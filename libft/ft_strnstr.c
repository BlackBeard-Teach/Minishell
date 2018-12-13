/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:31:11 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/06/06 09:27:12 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)hay);
	i = 0;
	while (hay[i])
	{
		j = 0;
		while ((i + j < len) && hay[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)hay + i);
		}
		i++;
	}
	return (NULL);
}
