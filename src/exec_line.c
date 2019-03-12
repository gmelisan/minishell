/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 07:21:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 20:17:07 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_line(t_string line, t_string **ps_env, int *exit_flag)
{
	int			ret;
	t_string	*s_argv;
	int			index;

	ret = 0;
	index = 0;
	while (*exit_flag != 1)
	{
		if ((ret = get_argv(line, &index, &s_argv, *ps_env)))
			return (ret);
		if (index == -1)
			break ;
		if (!s_argv)
			continue ;
		if (check_builtin(s_argv))
			ret = exec_builtin(s_argv, ps_env, exit_flag);
		else if ((ret = check_command(s_argv, *ps_env)) == 0)
			ret = exec_command_wrapper(s_argv, *ps_env);
		str_delarr(&s_argv);
		if (ret && !*exit_flag)
			print_error(ret);
	}
	return (ret);
}
