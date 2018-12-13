/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:23:14 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/06/11 12:35:38 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*csrc;
	char		*cdst;

	csrc = src;
	cdst = dst;
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			cdst[i - 1] = csrc[i - 1];
			i--;
		}
	}
	else if (cdst < csrc)
		ft_memcpy(cdst, csrc, len);
	return (cdst);
}
