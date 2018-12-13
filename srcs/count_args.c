/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 02:01:24 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/26 12:26:35 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_args(char *str)
{
	int	nbr_words;
	int	i;

	nbr_words = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '\t')
				&& ((str[i - 1] == ' ' || str[i - 1] == '\t') || i == 0))
			nbr_words++;
		i++;
	}
	return (nbr_words);
}
