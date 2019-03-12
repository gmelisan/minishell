/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 00:08:07 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/11 01:12:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vec_addback(t_vector *vec, void *new)
{
	size_t newbytelen;
	size_t newalloc;

	if (!vec || !new)
		return (vec);
	newbytelen = (vec->len + 1) * vec->size;
	if (newbytelen >= vec->alloc)
	{
		newalloc = vec->alloc * 2;
		while (newbytelen >= newalloc)
			newalloc *= 2;
		if (!ft_realloc((void **)&vec->v, (vec->len * vec->size), newalloc))
			return (NULL);
		vec->alloc = newalloc;
	}
	ft_memcpy(vec->v + (vec->len * vec->size), new, vec->size);
	vec->len++;
	return (vec);
}
