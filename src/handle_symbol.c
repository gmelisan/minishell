/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_symbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 04:59:40 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 20:43:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		handle_tilda(t_string line, int *i, t_string *word, t_string *s_env)
{
	t_string	home;
	int			ret;

	if (str_get(line, *i + 1) != '/' && !is_endsymbol(str_get(line, *i + 1)))
		return (0);
	if ((ret = env_getval(s_env, "HOME", &home)))
		return (ret);
	if (!home.s)
		return (0);
	if (str_addback(word, home.s, home.len) == NULL)
		return (ERROR_MALLOC);
	str_delete(&home);
	*i += 1;
	return (0);
}

int		handle_dquote(int *i, int dquote)
{
	*i += 1;
	return (dquote ^= 1);
}

int		handle_backslash(t_string line, int *i, t_string *word)
{
	*i += 1;
	if (str_addback(word, line.s + *i, 1) == NULL)
		return (ERROR_MALLOC);
	*i += 1;
	return (0);
}

int		handle_dollar(t_string line, int *i, t_string *word,
								t_string *s_env)
{
	int			ret;
	t_string	var;
	t_string	value;

	*i += 1;
	if (!ft_isalnum(str_get(line, *i)))
		return (str_addback(word, &line.s[*i - 1], 1) == NULL ?
				ERROR_MALLOC : 0);
	str_zero(&var);
	while (ft_isalnum(str_get(line, *i)))
	{
		str_addback(&var, &line.s[*i], 1);
		*i += 1;
	}
	if ((ret = env_getval(s_env, var.s, &value)))
		return (ret);
	str_delete(&var);
	if (!value.s)
		return (0);
	if (str_addback(word, value.s, value.len) == NULL)
		return (ERROR_MALLOC);
	str_delete(&value);
	return (0);
}

int		handle_common(t_string line, int *i, t_string *word)
{
	if (str_addback(word, &line.s[*i], 1) == NULL)
		return (ERROR_MALLOC);
	*i += 1;
	return (0);
}
