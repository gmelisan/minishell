/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:40:30 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/01 15:07:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void		str_delete(t_string *str)
{
	if (str->allocated > 0)
		ft_strdel(&str->s);
	str->len = 0;
	str->allocated = 0;
}
