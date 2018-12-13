/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:28:49 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/06/13 13:36:38 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	char				*csrc;
	char				*cdst;

	i = 0;
	csrc = (char*)src;
	cdst = (char*)dst;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
