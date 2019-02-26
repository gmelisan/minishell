/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:07:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/25 08:32:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define SHELL_NAME		"minishell"

enum e_toktype		{NONE, COMMAND, SEMICOLON};

typedef struct		s_token
{
	enum e_toktype	type;
	char			**argv;
}					t_token;

void				error_nofile(char *file);
void				error(char *str);
void				error_syntax(char *str);
int					main_loop(int fd);
t_token				*parse_line(char *line);
int					exec_line(t_token *tokens);

#endif
