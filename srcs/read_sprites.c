/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:28:41 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 16:28:58 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	sprite_correct(t_str *st)
{
	int	j;

	j = 0;
	while (st->numspr > j)
	{
		ckeck_close_map(st->sprite[j].x - 0.5, st->sprite[j].y \
		- 0.5, st, st->heightm);
		j++;
	}
}

void			ft_sprites(t_str *st)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while (i < st->heightm)
	{
		j = 0;
		while (st->map[i][j])
		{
			if (st->map[i][j] == '2' || st->map[i][j] == '3')
			{
				st->sprite[k].x = i + 0.5;
				st->sprite[k].y = j + 0.5;
				(st->map[i][j] == '2') ? st->sprite[k].texture = 6 : 0;
				(st->map[i][j] == '3') ? st->sprite[k].texture = 7 : 0;
				k++;
			}
			j++;
		}
		i++;
	}
	sprite_correct(st);
}
