/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:23:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/28 18:35:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "libft.h"

typedef struct	s_string
{
	char		*s;
	int			len;
}				t_string;

t_string		str_create(size_t len);
t_string		str_duplicate(t_string str);
t_string		str_copy(char *s);
t_string		str_concat(int n, ...);
t_string		str_substring(t_string str, int start, int len);

void			str_delete(t_string *str);

int				str_fixlen(t_string *str);
char			str_get(t_string str, int i);
int				str_compare(t_string str1, t_string str2);
int				str_resize(t_string *str, size_t n);

#endif