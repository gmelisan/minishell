/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:11:56 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/07 21:57:00 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_builtin(t_string *s_argv)
{
	if (ft_strequ(s_argv[0].s, "exit"))
		return (1);
	else if (ft_strequ(s_argv[0].s, "cd"))
		return (1);
	else if (ft_strequ(s_argv[0].s, "pwd"))
		return (1);
	else if (ft_strequ(s_argv[0].s, "env"))
		return (1);
	else if (ft_strequ(s_argv[0].s, "setenv"))
		return (1);
	else if (ft_strequ(s_argv[0].s, "unsetenv"))
		return (1);
	else if (ft_strequ(s_argv[0].s, "echo"))
		return (1);
	else if (ft_strequ(s_argv[0].s, "help"))
		return (1);
	return (0);
}
