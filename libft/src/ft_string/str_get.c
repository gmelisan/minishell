/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:43:34 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/01 15:57:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		str_get(t_string str, int i)
{
	if (i < 0)
		return (0);
	if ((size_t)i < str.allocated)
		return (str.s[i]);
	return (0);
}
