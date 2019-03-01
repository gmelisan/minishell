/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_fixlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:28:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/01 15:11:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		str_fixlen(t_string *str)
{
	str->len = ft_strlen(str->s);
	str->allocated = str->len + 1;
	return (str->len);
}
