/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:55:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/06 20:47:25 by gmelisan         ###   ########.fr       */
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

int			env_getval(t_string *s_env, char *name, t_string *value)
{
	int			i;
	char		*startval;
	t_string	s_name;

	startval = NULL;
	i = 0;
	if (convert(name, &s_name))
		return (ERROR_MALLOC);
	while (s_env[i].s)
	{
		if (ft_strncmp(s_env[i].s, s_name.s, s_name.len) == 0)
			startval = &s_env[i].s[s_name.len];
		i++;
	}
	str_delete(&s_name);
	if (startval)
	{
		*value = str_copy(startval);
		return ((*value).s ? 0 : ERROR_MALLOC);
	}
	ft_bzero(value, sizeof(t_string));
	return (0);
}
