/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_concat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:50:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/22 22:45:00 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static t_string	str_vconcat(int n, va_list ap)
{
	t_string	res;
	char		*str;
	int			len;
	int			oldlen;

	oldlen = 0;
	res.s = NULL;
	while (--n >= 0)
	{
		str = va_arg(ap, char *);
		len = ft_strlen(str);
		ft_realloc((void **)&res.s, oldlen, oldlen + len + 1);
		ft_memcpy(res.s + oldlen, str, len);
		oldlen += len;
	}
	res.len = oldlen;
	return (res);
}

t_string		str_concat(int n, ...)
{
	va_list		ap;
	t_string	str;

	str.s = NULL;
	str.len = -1;
	if (n <= 0)
		return (str);
	va_start(ap, n);
	str = str_vconcat(n, ap);
	va_end(ap);
	return (str);
}
