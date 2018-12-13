/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:49:09 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/27 16:07:33 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include "../libft/libft.h"

# define DOES_NOT_EXIST 1
# define NOT_A_DIR 2

char		**g_env;
void		minishell(char **cmd, char *line);
int			ft_builtin_func(int ac, char **av);
void		free_2d_arr(char **cmd);
int			ft_env(int ac, char **av);
int			print_env(char **env);
int			env_error(char *str);
char		*get_var_content(char *var);
char		**add_env_var(char **env, char *var);
void		ft_set_env(char *var, char *content);
char		**replace_var(char **env, char *var);
int			ft_setenv(int ac, char **av);
int			ft_unsetenv(int ac, char **av);
int			ft_cd(int ac, char **av);
int			ft_echo(int ac, char *str);
void		init_env(char **env);
int			get_env_var(char **env, char *var);
char		*get_var_name(char *var);
char		**env_helper(char **av, char **tempenv);
char		**parse_cmd(char *s);
int			ft_exit(int ac, char **av);
void		exit_error(char *arg);
int			exec_cmd(char **cmd, char **env);
char		**find_paths(char **env);
char		*get_exec(char **env, char *path);
int			print_error(char *cmd);
void		cd_error(int n, char *str);
void		signal_handler(int signo);
void		process_sighandler(int signo);
int			count_args(char *str);
int			arg_len(char *s);
#endif
