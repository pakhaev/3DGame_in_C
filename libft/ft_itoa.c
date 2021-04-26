/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:41:52 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/14 18:50:45 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int s)
{
	int		i;
	long	c;

	c = s;
	i = 0;
	if (c < 0)
		c *= -1;
	while (c >= 10)
	{
		c /= 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_res(long n, int len, char *res)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		res[i] = '-';
		i = len;
		len++;
		n *= -1;
	}
	else
		i = len - 1;
	while (n >= 10)
	{
		res[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	res[i] = n % 10 + 48;
	res[len] = '\0';
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nb;
	char	*dst;
	int		i;

	i = 0;
	nb = n;
	len = ft_numlen((int)nb);
	if (!(res = (char *)malloc(sizeof(char) * len + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (nb == 0)
	{
		res[i++] = nb + 48;
		res[i] = '\0';
		return (res);
	}
	dst = ft_res(nb, len, res);
	if (!dst)
		return (NULL);
	return (dst);
}
