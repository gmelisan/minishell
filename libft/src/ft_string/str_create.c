/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:33:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/08 18:25:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string		str_create(size_t len)
{
	t_string str;

	str.alloc = STR_DEFBUFSIZE;
	while (str.alloc <= len)
		str.alloc *= 2;
	str.s = ft_memalloc(str.alloc);
	if (!str.s)
	{
		str.len = 0;
		str.alloc = 0;
	}
	else
		str.len = len;
	return (str);
}
