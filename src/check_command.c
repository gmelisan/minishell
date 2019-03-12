/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:53:56 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 08:32:30 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_directory(char *path)
{
	struct stat st;

	stat(path, &st);
	if (is_dir(st))
		return (1);
	return (0);
}

static int	find_file(t_string *pathes, t_string name, t_string *found)
{
	int			i;
	t_string	abspath;

	ft_bzero(found, sizeof(t_string));
	i = -1;
	while (pathes[++i].s)
	{
		abspath = str_duplicate(name);
		if (!abspath.s)
			return (ERROR_MALLOC);
		if (str_addfront(&abspath, "/", 1) == NULL)
			return (ERROR_MALLOC);
		if (str_addfront(&abspath, pathes[i].len ? pathes[i].s : ".",
									pathes[i].len ? pathes[i].len : 1) == NULL)
			return (ERROR_MALLOC);
		if (access(abspath.s, F_OK) == 0 && !is_directory(abspath.s))
		{
			*found = abspath;
			return (0);
		}
		str_delete(&abspath);
	}
	return (0);
}

static	int	noslash(t_string *s_argv, t_string *s_env)
{
	t_string	path;
	t_string	*pathes;
	int			ret;

	if ((ret = env_getval(s_env, "PATH", &path)))
		return (ret);
	if ((ret = split_path(path, &pathes)))
		return (ERROR_MALLOC);
	str_delete(&path);
	if ((ret = find_file(pathes, s_argv[0], &path)))
		return (ret);
	str_delarr(&pathes);
	if (!path.s)
		return (ERROR_NOCOMMAND);
	str_delete(&s_argv[0]);
	s_argv[0] = path;
	return (0);
}

int			check(t_string *s_argv, t_string *s_env)
{
	int			ret;
	struct stat	st;

	if (!ft_strchr(s_argv[0].s, '/'))
		if ((ret = noslash(s_argv, s_env)))
			return (ret);
	if (stat(s_argv[0].s, &st) == -1)
		return (ERROR_NOSUCHFOD);
	if (is_dir(st))
		return (ERROR_CMDDIR);
	if (access(s_argv[0].s, X_OK) != 0)
		return (ERROR_NOXRIGHT);
	return (0);
}

int			check_command(t_string *s_argv, t_string *s_env)
{
	int ret;

	ret = check(s_argv, s_env);
	if (ret)
		ft_fdprintf(STDERR, "%s: ", s_argv[0].s);
	return (ret);
}
