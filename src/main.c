/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 03:08:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/25 06:50:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv)
{
	int		fd;

	fd = STDIN;
	if (argc > 1)
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			error_nofile(argv[1]);
	return (main_loop(fd));
}
