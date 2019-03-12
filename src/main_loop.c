/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:51:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 19:28:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		sighandler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		show_prompt(g_fd, *g_env);
	}
}

int				main_loop(int fd, t_string **ps_env)
{
	t_string	line;
	int			ret;
	int			exit_flag;

	exit_flag = 0;
	g_env = ps_env;
	while (!exit_flag)
	{
		signal(SIGINT, sighandler);
		show_prompt(fd, *ps_env);
		if ((ret = get_input(fd, &line, &exit_flag)))
		{
			print_error(ret);
			break ;
		}
		if (exit_flag)
			ft_printf("\n");
		if ((ret = exec_line(line, ps_env, &exit_flag)) && !exit_flag)
			print_error(ret);
		str_delete(&line);
	}
	return (ret);
}
