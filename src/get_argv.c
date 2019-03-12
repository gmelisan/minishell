/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:38:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 18:34:55 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_endsymbol(int c)
{
	if (c == 0 || c == ';')
		return (1);
	return (0);
}

static void	del(void *elem)
{
	str_delete((t_string*)elem);
}

static int	get_word(t_string line, int *i, t_string *word, t_string *s_env)
{
	int		dquote;
	int		ret;

	dquote = 0;
	ret = 0;
	if (str_get(line, *i) == '~' && (ret = handle_tilda(line, i, word, s_env)))
		return (ret);
	while (!is_endsymbol(str_get(line, *i)) &&
			(dquote || !ft_isspace(str_get(line, *i))))
	{
		if (str_get(line, *i) == '"')
			dquote = handle_dquote(i, dquote);
		else if (str_get(line, *i) == '$')
			ret = handle_dollar(line, i, word, s_env);
		else if (str_get(line, *i) == '\\')
			ret = handle_backslash(line, i, word);
		else
			ret = handle_common(line, i, word);
		if (ret)
			return (ret);
	}
	if (dquote)
		return (ERROR_BADQUOTE);
	return (0);
}

static int	parse(t_string line, int *i, t_vector *vec, t_string *s_env)
{
	int			ret;
	t_string	word;

	while (1)
	{
		while (ft_isspace(str_get(line, *i)))
			*i += 1;
		if (is_endsymbol(str_get(line, *i)))
			break ;
		word = str_create(0);
		if ((ret = get_word(line, i, &word, s_env)))
		{
			vec_delete(vec, del);
			str_delete(&word);
			return (ret);
		}
		if (vec_addback(vec, (void *)&word) == NULL)
			return (ERROR_MALLOC);
	}
	return (0);
}

int			get_argv(t_string line, int *i, t_string **ps_argv,
						t_string *s_env)
{
	t_vector	vec;
	int			ret;

	ret = 0;
	if (!str_get(line, *i))
	{
		*i = -1;
		return (0);
	}
	vec = vec_create(0, sizeof(t_string));
	if (!vec.v)
		return (ERROR_MALLOC);
	ret = parse(line, i, &vec, s_env);
	if (ret || vec.len == 0)
		ft_memdel((void **)&vec.v);
	*ps_argv = (t_string *)vec.v;
	*i += 1;
	return (ret);
}
