/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:35:44 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/09 16:24:24 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*str;
	size_t			i;
	size_t			j;
	unsigned char	*dst;

	j = 0;
	i = 0;
	str = (unsigned char*)s;
	dst = (unsigned char*)malloc(sizeof(*str) * (len + 1));
	if (!str || !dst)
		return (NULL);
	while (str[j])
	{
		if (j >= start && i < len)
		{
			dst[i] = str[j];
			i++;
		}
		j++;
	}
	dst[i] = '\0';
	return ((char*)dst);
}
