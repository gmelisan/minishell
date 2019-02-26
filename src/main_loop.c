/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:51:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/26 06:56:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_prompt()
{
	char	buf[PATH_MAX];

	ft_bzero(buf, PATH_MAX);
	if (1 || getcwd(buf, PATH_MAX - 1) == NULL)
		ft_printf("$> ");
	else
		ft_printf("%s $> ", buf);
}

void	check_tokens(t_list *tok)
{
	t_token *token;

	token = (t_token *)tok->content;
	ft_printf("[%s], type = ", token->s);
	switch (token->type)
	{
	case WORD:
		ft_printf("WORD");
		break;
	case SEMICOLON:
		ft_printf("SEMICOLON");
		break;
	case NONE:
		ft_printf("NONE");
		break;
	}
	ft_printf("\n");
}

int		main_loop(int fd)
{
	char	*line;
	t_list	*toklist;
	int		ret;

	while (1)
	{
		if (fd == STDIN)
			show_prompt();
		ret = get_next_line(fd, &line);
		if (ret == -1)
			error("Error while reading input");
		else if (ret == 0)
			break;
		toklist = tokenize(line);
		//ft_lstiter(toklist, check_tokens);
		exec_line(toklist);
		ft_strdel(&line);
		ft_lstdel(&toklist, deltok);
	}
	return (0);
}
