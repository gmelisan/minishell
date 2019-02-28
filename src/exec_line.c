/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 07:21:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/28 18:03:55 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print(char **a)
{
	int i;

	i = 0;
	while (a[i])
	{
		ft_printf("[%s]\n", a[i]);
		i++;
	}
}

int		exec_line(t_string line)
{
	int		ret;
	char	**argv;

	while ((ret = get_argv(line, &argv)))
	{
		if (ret)
			error(ret);
		print(argv);
		ft_strarrdel(&argv);
	}
	return (0);
}
