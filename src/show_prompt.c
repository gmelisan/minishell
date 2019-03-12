/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 04:56:30 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 06:00:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		replace(t_string home, t_string cwd, t_string *path)
{
	size_t	i;

	i = 0;
	while ((str_get(cwd, i) == str_get(home, i)) && i < cwd.len)
		i++;
	if (home.s && i == home.len)
	{
		if (str_addback(path, "~", 1) == NULL)
			return (ERROR_MALLOC);
		if (str_addback(path, cwd.s + i, cwd.len - i) == NULL)
			return (ERROR_MALLOC);
	}
	else
	{
		*path = str_duplicate(cwd);
		if (!path->s)
			return (ERROR_MALLOC);
	}
	return (0);
}

static int		get_pathstr(t_string *s_env, t_string *path)
{
	t_string	home;
	t_string	cwd;
	int			ret;

	str_zero(path);
	if ((ret = env_getval(s_env, "HOME", &home)))
		return (ret);
	cwd = str_create(CWD_BUFSIZE);
	if (!cwd.s)
		return (ERROR_MALLOC);
	if (!(getcwd(cwd.s, cwd.len)))
		return (ERROR_GETCWD);
	str_fixlen(&cwd);
	if ((ret = replace(home, cwd, path)))
		return (ret);
	str_delete(&home);
	str_delete(&cwd);
	return (0);
}

void			show_prompt(int fd, t_string *s_env)
{
	t_string	path;
	int			ret;

	if (fd != STDIN)
		return ;
	ret = get_pathstr(s_env, &path);
	if (ret)
		ft_printf("{red}ERR(%d) $>{eoc} ", ret);
	else
	{
		ft_printf("{red}%s $>{eoc} ", path.s);
		str_delete(&path);
	}
}
