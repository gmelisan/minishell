/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:31:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/04 15:44:30 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_nofile(char *file)
{
	ft_fdprintf(STDERR, "%s: Cannot open '%s'\n", SHELL_NAME, file);
	exit(1);
}

void	print_error(int e)
{
	if (!e)
		return ;
	if (e == ERROR_MALLOC)
		ft_fdprintf(STDERR, "%s: %s\n",	SHELL_NAME,
										"Error while allocating memory");
	else if (e == ERROR_GNL)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Input reading error");
	else if (e == ERROR_BADSYN)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Syntax error");
	else if (e == ERROR_EXEC)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Executing error");
	else if (e == ERROR_FORK)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Forking error");
	else if (e == ERROR_WAIT)
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Waiting error");
	else
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Unknown error");
}
