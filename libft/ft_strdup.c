/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:52:39 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/10/31 13:53:45 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	i;

	i = ft_strlen((char*)str) + 1;
	new_str = (char *)malloc(sizeof(char) * i);
	if (new_str != NULL)
	{
		return (ft_memcpy(new_str, str, i));
	}
	else
		return (NULL);
}
