/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 07:21:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 21:00:27 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear(char ***p_argv, char ***p_envp, t_string **ps_argv)
{
	ft_strarrdel(p_argv);
	ft_strarrdel(p_envp);
	str_delarr(ps_argv);
}

int		exec_line(t_string line, t_string *s_env, int *exit_flag)
{
	int			ret;
	t_string	*s_argv;
	char		**argv;
	char		**envp;

	argv = NULL;
	if (line.len == 0)
		return (0);
	if ((ret = get_argv(line, &s_argv)))
		return (ret);
	if (check_builtin(s_argv))
		ret = exec_builtin(s_argv, s_env, exit_flag);
	else if (check_command(s_argv, s_env))
	{
		if ((ret = prepare_exec_command(s_argv, s_env, &argv, &envp)))
			return (ret);
		ret = exec_command(argv, envp);
		clear(&argv, &envp, &s_argv);
		return (ret);
	}
	str_delarr(&s_argv);
	return (ret);
}
