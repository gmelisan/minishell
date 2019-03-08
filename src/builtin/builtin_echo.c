/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:50:23 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/07 17:28:05 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_echo(t_string *s_argv)
{
	int i;

	i = 1;
	if (ft_strequ(s_argv[1].s, "-n"))
		while (s_argv[++i].s)
			ft_printf(s_argv[i + 1].s ? "%s " : "%s", s_argv[i].s);
	else
	{
		while (s_argv[i].s)
		{
			ft_printf(s_argv[i + 1].s ? "%s " : "%s", s_argv[i].s);
			i++;
		}
		ft_printf("\n");
	}
	return (0);
}
