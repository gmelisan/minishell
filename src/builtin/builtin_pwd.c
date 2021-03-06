/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:15:01 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 04:02:37 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_pwd(void)
{
	char buf[CWD_BUFSIZE];

	ft_bzero(buf, CWD_BUFSIZE);
	if (!(getcwd(buf, CWD_BUFSIZE - 1)))
		return (ERROR_GETCWD);
	ft_printf("%s\n", buf);
	return (0);
}
