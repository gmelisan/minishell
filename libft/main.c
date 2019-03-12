/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:08:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/11 01:13:20 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_string.h"
#include "ft_vector.h"

typedef struct	s_test
{
	int a;
	int b;
	char *c;
}				t_test;

void	del(void *elem)
{
	t_test *a;

	a = (t_test *)elem;
	ft_strdel(&a->c);
}

int		main(void)
{
	t_vector	vec;
	t_test		test;
	t_test		test2;
	t_test		test3;
	t_test		*p;

	vec = vec_create(0, sizeof(t_test));
	ft_printf("vec.v = %p, vec.len = %ld, vec.alloc = %ld, vec.size =%ld\n\n",
			  vec.v, vec.len, vec.alloc, vec.size);
	
	int i = 0;
	while (i < 8)
	{
		test.a = i;
		test.b = i * 2;
		test.c = ft_strdup("hey");
		vec_addback(&vec, (void *)&test);
		i++;
	}

	i = 0;
	while (vec_get(vec, i))
	{
		p = (t_test *)vec_get(vec, i);
		ft_printf("%d: a = %-5d, b = %-5d, c = %-10s\n", i,
				  p->a, p->b, p->c);
		i++;
	}
	vec_delete(&vec, del);
	return (0);
}
