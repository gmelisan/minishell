/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:07:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/01 14:06:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://brennan.io/2015/01/16/write-a-shell-in-c/

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_string.h"

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define ERROR_MALLOC	1
# define ERROR_GNL		2
# define ERROR_BADSYN	3

# define SHELL_NAME		"minishell"

void	error_nofile(char *file);
void	print_error(int	e);
void	error_syntax(char *str);
int		main_loop(int fd);
int		exec_line(t_string line);
int		get_argv(t_string line, char ***p_argv);

#endif
