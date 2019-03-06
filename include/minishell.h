/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:07:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/06 20:38:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://brennan.io/2015/01/16/write-a-shell-in-c/
*/

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_string.h"

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define CWD_BUFSIZE	1024

# define SHELL_NAME		"minishell"

enum	e_err
{
	ERROR_MALLOC = 10,
	ERROR_GNL,
	ERROR_BADSYN,
	ERROR_EXEC,
	ERROR_FORK,
	ERROR_WAIT,
	ERROR_CD,
	ERROR_PWD,
	ERROR_ENV,
	ERROR_NODIR,
	ERROR_CDFILE,
	ERROR_SETENVDIGIT,
	ERROR_SETENVALNUM
};

void	error_nofile(char *file);
void	print_error(int	e);
void	error_syntax(char *str);
int		main_loop(int fd, t_string **ps_env);
int		exec_line(t_string line, t_string **ps_env, int *exit_flag);

int		get_argv(t_string line, t_string **ps_argv);
int		check_builtin(t_string *s_argv);
int		exec_builtin(t_string *s_argv, t_string **ps_env, int *exit_flag);

int		prepare_exec_command(t_string *s_argv, t_string *s_env,
									char ***p_argv, char ***p_envp);
int		check_command(t_string *s_argv, t_string *s_env);
int		exec_command(char **argv, char **envp);

int		builtin_cd(t_string *s_argv, t_string **ps_env);
int		builtin_exit(t_string *s_argv);
int		builtin_pwd(void);
int		builtin_env(t_string *s_env);
int		builtin_setenv(t_string *s_argv, t_string **ps_env);
int		builtin_unsetenv(t_string *s_argv, t_string **ps_env);

int		get_env(t_string **ps_env);
int		env_getval(t_string *s_env, char *name, t_string *value);
int		env_setval(t_string **ps_env, char *name, t_string value);
int		env_del(t_string **ps_env, char *name);

#endif
