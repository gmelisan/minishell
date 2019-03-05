/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:51:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/04 16:07:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main_loop(int fd)
{
	t_string	line;
	int			ret;

	while (1)
	{
		if (fd == STDIN)
			ft_printf("$> ");
		if ((ret = get_next_line(fd, &line.s)) == -1)
		{
			print_error(ERROR_GNL);
			continue ;
		}
		else if (ret == 0)
			break;
		str_fixlen(&line);
		if ((ret = exec_line(line)) != 0)
			print_error(ret);
		str_delete(&line);
	}
	if (fd == STDIN)
		ft_printf("\n");
	return (0);
}
