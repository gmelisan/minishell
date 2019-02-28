/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:51:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/28 18:35:58 by gmelisan         ###   ########.fr       */
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
		ret = get_next_line(fd, &line.s);
		if (ret == -1)
			error(ERROR_GNL);
		else if (ret == 0)
			break;
		str_fixlen(&line);
		exec_line(line);
		str_delete(&line);
	}
	return (0);
}
