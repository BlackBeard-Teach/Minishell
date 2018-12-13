/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:18:31 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/27 15:30:12 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			env_help(char *temp, char **tempenv, char **av, int err)
{
	int i;

	i = -1;
	while (av[++i])
	{
		if (ft_strchr(av[i], '='))
			tempenv = replace_var(tempenv, av[i]);
		else if (temp != NULL)
		{
			err = exec_cmd(&av[i], tempenv);
			ft_strdel(&temp);
			break ;
		}
		else
			err = env_error(av[i]);
		if (!ft_strchr(av[i], '='))
			err = 1;
	}
}

char			**env_helper(char **av, char **tempenv)
{
	char	*temp;
	int		err;
	int		i;

	i = -1;
	err = 0;
	temp = get_exec(tempenv, av[i]);
	env_help(temp, tempenv, &av[i], err);
	if (err == 0)
		print_env(tempenv);
	return (tempenv);
}

char			**parse_cmd(char *s)
{
	int		tab_size;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	tab_size = count_args(s);
	tab = (char **)malloc(sizeof(char *) * tab_size + 1);
	if (tab == NULL)
		return (NULL);
	while (tab_size--)
	{
		while ((*s == ' ' || *s == '\t') && *s)
			s++;
		if ((tab[i++] = ft_strsub(s, 0, arg_len(s))) == NULL)
			return (NULL);
		s += arg_len(s);
	}
	tab[i] = NULL;
	return (tab);
}
