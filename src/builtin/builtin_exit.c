/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:09:50 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 16:22:06 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_exit(t_string *s_argv)
{
	int code;

	code = 0;
	if (s_argv[1].s)
		code = ft_atoi(s_argv[1].s);
	return (code);
}
