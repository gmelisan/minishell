/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:08:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/04 13:29:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		isdelim(int c)
{
	if (ft_isspace(c))
		return (1);
	if (c == ';')
		return (1);
	return (0);
}

int		main(void)
{
	t_string str;
	t_string *tab;

	str = str_copy("hello	dark;ness		 my    old friend    ");
	tab = str_split(str, isdelim);
	int i = 0;
	while (tab[i].s)
	{
		ft_printf("%s\n", tab[i].s);
		str_delete(&tab[i]);
		i++;
	}
	free(tab);
	str_delete(&str);
	str = str_copy("test");
	str_addfront(&str, "loooooooooooooooooooooooooooooooooong prefix....................", 64);
	ft_printf("---\n%s\nalloc = %d, len = %d", str.s, str.allocated, str.len);
	str_delete(&str);
	return (0);
}
