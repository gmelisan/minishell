/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:08:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/01 18:10:06 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		main(void)
{
	t_string str;
	t_string *tab;

	str = str_copy("hello	darkness		 my    old friend    ");
	tab = str_split(str, ft_isspace);
	int i = 0;
	while (tab[i].s)
	{
		ft_printf("%s\n", tab[i].s);
		str_delete(&tab[i]);
		i++;
	}
	free(tab);
	str_delete(&str);
	return (0);
}
