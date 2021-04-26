/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:57:31 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 16:57:40 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	fc_width(t_str *st, int y)
{
	st->j = 0;
	while (st->j < st->winw)
	{
		st->fc.cellx = (int)(st->fc.floorx);
		st->fc.celly = (int)(st->fc.floory);
		st->fc.tx = (int)(TW * (st->fc.floorx - st->fc.cellx)) & (TW - 1);
		st->fc.ty = (int)(TH * (st->fc.floory - st->fc.celly)) & (TH - 1);
		st->fc.floorx += st->fc.stepx;
		st->fc.floory += st->fc.stepy;
		st->fc.floortex = 4;
		st->fc.ceilingtex = 5;
		st->fc.color = st->texture[st->fc.floortex][TW * st->fc.ty \
		+ st->fc.tx];
		st->fc.color = (st->fc.color >> 1) & 8355711;
		st->buf[y][st->j] = st->fc.color;
		st->fc.color = st->texture[st->fc.ceilingtex][TW * st->fc.ty \
		+ st->fc.tx];
		st->fc.color = (st->fc.color >> 1) & 8355711;
		st->buf[st->winh - y - 1][st->j] = st->fc.color;
		st->j++;
	}
}

void		floor_ceiling(t_str *st)
{
	st->i = st->winh / 2 + 1;
	while (st->i < st->winh)
	{
		st->fc.rayx0 = st->dirx - st->planex;
		st->fc.rayy0 = st->diry - st->planey;
		st->fc.rayx1 = st->dirx + st->planex;
		st->fc.rayy1 = st->diry + st->planey;
		st->fc.p = st->i - st->winh / 2;
		st->fc.posz = 0.5 * st->winh;
		st->fc.rdist = st->fc.posz / st->fc.p;
		st->fc.stepx = st->fc.rdist * (st->fc.rayx1 - st->fc.rayx0) \
		/ st->winw;
		st->fc.stepy = st->fc.rdist * (st->fc.rayy1 - st->fc.rayy0) \
		/ st->winw;
		st->fc.floorx = st->posx + st->fc.rdist * st->fc.rayx0;
		st->fc.floory = st->posy + st->fc.rdist * st->fc.rayy0;
		fc_width(st, st->i);
		st->i++;
	}
}
