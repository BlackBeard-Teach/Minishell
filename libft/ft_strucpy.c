/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strucpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:15:40 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/22 13:13:56 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strucpy(char **dest, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c || src[i] == '\0')
			break ;
		i++;
	}
	if ((*dest = ft_strnew(i + 1)) == NULL)
		return (-1);
	ft_strncpy(*dest, src, i);
	return (i);
}
