/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:20:58 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/02 13:03:07 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*s;

	s = (char *)str + ft_strlen((char *)str);
	while (str <= s)
	{
		if (*s == (char)ch)
			return (s);
		s--;
	}
	return (NULL);
}
