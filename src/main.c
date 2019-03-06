/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 03:08:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/06 21:18:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_string	*s_env;
	int			ret;

	fd = STDIN;
	if (argc > 1)
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			error_nofile(argv[1]);
	if ((ret = get_env(&s_env)))
		print_error(ret);
	else
		ret = main_loop(fd, &s_env);
	str_delarr(&s_env);
	return (ret);
}
