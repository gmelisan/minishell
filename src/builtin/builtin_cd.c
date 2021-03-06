/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:58:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 04:05:22 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cwd(t_string *str)
{
	char	buf[CWD_BUFSIZE];

	ft_bzero(buf, CWD_BUFSIZE);
	if (!(getcwd(buf, CWD_BUFSIZE - 1)))
		return (ERROR_GETCWD);
	*str = str_copy(buf);
	if (!(*str).s)
		return (ERROR_MALLOC);
	return (0);
}

static int	change_dir(t_string path, t_string **ps_env)
{
	struct stat	st;
	t_string	curpath;
	int			ret;

	if (stat(path.s, &st) == -1)
		return (ERROR_NOSUCHFOD);
	if (!is_dir(st))
		return (ERROR_CDFILE);
	if (access(path.s, X_OK) != 0)
		return (ERROR_NOXRIGHT);
	if ((ret = cwd(&curpath)))
		return (ret);
	if ((ret = env_setval(ps_env, "OLDPWD", curpath)))
		return (ret);
	str_delete(&curpath);
	if (chdir(path.s) == -1)
		return (ERROR_CHDIR);
	if ((ret = cwd(&curpath)))
		return (ret);
	if ((ret = env_setval(ps_env, "PWD", curpath)))
		return (ret);
	str_delete(&curpath);
	return (0);
}

int			builtin_cd(t_string *s_argv, t_string **ps_env)
{
	t_string	path;
	int			ret;

	if (!s_argv[1].s)
	{
		if ((ret = env_getval(*ps_env, "HOME", &path)))
			return (ret);
	}
	else if (ft_strequ(s_argv[1].s, "-"))
	{
		if ((ret = env_getval(*ps_env, "OLDPWD", &path)))
			return (ret);
	}
	else
		path = str_duplicate(s_argv[1]);
	if ((ret = change_dir(path, ps_env)))
		ft_fdprintf(STDERR, "%s: ", s_argv[1].s);
	str_delete(&path);
	return (ret);
}
