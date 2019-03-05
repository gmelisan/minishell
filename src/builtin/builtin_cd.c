/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:58:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 21:18:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_dir(struct stat st)
{
	if ((st.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

static	int	change_dir(t_string path)
{
	struct stat	st;

	if (stat(path.s, &st) == -1)
		return (ERROR_NODIR);
	if (!is_dir(st))
		return (ERROR_CDFILE);
	if (chdir(path.s) == -1)
		return (ERROR_CD);
	return (0);
}

int		builtin_cd(t_string *s_argv, t_string *s_env)
{
	t_string	path;
	int			ret;

	if (!s_argv[1].s)
	{
		if ((ret = env_getval(s_env, "HOME", &path)))
			return (ret);
	}
	else
		path = str_duplicate(s_argv[1]);
	ret = change_dir(path);
	str_delete(&path);
	return (ret);
}
