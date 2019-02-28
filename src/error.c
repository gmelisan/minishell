/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:50:08 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/28 18:03:07 by gmelisan         ###   ########.fr       */
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
	else
		ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, "Unknown error");
}
n