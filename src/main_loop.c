/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:51:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 17:57:22 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		show_prompt(int fd)
{
	if (fd == STDIN)
		ft_printf("{red}$>{eoc} ");
}

int				main_loop(int fd, t_string *s_env)
{
	t_string	line;
	int			ret;
	int			exit_flag;

	exit_flag = 0;
	while (!exit_flag)
	{
		show_prompt(fd);
		if ((ret = get_next_line(fd, &line.s)) == -1)
		{
			print_error(ERROR_GNL);
			continue ;
		}
		else if (ret == 0)
		{
			ft_printf("\n");
			break;
		}
		str_fixlen(&line);
		if ((ret = exec_line(line, s_env, &exit_flag)) != 0 && !exit_flag)
			print_error(ret);
		str_delete(&line);
	}
	return (ret);
}
