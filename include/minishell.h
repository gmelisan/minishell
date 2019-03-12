/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:07:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 09:13:30 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://brennan.io/2015/01/16/write-a-shell-in-c/
*/

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_string.h"
# include "ft_vector.h"

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define CWD_BUFSIZE	1024

# define SHELL_NAME		"minishell"

enum	e_err
{
	ERROR_MALLOC = 42,
	ERROR_READ,
	ERROR_BADQUOTE,
	ERROR_EXEC,
	ERROR_FORK,
	ERROR_WAIT,
	ERROR_CHDIR,
	ERROR_GETCWD,
	ERROR_NOSUCHFOD,
	ERROR_CDFILE,
	ERROR_NOXRIGHT,
	ERROR_NOCOMMAND,
	ERROR_CMDDIR,
	ERROR_SETENVDIGIT,
	ERROR_SETENVALNUM
};

void	error_nofile(char *file);
void	print_error(int	e);
void	show_prompt(int fd, t_string *s_env);
int		get_input(int fd, t_string *line, int *exit_flag);
int		main_loop(int fd, t_string **ps_env);
int		exec_line(t_string line, t_string **ps_env, int *exit_flag);

int		get_argv(t_string line, int *i, t_string **ps_argv, t_string *s_env);
int		check_builtin(t_string *s_argv);
int		exec_builtin(t_string *s_argv, t_string **ps_env, int *exit_flag);

int		check_command(t_string *s_argv, t_string *s_env);
int		exec_command_wrapper(t_string *s_argv, t_string *s_env);

int		builtin_cd(t_string *s_argv, t_string **ps_env);
int		builtin_exit(t_string *s_argv);
int		builtin_pwd(void);
int		builtin_env(t_string *s_env);
int		builtin_setenv(t_string *s_argv, t_string **ps_env);
int		builtin_unsetenv(t_string *s_argv, t_string **ps_env);
int		builtin_echo(t_string *s_argv);
int		builtin_help(void);

int		get_env(t_string **ps_env);
int		env_getval(t_string *s_env, char *name, t_string *value);
int		env_setval(t_string **ps_env, char *name, t_string value);
int		env_del(t_string **ps_env, char *name);

int		split_path(t_string str, t_string **pathes);
int		is_dir(struct stat st);

int		is_endsymbol(int c);
int		handle_tilda(t_string line, int *i, t_string *word, t_string *s_env);
int		handle_dquote(int *i, int dquote);
int		handle_dollar(t_string line, int *i, t_string *word, t_string *s_env);
int		handle_backslash(t_string line, int *i, t_string *word);
int		handle_common(t_string line, int *i, t_string *word);

int			g_fd;
t_string	**g_env;

#endif

