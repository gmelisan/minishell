/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 07:19:26 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/25 09:23:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		count_tokens(char *line)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (ft_isspace(line[i]))
		i++;
	while (line[i])
	{
		n++;
		while (line[i] && !ft_isspace(line[i]))
			i++;
		while (ft_isspace(line[i]))
			i++;
	}
	return (n);
}

static t_token	*tokenize(char *line)
{
	t_token	*tokens;
	int		n;

	n = count_tokens(line);
	tokens = ft_memalloc(n + 1);

	
}

t_token			*parse_line(char *line)
{
	t_token	*tokens;

	tokens = tokenize(line);
}
