/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:26:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 05:51:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count(t_string str)
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

int			split_path(t_string str, t_string **pathes)
{
	int		i;
	int		j;

	if (!(*pathes = (t_string *)ft_memalloc(
									sizeof(t_string) * (count(str) + 1))))
		return (ERROR_MALLOC);
	i = 0;
	j = 0;
	while (str_get(str, i))
	{
		(*pathes)[j] = str_create(0);
		while (str_get(str, i) && str_get(str, i) != ':')
		{
			if (!str_addback(*pathes + j, str.s + i, 1))
				return (ERROR_MALLOC);
			i++;
		}
		j++;
		i++;
	}
	if ((str_get(str, i - 1) == ':') || (str.s && str.len == 0))
		(*pathes)[j] = str_create(0);
	return (0);
}
