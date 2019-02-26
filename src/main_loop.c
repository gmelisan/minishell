/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 06:51:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/25 08:36:48 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main_loop(int fd)
{
	char	*line;
	t_token	*tokens;

	while (1)
	{
		if (fd == STDIN)
			ft_printf("$> ");
		if (get_next_line(fd, &line) == -1)
			error("Error while reading input");
		tokens = parse_line(line);
		exec_line(tokens);
		ft_strdel(&line);
		ft_strarrdel(&parsed_line);
	}
	return (0);
}
