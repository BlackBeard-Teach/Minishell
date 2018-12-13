/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_arrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:16:45 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/26 16:49:54 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_2d_arrcpy(char **tab)
{
	char	**ret;
	int		size;
	int		i;

	size = ft_2d_strlen(tab);
	i = -1;
	ret = (char **)malloc(sizeof(char *) * size + 1);
	if (ret == NULL)
		return (NULL);
	while (++i < size)
	{
		ret[i] = ft_strdup(tab[i]);
		if (ret[i] == NULL)
			return (NULL);
	}
	ret[i] = NULL;
	return (ret);
}
