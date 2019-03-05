/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_exec_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:49:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 17:52:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int convert(t_string *s_argv, char ***p_argv)
{
	int		i;
	char	**argv;

	i = 0;
	while (s_argv[i].s)
		i++;
	argv = (char **)ft_memalloc(sizeof(*argv) * (i + 1));
	if (!argv)
		return (ERROR_MALLOC);
	i = 0;
	while (s_argv[i].s)
	{
		argv[i] = (char *)ft_memalloc(sizeof(**argv) * (s_argv[i].len + 1));
		if (!argv[i])
			return (ERROR_MALLOC);
		ft_memcpy(argv[i], s_argv[i].s, s_argv[i].len);
		i++;
	}
	*p_argv = argv;
	return (0);
}

int		prepare_exec_command(t_string *s_argv, t_string *s_env,
							 char ***p_argv, char ***p_envp)
{
	convert(s_argv, p_argv);
	convert(s_env, p_envp);
	return (0);
}
