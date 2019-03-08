/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 07:21:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/08 19:26:37 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_empty(t_string line)
{
	int i;

	if (line.len == 0)
		return (1);
	i = 0;
	while (ft_isspace(str_get(line, i)))
		i++;
	if (!(str_get(line, i)))
		return (1);
	return (0);
}

int			exec_line(t_string line, t_string **ps_env, int *exit_flag)
{
	int			ret;
	t_string	*s_argv;

	if (is_empty(line))
		return (0);
	while (1)
	{
		if ((ret = get_argv(line, &s_argv)))
			return (ret);
		if (!s_argv[0].s)
			break ;
		if (check_builtin(s_argv))
			ret = exec_builtin(s_argv, ps_env, exit_flag);
		else if ((ret = check_command(s_argv, *ps_env)) == 0)
			ret = exec_command_wrapper(s_argv, *ps_env);
		str_delarr(&s_argv);
	}
	return (ret);
}
/*
int			exec_line(t_string line, t_string **ps_env, int *exit_flag)
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
	if (s_argv[0].s)
	{
		if (check_builtin(s_argv))
			ret = exec_builtin(s_argv, ps_env, exit_flag);
		else if ((ret = check_command(s_argv, *ps_env)) == 0)
		{
			if ((ret = prepare_exec_command(s_argv, *ps_env, &argv, &envp)))
				return (ret);
			ret = exec_command(argv, envp);
			clear(&argv, &envp, &s_argv);
			return (ret);
		}
	}
	str_delarr(&s_argv);
	return (ret);
}
*/
