/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:55:11 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 17:25:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_env(t_string **ps_env)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
		i++;
	*ps_env = ft_memalloc(sizeof(t_string) * (i + 1));
	if (!*ps_env)
		return (ERROR_MALLOC);
	i = 0;
	while (environ[i])
	{
		(*ps_env)[i] = str_copy(environ[i]);
		if (!(*ps_env)[i].s)
			return (ERROR_MALLOC);
		i++;
	}
	return (0);
}
