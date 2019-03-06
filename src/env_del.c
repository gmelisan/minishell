/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:30:47 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/06 19:51:22 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	convert(char *name, t_string *p_name)
{
	*p_name = str_copy(name);
	if (!(*p_name).s)
		return (ERROR_MALLOC);
	if (str_addback(p_name, "=", 1) == NULL)
		return (ERROR_MALLOC);
	return (0);
}

static int	delete(t_string **ps_env, int i)
{
	int n;

	n = 0;
	while ((*ps_env)[n].s)
		n++;
	str_delete(*ps_env + i);
	while (++i < n)
		(*ps_env)[i - 1] = (*ps_env)[i];
	ft_bzero(*ps_env + i - 1, sizeof(t_string));
	return (0);
}

int			env_del(t_string **ps_env, char *name)
{
	int			i;
	t_string	s_name;

	i = 0;
	if (convert(name, &s_name))
		return (ERROR_MALLOC);
	while ((*ps_env)[i].s)
	{
		if (ft_strncmp((*ps_env)[i].s, s_name.s, s_name.len) == 0)
			delete(ps_env, i);
		i++;
	}
	str_delete(&s_name);
	return (0);
}
