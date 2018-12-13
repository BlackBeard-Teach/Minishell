/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:06:10 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/26 16:54:12 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		ft_putstr("$>");
	}
	return ;
}

void	process_sighandler(int signo)
{
	if (signo == SIGINT)
		ft_putchar('\n');
}
