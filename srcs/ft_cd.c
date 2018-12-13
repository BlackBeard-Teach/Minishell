/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 23:17:41 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/27 14:30:03 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_cwd(char *cwd)
{
	char buf[4096];
	char *content;

	getcwd(buf, 4096);
	ft_set_env("PWD", buf);
	if (!cwd)
	{
		content = get_var_content("HOME");
		chdir(content);
		ft_strdel(&content);
	}
	else
		chdir(cwd);
	getcwd(buf, 4096);
	content = get_var_content("PWD");
	ft_set_env("OLDPWD", content);
	ft_strdel(&content);
	ft_set_env("PWD", buf);
}

static int	is_dir(char *path)
{
	struct stat s;

	stat(path, &s);
	if (s.st_mode & S_IFDIR)
		return (1);
	return (0);
}

static char	*parse_path(char *path)
{
	char *ret;
	char *temp;

	if (path[0] == '~')
	{
		temp = get_var_content("HOME");
		ret = ft_strjoin(temp, &path[1]);
		ft_strdel(&temp);
	}
	else
		ret = ft_strdup(path);
	return (ret);
}

void		cd_dash(void)
{
	char	*temp;

	temp = get_var_content("OLDPWD");
	change_cwd(temp);
	ft_strdel(&temp);
	temp = get_var_content("PWD");
	ft_putendl(temp);
	ft_strdel(&temp);
}

int			ft_cd(int ac, char **av)
{
	char	*parsed;

	if (ac == 1)
		change_cwd(NULL);
	else
	{
		parsed = parse_path(av[1]);
		if (!ft_strcmp(av[1], "-"))
			cd_dash();
		else if (access(parsed, F_OK) == -1)
			cd_error(1, av[1]);
		else if (!is_dir(parsed))
			cd_error(2, av[1]);
		else
			change_cwd(parsed);
		ft_strdel(&parsed);
	}
	return (1);
}
