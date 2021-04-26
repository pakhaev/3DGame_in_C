/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:58:43 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/12 13:02:52 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i] != '\0' && i < n && s1[i] == s2[j])
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return ((char *)&s1[i - j]);
			i -= j;
		}
		i++;
	}
	return (NULL);
}
