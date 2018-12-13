/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:39:58 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/26 16:55:17 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env(int ac, char **av)
{
	char	**tempenv;

	if (ac == 1)
		return (print_env(g_env));
	else
	{
		tempenv = ft_2d_arrcpy(g_env);
		env_helper(av, tempenv);
		free_2d_arr(tempenv);
	}
	return (1);
}

int		print_env(char **env)
{
	int i;

	i = -1;
	while (env[++i])
		if (ft_strcmp(env[i], "") != 0)
			ft_putendl(env[i]);
	return (1);
}

char	*get_var_content(char *var)
{
	int		index;
	char	**temp;
	char	*ret;

	index = get_env_var(g_env, var);
	if (index == -1)
		return (NULL);
	temp = ft_strsplit(g_env[index], '=');
	ret = ft_strdup(temp[1]);
	free_2d_arr(temp);
	return (ret);
}

char	**add_env_var(char **env, char *var)
{
	int		i;
	int		size;
	char	**new;

	i = 0;
	size = ft_2d_strlen(env) + 1;
	new = (char **)malloc(sizeof(char *) * size + 1);
	if (new == NULL)
		return (NULL);
	while (i < size - 1)
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = ft_strdup(var);
	new[i + 1] = NULL;
	free_2d_arr(env);
	return (new);
}
