/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 21:57:40 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 07:02:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_help(void)
{
	ft_printf("minishell, by gmelisan\n\n");
	ft_printf("Internal commands:\n");
	ft_printf("- echo\n- cd\n- setenv\n- unsetenv\n- env\n");
	ft_printf("- pwd\n- help\n- exit\n");
	return (0);
}
