/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:38:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/01 14:06:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static int	calc_len(t_string line, int i, int end) */
/* { */
/* 	int len; */

/* 	len = 0; */
/* 	while (i < end) */
/* 	{ */
/* 		while (ft_isspace(str_get(line, i))) */
/* 			i++; */
/* 		if (str_get(line, i)) */
/* 			len++; */
/* 		while (str_get(line, i) && !ft_isspace(str_get(line, i))) */
/* 			i++; */
/* 	} */
/* } */

/* static int	fill_argv(t_string line, char ***p_argv, int i, int end) */
/* { */
/* 	int len; */

/* 	len = calc_len(line, i, end); */
/* 	while (i < end) */
/* 	{ */
		
/* 		i++; */
/* 	} */
/* } */

/* int		get_argv(t_string line, char ***p_argv) */
/* { */
/* 	static int	i = 0; */
/* 	int			end; */

/* 	*p_argv = NULL; */
/* 	end = i; */
/* 	while (str_get(line, i) && str_get(line, i) != ';') */
/* 		end++; */
/* 	if (end == i) */
/* 		return (0); */
	
/* 	end++; */
/* 	return (0); */
/* } */

int		get_argv(t_string line, char ***p_argv)
{
	*p_argv = ft_strsplit(line.s, ' ');
	if (!*p_argv)
		return (ERROR_MALLOC);
	return (0);
}
