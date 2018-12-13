/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:09:12 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/25 11:39:36 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_puts(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\"' && str[i] != '\'')
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar(' ');
}

void	echo_helper(char *str)
{
	int		i;
	int		j;
	char	*s;
	char	*temp;

	i = 0;
	while (g_env[i])
	{
		j = 0;
		while (g_env[i][j] != '=')
			j++;
		s = ft_strnew(j);
		s = ft_strncpy(s, g_env[i], j);
		if (ft_strequ(s, str))
			break ;
		temp = s;
		ft_strdel(&s);
		free(s);
		i++;
	}
	if (ft_strequ(temp, str) == 1)
		ft_putstr(g_env[i] + j + 1);
	free(s);
}

int		ft_echo(int ac, char *str)
{
	if (ac == 1)
		ft_putchar('\n');
	else if (str[0] == '$')
	{
		str++;
		echo_helper(str);
	}
	else
		ft_puts(str);
	return (1);
}
