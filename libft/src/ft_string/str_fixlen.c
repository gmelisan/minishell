/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_fixlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:28:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/04 14:31:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		str_fixlen(t_string *str)
{
	str->len = (str->s ? ft_strlen(str->s) : 0);
	str->allocated = (str->s ? str->len + 1 : 0);
	return (str->len);
}
