/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 23:22:32 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/25 12:00:18 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		print_error(char *cmd)
{
	ft_putstr_fd("-minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (-1);
}

void	exit_error(char *s)
{
	ft_putstr_fd("-Minishell: exit: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

void	cd_error(int n, char *str)
{
	if (n == 1)
	{
		ft_putstr_fd("cd : ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(" : No such file or directory", 2);
	}
	else if (n == 2)
	{
		ft_putstr_fd("cd : ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(" : Not a directory", 2);
	}
}

int		env_error(char *str)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (1);
}
