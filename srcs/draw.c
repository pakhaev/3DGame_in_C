/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:31:42 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 16:31:52 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw(t_str *st)
{
	st->i = -1;
	st->j = -1;
	while (++st->i < st->winh)
	{
		st->j = -1;
		while (++st->j < st->winw)
			st->img.data[st->i * st->winw + st->j] = st->buf[st->i][st->j];
	}
	mlx_put_image_to_window(st->mlx, st->win, st->img.img, 0, 0);
}
