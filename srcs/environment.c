/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:28:23 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/27 15:42:13 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * (i + 1));
	g_env[i] = NULL;
	i = -1;
	while (env[++i])
		g_env[i] = ft_strdup(env[i]);
	return ;
}

int		get_env_var(char **env, char *var)
{
	int		i;
	char	*recent;

	i = 0;
	while (env[i] && ft_strcmp((recent = get_var_name(env[i])), var) != 0)
	{
		ft_strdel(&recent);
		i++;
	}
	if (env[i])
		ft_strdel(&recent);
	if (env[i])
		return (i);
	else
		return (-1);
}

char	*get_var_name(char *var)
{
	int		i;
	char	*ret;

	i = 0;
	if (!var || !*var)
		return (NULL);
	if (var[0] == '=')
		return (var);
	while (var[i])
	{
		if (var[i] == '=' || var[i] == '\0')
			break ;
		i++;
	}
	ret = ft_strnew(i + 1);
	if (ret == NULL)
		return (NULL);
	ft_strncpy(ret, var, i);
	return (ret);
}
