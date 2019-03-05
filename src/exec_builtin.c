/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:55:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 19:35:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtin(t_string *s_argv, t_string *s_env, int *exit_flag)
{
	*exit_flag = 0;
	if (ft_strequ(s_argv[0].s, "exit"))
	{
		*exit_flag = 1;
		return (builtin_exit(s_argv));
	}
	else if (ft_strequ(s_argv[0].s, "cd"))
		return (builtin_cd(s_argv, s_env));
	else if (ft_strequ(s_argv[0].s, "pwd"))
		return (builtin_pwd());
	else if (ft_strequ(s_argv[0].s, "env"))
		return (builtin_env(s_env));
	else if (ft_strequ(s_argv[0].s, "setenv"))
		return (builtin_setenv(s_argv, s_env));
	else if (ft_strequ(s_argv[0].s, "unsetenv"))
		return (builtin_unsetenv(s_argv, s_env));
	return (0);
}
