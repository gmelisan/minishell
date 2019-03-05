/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:31:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 21:18:17 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_nofile(char *file)
{
	ft_fdprintf(STDERR, "%s: Cannot open '%s'\n", SHELL_NAME, file);
	exit(1);
}

t_string	create_message(int e)
{
	t_string str;

	if (e == ERROR_MALLOC)
		str = str_copy("Error while allocating memory");
	else if (e == ERROR_GNL)
		str = str_copy("Input reading error");
	else if (e == ERROR_BADSYN)
		str = str_copy("Syntax error");
	else if (e == ERROR_EXEC)
		str = str_copy("Executing error");
	else if (e == ERROR_FORK)
		str = str_copy("Forking error");
	else if (e == ERROR_WAIT)
		str = str_copy("Waiting error");
	else if (e == ERROR_CD)
		str = str_copy("Changing directory error");
	else if (e == ERROR_PWD)
		str = str_copy("Error while printing working directory");
	else if (e == ERROR_NODIR)
		str = str_copy("No such file or directory");
	else if (e == ERROR_CDFILE)
		str = str_copy("Not a directory");
	else
		str = str_copy("Unknown error");
	return (str);
}

void	print_error(int e)
{
	t_string str;

	if (!e)
		return ;
	str = create_message(e);
	ft_fdprintf(STDERR, "%s: %s\n", SHELL_NAME, str.s);
	str_delete(&str);
}
