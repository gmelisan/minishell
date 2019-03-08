/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:07:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/07 19:09:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static t_string	*create(t_string *str, char *s, size_t size)
{
	*str = str_create(size);
	if (!str->allocated)
		return (NULL);
	ft_memcpy(str->s, s, size);
	return (str);
}

t_string		*str_addback(t_string *str, char *s, size_t size)
{
	size_t	newalloc;

	if (!str || !s || !size)
		return (str);
	if (!str->allocated)
		return (create(str, s, size));
	if (str->len + size >= str->allocated)
	{
		newalloc = str->allocated * 2;
		while (str->len + size >= newalloc)
			newalloc *= 2;
		if (!ft_realloc((void **)&str->s, str->len, newalloc))
			return (NULL);
		str->allocated = newalloc;
	}
	ft_memcpy(str->s + str->len, s, size);
	str->len += size;
	return (str);
}
