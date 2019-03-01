/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:33:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/01 15:45:06 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string		str_create(size_t len)
{
	t_string str;

	str.allocated = STR_DEFBUFSIZE;
	while (str.allocated <= len)
		str.allocated *= 2;
	str.s = ft_memalloc(str.allocated);
	if (!str.s)
	{
		str.len = 0;
		str.allocated = 0;
	}
	else
		str.len = len;
	return (str);
}
