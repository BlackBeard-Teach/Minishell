/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:23:01 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/06/12 07:38:08 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = ft_strlen(s1);
	dest = (char *)malloc(sizeof(*s1) * i + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}
