/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:52:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/06 19:50:54 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_unsetenv(t_string *s_argv, t_string **ps_env)
{
	int i;

	i = 0;
	while (s_argv[++i].s)
		env_del(ps_env, s_argv[i].s);
	return (0);
}
