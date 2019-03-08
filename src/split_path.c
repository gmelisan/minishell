/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:26:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/07 21:53:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			count(t_string str)
{
	int i;
	int n;

	i = 0;
	n = 1;
	while (str_get(str, i))
	{
		if (str_get(str, i) == ':')
			n++;
		i++;
	}
	return (n);
}

t_string	*split_path(t_string str)
{
	t_string	*res;
	int			i;
	int			j;

	if (!(res = (t_string *)ft_memalloc(sizeof(*res) * (count(str) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str_get(str, i))
	{
		res[j] = str_create(0);
		while (str_get(str, i) && str_get(str, i) != ':')
		{
			if (!str_addback(&res[j], str.s + i, 1))
				return (NULL);
			i++;
		}
		j++;
		i++;
	}
	if ((str_get(str, i - 1) == ':') || (str.s && str.len == 0))
		res[j] = str_create(0);
	return (res);
}
