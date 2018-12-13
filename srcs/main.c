/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:15:14 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/27 17:36:41 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	**cmd;
	char	*line;
	int		status;

	(void)ac;
	(void)av;
	status = 1;
	cmd = NULL;
	init_env(env);
	while (status)
	{
		ft_putstr("$>");
		line = NULL;
		signal(SIGINT, signal_handler);
		if (get_next_line(1, &line) != -1 && !ft_strequ(line, ""))
			minishell(cmd, line);
		ft_strdel(&line);
	}
	return (0);
}

void	minishell(char **cmd, char *line)
{
	cmd = parse_cmd(line);
	if (ft_2d_strlen(cmd) == 0 ||
			ft_builtin_func(ft_2d_strlen(cmd), cmd) != -1)
	{
		free_2d_arr(cmd);
		return ;
	}
	else
		exec_cmd(cmd, g_env);
	free_2d_arr(cmd);
}

int		clear(void)
{
	write(1, "\33[H\33[2J", 7);
	return (1);
}

int		ft_builtin_func(int ac, char **av)
{
	int		i;

	i = 1;
	if (ft_strequ(av[0], "echo"))
	{
		while (av[i])
			ft_echo(ac, av[i++]);
		ft_putchar('\n');
		return (1);
	}
	if (ft_strequ(av[0], "cd"))
		return (ft_cd(ac, av));
	if (ft_strequ(av[0], "setenv"))
		return (ft_setenv(ac, av));
	if (ft_strequ(av[0], "unsetenv"))
		return (ft_unsetenv(ac, av));
	if (ft_strequ(av[0], "env"))
		return (ft_env(ac, av));
	if (ft_strequ(av[0], "exit"))
		exit((av[1]) ? ft_atoi(av[1]) : 0);
	if (ft_strequ(av[0], "clear"))
		return (clear());
	return (-1);
}
