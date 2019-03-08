/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:55:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/07 21:57:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtin(t_string *s_argv, t_string **ps_env, int *exit_flag)
{
	*exit_flag = 0;
	if (ft_strequ(s_argv[0].s, "exit"))
	{
		*exit_flag = 1;
		return (builtin_exit(s_argv));
	}
	else if (ft_strequ(s_argv[0].s, "cd"))
		return (builtin_cd(s_argv, ps_env));
	else if (ft_strequ(s_argv[0].s, "pwd"))
		return (builtin_pwd());
	else if (ft_strequ(s_argv[0].s, "env"))
		return (builtin_env(*ps_env));
	else if (ft_strequ(s_argv[0].s, "setenv"))
		return (builtin_setenv(s_argv, ps_env));
	else if (ft_strequ(s_argv[0].s, "unsetenv"))
		return (builtin_unsetenv(s_argv, ps_env));
	else if (ft_strequ(s_argv[0].s, "echo"))
		return (builtin_echo(s_argv));
	else if (ft_strequ(s_argv[0].s, "help"))
		return (builtin_help());
	return (0);
}
