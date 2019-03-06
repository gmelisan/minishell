/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:33:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/06 14:56:30 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_env(t_string *s_env)
{
	int i;

	i = 0;
	while (s_env[i].s)
	{
		ft_printf("%s\n", s_env[i].s);
		i++;
	}
	return (0);
}
