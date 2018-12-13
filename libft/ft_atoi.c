/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:09:58 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/06/05 14:14:39 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	neg;
	int i;

	nb = 0;
	neg = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = (nb * 10) - 48 + str[i];
		i++;
	}
	if (neg == 1)
		return (-nb);
	else
		return (nb);
}
