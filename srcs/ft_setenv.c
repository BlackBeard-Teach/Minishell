/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:12:07 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/26 17:11:37 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_env(char *var, char *content)
{
	char	*temp;
	char	*temp2;
	int		i;
	int		index;

	i = 0;
	temp2 = ft_strjoin(var, "=");
	temp = ft_strjoin(temp2, content);
	index = get_env_var(g_env, var);
	if (index == -1)
		g_env = add_env_var(g_env, temp);
	else
	{
		ft_strdel(&g_env[index]);
		g_env[index] = ft_strdup(temp);
	}
	ft_strdel(&temp);
	ft_strdel(&temp2);
}

char	**replace_var(char **env, char *var)
{
	int		i;
	int		index;
	char	**temp;

	i = 0;
	temp = ft_strsplit(var, '=');
	index = get_env_var(env, temp[0]);
	if (index != -1)
	{
		ft_strdel(&env[index]);
		env[index] = ft_strdup(var);
	}
	else
		env = add_env_var(env, var);
	free_2d_arr(temp);
	return (env);
}

int		ft_setenv(int ac, char **av)
{
	if (ac == 1)
		print_env(g_env);
	if (ac == 2)
		ft_set_env(av[1], "");
	if (ac == 3)
		ft_set_env(av[1], av[2]);
	else if (ac > 3)
		ft_putstr_fd("setenv: Too many arguments\n", STDERR_FILENO);
	return (1);
}
