/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 23:09:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/22 23:18:16 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		str_resize(t_string *str, size_t n)
{
	ft_realloc((void **)&str->s, str->len, n);
	str->len = n;
	return (n);
}
