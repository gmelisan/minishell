/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 03:25:57 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/26 07:04:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_type(t_token *token)
{
	if (ft_strequ(token->s, ";"))
		token->type = SEMICOLON;
	else
		token->type = WORD;
}

t_list		*tokenize(char *line)
{
	t_list	*toklist;
	t_token	token;
	int		i;
	int		j;

	toklist = NULL;
	i = 0;	
	while (ft_isspace(line[i]))
		i++;
	while (line[i])
	{
		j = i;
		while (line[i] && !ft_isspace(line[i]))
			i++;
		token.s = ft_strsub(line, j, i - j);
		set_type(&token);
		while (ft_isspace(line[i]))
			i++;
		ft_lstaddback(&toklist, ft_lstnew(&token, sizeof(token)));
	}
	token.s = NULL;
	token.type = NONE;
	ft_lstaddback(&toklist, ft_lstnew(&token, sizeof(token)));
	return (toklist);
}

void	deltok(void	*token, size_t size)
{
	ft_strdel(&((t_token *)token)->s);
	if (size)
		return ;
}
