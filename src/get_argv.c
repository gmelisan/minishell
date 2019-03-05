/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:38:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/04 16:30:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			get_argv(t_string line, t_string **ps_argv)
{
	t_string	*s_argv;

	s_argv = str_split(line, ft_isspace);
	if (!s_argv)
		return (ERROR_MALLOC);
	*ps_argv = s_argv;
	return (0);
}
