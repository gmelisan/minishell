/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:11:56 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/04 16:37:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_builtin(t_string str)
{
	if (ft_strcmp(str.s, "cd"))
		return (1);
	if (ft_strcmp(str.s, "exit"))
		return (1);
	return (0);
}
