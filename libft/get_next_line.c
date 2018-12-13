/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 07:44:54 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/09/22 15:22:33 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_newline(char **str, char **line, int fd, int ret_out)
{
	char	*temp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		temp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (ret_out == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[255];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			ret_out;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret_out = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret_out] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret_out < 0)
		return (-1);
	else if (ret_out == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_newline(str, line, fd, ret_out));
}
