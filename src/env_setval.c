/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:30:07 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/06 21:23:53 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	replace(t_string *env_i, char *name, t_string value)
{
	str_delete(env_i);
	*env_i = str_copy(name);
	if (!(*env_i).s)
		return (ERROR_MALLOC);
	if (str_addback(env_i, "=", 1) == NULL)
		return (ERROR_MALLOC);
	if (str_addback(env_i, value.s, value.len) == NULL)
		return (ERROR_MALLOC);
	return (0);
}

static int	add(t_string **ps_env, char *name, t_string value)
{
	int i;

	i = 0;
	while ((*ps_env)[i].s)
		i++;
	if (ft_realloc((void **)ps_env,
			sizeof(t_string) * i, sizeof(t_string) * (i + 2)) == NULL)
		return (ERROR_MALLOC);
	(*ps_env)[i] = str_copy(name);
	if (!(*ps_env)[i].s)
		return (ERROR_MALLOC);
	if (str_addback(*ps_env + i, "=", 1) == NULL)
		return (ERROR_MALLOC);
	if (!value.s)
		return (0);
	if (str_addback(*ps_env + i, value.s, value.len) == NULL)
		return (ERROR_MALLOC);
	return (0);
}

static int	convert(char *name, t_string *p_name)
{
	*p_name = str_copy(name);
	if (!(*p_name).s)
		return (ERROR_MALLOC);
	if (str_addback(p_name, "=", 1) == NULL)
		return (ERROR_MALLOC);
	return (0);
}

int			env_setval(t_string **ps_env, char *name, t_string value)
{
	int			i;
	int			ret;
	t_string	s_name;

	if ((ret = convert(name, &s_name)))
		return (ret);
	ret = -1;
	i = 0;
	while ((*ps_env)[i].s)
	{
		if (ft_strncmp((*ps_env)[i].s, s_name.s, s_name.len) == 0)
		{
			if ((ret = replace(*ps_env + i, name, value)))
				return (ret);
			break ;
		}
		i++;
	}
	str_delete(&s_name);
	return (ret == -1 ? add(ps_env, name, value) : 0);
}
