/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:14:58 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/21 18:05:10 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_processing(int fd, char *str, char *buf)
{
	int res;

	res = 1;
	while (res != 0 && !ft_returning(str))
	{
		if ((res = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return ((char*)-1);
		}
		buf[res] = '\0';
		str = ft_gnljoin(str, buf);
	}
	free(buf);
	if (!str)
		return (NULL);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	char		*buf;
	static char	*str;

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	str = ft_processing(fd, str, buf);
	if (str == (char*)-1)
		return (-1);
	*line = ft_gnldup(str);
	str = ft_strgnldup(str);
	if (!str)
	{
		free(str);
		return (0);
	}
	return (1);
}
