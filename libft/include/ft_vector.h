/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 02:11:48 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/08 02:41:36 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"

# define VEC_DEFBUFSIZE		32

typedef struct	s_vector
{
	void		*v;
	size_t		len;
	size_t		alloc;
	size_t		size;
}				t_vector;

t_vector		vec_create(size_t len);
t_vector		vec_duplicate(t_vector vec);
t_vector		vec_delete(t_vector *vec);
void			*vec_get(t_vector vec, int i);
t_vector		*vec_addback(t_vector *vec, void *new);
t_vector		*vec_addfront(t_vector *vec, void *new);

#endif