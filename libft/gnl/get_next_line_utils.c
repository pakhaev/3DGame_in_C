/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:05:27 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/21 18:04:54 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnlen(char *str, int f)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (f == 1)
		while (str[i] && str[i] != '\n')
			i++;
	else
		while (str[i])
			i++;
	return (i);
}

int		ft_returning(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_gnljoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (ft_gnlen((char *)s1, 0) + \
						ft_gnlen((char *)s2, 0) + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

char	*ft_gnldup(char *str)
{
	char	*nstr;
	size_t	i;

	if (!str)
		return (NULL);
	i = ft_gnlen((char*)str, 1);
	if (!(nstr = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strgnldup(char *str)
{
	char	*nstr;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	j = 0;
	i = ft_gnlen(str, 1);
	if (!str[i] || !(nstr = (char*)malloc(sizeof(char) * \
					((ft_gnlen(str, 0) - i) + 1))))
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i])
		nstr[j++] = str[i++];
	nstr[j] = '\0';
	free(str);
	return (nstr);
}
