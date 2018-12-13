/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:41:55 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/27 15:43:29 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*path_to_bin(char *path, char *bin)
{
	char *ret;
	char *temp;

	temp = ft_strjoin(path, "/");
	ret = ft_strjoin(temp, bin);
	ft_strdel(&temp);
	return (ret);
}

int			exec_cmd(char **cmd, char **env)
{
	pid_t	process;
	char	*bin;

	bin = get_exec(env, cmd[0]);
	if (bin == NULL)
		return (print_error(cmd[0]));
	process = fork();
	signal(SIGINT, process_sighandler);
	if (process == 0)
		process = execve(bin, cmd, env);
	else
		wait(&process);
	ft_strdel(&bin);
	return (1);
}

char		**find_paths(char **env)
{
	char	**temp;
	char	**ret;

	if (get_env_var(env, "PATH") == -1)
		return (NULL);
	if ((temp = ft_strsplit(env[get_env_var(env, "PATH")], '=')) == NULL)
		return (NULL);
	if ((ret = ft_strsplit(temp[1], ':')) == NULL)
	{
		free_2d_arr(temp);
		return (NULL);
	}
	else
	{
		free_2d_arr(temp);
		return (ret);
	}
}

char		*fuck_norm(char **newpath, char *path, char **temp, int size)
{
	struct stat s;
	int			i;

	i = -1;
	while (temp[++i] &&
			((stat((*newpath = path_to_bin(temp[i], path)), &s)) == -1 \
			|| !(s.st_mode & S_IFREG)))
		ft_strdel(*(&newpath));
	free_2d_arr(temp);
	if (i == size)
		return (NULL);
	else
		return (*newpath);
}

char		*get_exec(char **env, char *path)
{
	char		**temp;
	struct stat	s;
	int			i;
	int			size;
	char		*newpath;

	i = 0;
	newpath = NULL;
	temp = find_paths(env);
	if (stat(path, &s) == 0 && (s.st_mode & S_IFREG))
	{
		free_2d_arr(temp);
		return (ft_strdup(path));
	}
	if (temp == NULL)
		return (NULL);
	while (temp[i++])
		size = i;
	fuck_norm(&newpath, path, temp, size);
	return (newpath);
}
