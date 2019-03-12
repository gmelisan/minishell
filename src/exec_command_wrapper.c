/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_wrapper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:16:03 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 06:42:21 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
	}
}

static int	exec_command(char **argv, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	signal(SIGINT, sighandler);
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			return (ERROR_EXEC);
	}
	else if (pid < 0)
		return (ERROR_FORK);
	else
	{
		while (1)
		{
			if (waitpid(pid, &status, WUNTRACED) == -1)
				return (ERROR_WAIT);
			if (WIFEXITED(status) || WIFSIGNALED(status))
				break ;
		}
	}
	return (0);
}

static int	convert(t_string *s_argv, char ***p_argv)
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

int			exec_command_wrapper(t_string *s_argv, t_string *s_env)
{
	int		ret;
	char	**argv;
	char	**envp;

	if ((ret = convert(s_argv, &argv)))
		return (ret);
	if ((ret = convert(s_env, &envp)))
		return (ret);
	ret = exec_command(argv, envp);
	ft_strarrdel(&argv);
	ft_strarrdel(&envp);
	return (ret);
}
