/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:41:05 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/06/12 16:13:32 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *k;
	unsigned const char *j;

	k = (unsigned const char *)s1;
	j = (unsigned const char *)s2;
	while (n != '\0')
	{
		if (*k != *j)
			return (*k - *j);
		k++;
		j++;
		n--;
	}
	return (0);
}
