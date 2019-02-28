/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 06:44:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/28 18:35:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_argv_list(t_string line, t_list **argvlist)
{
	t_string	str;
	static int	i = 0;
	int			len;
	int			start;

	*argvlist = NULL;
	while (str_get(line, i) && str_get(line, i) != ';')
	{
		start = i;
		len = 0;
		while (line.s[i] && !ft_isspace(line.s[i]))
		{
			i++;
			len++;
		}
		if (len)
		{
			str = str_create(len);
			if (!str.s)
				return (-1);
			ft_memcpy(str.s, &(line.s[start]), len);
			ft_lstaddback(argvlist, ft_lstnew(&str, sizeof(t_string)));
		}
	}
	i++;
	return (*argvlist ? 1 : 0);
}

t_string	word(t_string line, int *i, int cmdlen)
{
	int start;
	int	inside_q;

	inside_q = 0;
	start = i;
	while (i < cmdlen)
	{
		if (str_get(line, i) == '"')
			inside_q = 1;
		if (inside_q && str_get(line, i) == '"')
			inside_q = 0;
		if (str_get(line, i) == '"')
			i++;
		if (!inside_q && ft_isspace(str_get(line, i)))
			break;
		i++;
	}
	if (inside_q)
	{
		return (ERROR_BADSYN);
	}
	return (str_substring(line, start, i - start));
}

int			get_cmdlen(t_string line, int i)
{
	int len;

	len = 0;
	while (str_get(line, i) && line.s != ';')
		len++;
	return (len - i);
}

int			get_argv(t_string line, char ***p_argv)
{
	int		cmdlen;
	int		len;
	char	**argv;
	static int		i;

	cmdlen = get_cmdlen(line, i);
	len = 20;
	argv = *p_argv;
	argv = (char **)ft_memalloc(sizeof(char *) * len);
	if (!argv)
		return (ERROR_MALLOC);
	while (str_get(line, i))
	{
		
	}
	*p_argv = argv;
	return (0);
}


/* 

"  abcd efgh ; hello my; suka "a b c"      "

toklist:

abcd - word
efgh - word
; - semicol
hello - word
my - word
; semicol
suka - word
" - quote
a - word
b - word
c - word
" quote

cmdlist:

["abcd", "efgh"]
["hello", "my"]
["suka", "a b c"]

 */
