/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:33:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/28 15:59:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string		str_create(size_t len)
{
	t_string str;

	str.s = ft_strnew(len);
	if (!str.s)
		str.len = -1;
	else
		str.len = len;
	return (str);
}
