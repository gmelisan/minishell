/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 07:21:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/26 07:05:16 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_command(t_command c)
{
	int i;

	i = 0;
	while (c.argv[i])
	{
		ft_printf("argv[%d] = %s\n", i, c.argv[i]);
		i++;
	}
	ft_printf("\n");
}

int		exec_line(t_list *toklist)
{
	t_command *command;

	while (((t_token *)toklist->content)->type)
	{
		command = get_command(&toklist);
		if (!command)
			error("Parsing error");
		check_command(*command);
	}
	return (0);
}
