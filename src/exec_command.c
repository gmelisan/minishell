/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:20:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/04 16:17:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_command(char **argv, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
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
