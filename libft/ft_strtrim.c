/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:18:22 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/06/14 11:20:51 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (i < j))
		j--;
	str = ft_strnew(j - i + 1);
	if (str == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[j + 1] = '\0';
	return (str);
}
