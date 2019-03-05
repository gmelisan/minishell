/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:55:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 20:53:44 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_getval(t_string *s_env, char *name, t_string *value)
{
	int			i;
	t_string	s_name;
	char		*startval;

	startval = NULL;
	s_name = str_copy(name);
	if (!s_name.s || s_name.len == 0)
		return (ERROR_ENV);
	str_addback(&s_name, "=", 1);
	i = 0;
	while (s_env[i].s)
	{
		if (ft_strncmp(s_name.s, s_env[i].s, s_name.len) == 0)
			startval = &s_env[i].s[s_name.len];
		i++;
	}
	if (startval)
	{
		*value = str_copy(startval);
		str_delete(&s_name);
		return ((*value).s ? 0 : ERROR_ENV);
	}
	return (0);
}
