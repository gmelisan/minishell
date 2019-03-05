/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 07:21:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/04 16:42:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print(char **a)
{
	int i;

	i = 0;
	while (a[i])
	{
		ft_printf("[%s]\n", a[i]);
		i++;
	}
}

static int convert(t_string *s_argv, char ***p_argv)
{
	int		i;
	char	**argv;

	i = 0;
	while (s_argv[i].s)
		i++;
	argv = (char **)ft_memalloc(sizeof(*argv) * (i + 1));
	if (!argv)
		return (ERROR_MALLOC);
	i = 0;
	while (s_argv[i].s)
	{
		argv[i] = (char *)ft_memalloc(sizeof(**argv) * (s_argv[i].len + 1));
		if (!argv[i])
			return (ERROR_MALLOC);
		ft_memcpy(argv[i], s_argv[i].s, s_argv[i].len);
		i++;
	}
	*p_argv = argv;
	return (0);
}

static void	clear(t_string **ps_argv, char ***p_argv)
{
	int i;

	i = 0;
	while ((*ps_argv)[i].s)
		str_delete(&(*ps_argv)[i++]);
	free(*ps_argv);
	*ps_argv = NULL;
	ft_strarrdel(p_argv);
}

int		exec_line(t_string line)
{
	int			ret;
	t_string	*s_argv;
	char		**argv;

	ret = get_argv(line, &s_argv);
	if (ret)
		return (ret);
	/* print(argv); */
	if (check_builtin(s_argv[0])
		exec_builtin(s_argv);
	ret = convert(s_argv, &argv);
	if (ret)
	{
		clear(&s_argv, &argv);
		return (ret);
	}
	ret = exec_command(argv, environ);
	clear(&s_argv, &argv);
	return (ret ? ret : 0);
}
