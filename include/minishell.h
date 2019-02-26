/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:07:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/26 06:48:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://brennan.io/2015/01/16/write-a-shell-in-c/

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define PATH_MAX		256
# define SHELL_NAME		"minishell"

enum e_toktype
{
	NONE,
	WORD,
	SEMICOLON
};

typedef struct		s_token
{
	enum e_toktype	type;
	char			*s;
}					t_token;

typedef	struct		s_command
{
	char			**argv;
	t_token			next_token;
}					t_command;

void				error_nofile(char *file);
void				error(char *str);
void				error_syntax(char *str);
int					main_loop(int fd);
t_list				*tokenize(char *line);
void				deltok(void *token, size_t size);
t_command			*get_command(t_list **toklist);
int					exec_line(t_list *toklist);

#endif
