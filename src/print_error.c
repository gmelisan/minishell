/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:31:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/06 21:22:42 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			error_nofile(char *file)
{
	ft_fdprintf(STDERR, "%s: Cannot open '%s'\n", SHELL_NAME, file);
	exit(1);
}

static void		print_error2(int e)
{
	if (e == ERROR_CD)
		ft_fdprintf(STDERR, "%s\n", "Changing directory error");
	else if (e == ERROR_NODIR)
		ft_fdprintf(STDERR, "%s\n", "No such file or directory");
	else if (e == ERROR_CDFILE)
		ft_fdprintf(STDERR, "%s\n", "Not a directory");
	else if (e == ERROR_SETENVDIGIT)
		ft_fdprintf(STDERR, "setenv: %s\n",
					"Variable name must begin with a letter");
	else if (e == ERROR_SETENVALNUM)
		ft_fdprintf(STDERR, "setenv: %s\n",
					"Variable name must contain alphanumeric characters");
	else
		ft_fdprintf(STDERR, "%s: Unknown error, code = %d\n", SHELL_NAME, e);
}

void			print_error(int e)
{
	if (!e)
		return ;
	if (e == ERROR_MALLOC)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Allocating memory error");
	else if (e == ERROR_GNL)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Input reading errror");
	else if (e == ERROR_BADSYN)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Syntax error");
	else if (e == ERROR_EXEC)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Executing error");
	else if (e == ERROR_FORK)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Forking error");
	else if (e == ERROR_WAIT)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Waiting error");
	else if (e == ERROR_PWD)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME,
					"Error while printing working directory");
	else
		print_error2(e);
}
