/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:38:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/08 19:36:43 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
static int increase(t_string **ps_argv, int *size)
{
	int		newsize;

	if (*ps_argv == NULL)
		*ps_argv = (t_string *)ft_memalloc(sizeof(t_string) * size);
	newsize = *size ? *size * 2 : 16;
	if (ft_realloc((void **)ps_argv, sizeof(t_string) * (*size),
				   sizeof(t_string) * newsize) == NULL)
		return (ERROR_MALLOC);
	*size = newsize;
	return (0);
}
*/
int			get_argv(t_string line, t_string **ps_argv)
{
	t_string	*s_argv;
	size_t		size;
	int			i;
	int			j;

	size = 16;
	s_argv = (t_string *)ft_memalloc(sizeof(t_string) * size);
	if (!s_argv)
		return (ERROR_MALLOC);
	i = 0;
	while (ft_isspace(str_get(line, i)))
		i++;
	j = 0;
	while (str_get(line, i))
	{
		if (str_get(line, i) == '"')
		j++;
	}
	return (0);
}

/*
int			get_argv(t_string line, t_string **ps_argv)
{
	t_string	*s_argv;

	s_argv = str_split(line, ft_isspace);
	if (!s_argv)
		return (ERROR_MALLOC);
	*ps_argv = s_argv;
	return (0);
}
*/
