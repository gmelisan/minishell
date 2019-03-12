/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:36:37 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 07:14:21 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_setenv(t_string *s_argv, t_string **ps_env)
{
	int			i;
	int			ret;

	if (!s_argv[1].s)
		return (builtin_env(*ps_env));
	if (ft_isdigit(str_get(s_argv[1], 0)))
		return (ERROR_SETENVDIGIT);
	i = 0;
	while (str_get(s_argv[1], i))
	{
		if (!ft_isalnum(str_get(s_argv[1], i)))
			return (ERROR_SETENVALNUM);
		i++;
	}
	if ((ret = env_setval(ps_env, s_argv[1].s, s_argv[2])))
		return (ret);
	return (0);
}
