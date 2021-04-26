/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:32:11 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/13 20:32:12 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		xpm_correct(char *str, t_str *st, char *nstr, int fl)
{
	st->i = ft_strlen(str) - 1;
	st->j = ft_strlen(nstr) - 1;
	st->x = 0;
	while (st->x < st->j)
	{
		if (str[st->i] != nstr[st->j])
			(fl) ? ft_error(-12, st) : ft_error(-3, st);
		st->x++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
