/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:17:16 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/22 18:17:39 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_unset_env(char *var)
{
	int		i;
	int		j;
	int		size;
	char	**new;
	int		index;

	i = 0;
	j = 0;
	size = ft_2d_strlen(g_env) - 1;
	index = get_env_var(g_env, var);
	if (index == -1)
		return ;
	if ((new = (char **)malloc(sizeof(char *) * size + 1)) == NULL)
		return ;
	while (g_env[j])
	{
		if (ft_strcmp(g_env[j], g_env[index]) != 0)
			new[i++] = ft_strdup(g_env[j]);
		j++;
	}
	new[i] = NULL;
	free_2d_arr(g_env);
	g_env = new;
}

int			ft_unsetenv(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		ft_putstr_fd("unsetenv: not enough arguments\n", STDERR_FILENO);
	else
		while (av[i])
			ft_unset_env(av[i++]);
	return (1);
}
