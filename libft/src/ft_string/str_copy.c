/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:36:00 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/01 17:15:32 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string		str_copy(char *s)
{
	t_string str;

	str.s = NULL;
	str.len = 0;
	str.allocated = 0;
	if (!s)
		return (str);
	str = str_create(ft_strlen(s));
	ft_memcpy(str.s, s, str.len);
	return (str);
}
