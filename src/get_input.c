/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 05:10:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 07:45:53 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_input(int fd, t_string *line, int *exit_flag)
{
	int		ret;
	char	c;

	str_zero(line);
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == -1)
			return (ERROR_READ);
		if (ret == 0)
			*exit_flag = 1;
		if (ret == 0 || c == '\n')
			return (0);
		if (str_addback(line, &c, 1) == NULL)
			return (ERROR_MALLOC);
	}
	return (0);
}
