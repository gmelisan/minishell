/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:18:59 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/28 18:35:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		tokenize(t_string line, t_list **toklist)
{
	int		i;
	t_token tok;

	while (str_get(line, i))
	{
		if (ft_isalnum(str_get(line, i)))
			addword(
		i++;
	}
}

int		parse_line(t_string line, t_list cmdlist)
{
	t_list *toklist;

	
}
