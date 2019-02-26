/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 06:44:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/26 06:56:18 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_argc(t_list *toklist)
{
	int argc;

	argc = 0;
	while (toklist && ((t_token *)toklist->content)->type == WORD)
	{
		argc++;
		toklist = toklist->next;
	}
	return argc;
}

t_command	*get_command(t_list **toklist)
{
	t_command		*command;
	int				argc;
	int				i;

	if (((t_token *)(*toklist)->content)->type != WORD)
		return (NULL);
	argc = count_argc(*toklist);
	command = ft_memalloc(sizeof(*command));
	command->argv = ft_memalloc(sizeof(char *) * (argc + 1));
	i = 0;
	while (*toklist && ((t_token *)(*toklist)->content)->type == WORD)
	{
		command->argv[i++] = ft_strdup(((t_token *)(*toklist)->content)->s);
		*toklist = (*toklist)->next;
	}
	command->next_token = *(t_token *)(*toklist)->content;
	*toklist = (*toklist)->next;
	return (command);
}
