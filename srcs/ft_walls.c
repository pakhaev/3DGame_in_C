/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:08:08 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/19 13:08:10 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	wall_dist(t_str *st)
{
	if (st->rct.raydirx < 0)
	{
		st->rct.stepx = -1;
		st->rct.sdistx = (st->posx - st->rct.mpx) * st->rct.ddistx;
	}
	else
	{
		st->rct.stepx = 1;
		st->rct.sdistx = (st->rct.mpx + 1.0 - st->posx) * st->rct.ddistx;
	}
	if (st->rct.raydiry < 0)
	{
		st->rct.stepy = -1;
		st->rct.sdisty = (st->posy - st->rct.mpy) * st->rct.ddisty;
	}
	else
	{
		st->rct.stepy = 1;
		st->rct.sdisty = (st->rct.mpy + 1.0 - st->posy) * st->rct.ddisty;
	}
}

static	void	is_hit(t_str *st)
{
	while (st->rct.hit == 0)
	{
		if (st->rct.sdistx < st->rct.sdisty)
		{
			st->rct.sdistx += st->rct.ddistx;
			st->rct.mpx += st->rct.stepx;
			if (st->rct.raydirx < 0)
				st->rct.side = 0;
			else
				st->rct.side = 2;
		}
		else
		{
			st->rct.sdisty += st->rct.ddisty;
			st->rct.mpy += st->rct.stepy;
			if (st->rct.raydiry < 0)
				st->rct.side = 1;
			else
				st->rct.side = 3;
		}
		if (st->map[st->rct.mpx][st->rct.mpy] == '1')
			st->rct.hit = 1;
	}
}

static	void	calculate_walls(t_str *st)
{
	if (st->rct.side == 0 || st->rct.side == 2)
		st->rct.pwalld = (float)(st->rct.mpx - st->posx \
		+ (1 - st->rct.stepx) / 2) / st->rct.raydirx;
	else
		st->rct.pwalld = (double)(st->rct.mpy - st->posy \
		+ (1 - st->rct.stepy) / 2) / st->rct.raydiry;
	st->rct.lheight = (int)(st->winh / st->rct.pwalld);
	st->rct.dstart = -st->rct.lheight / 2 + st->winh / 2;
	(st->rct.dstart < 0) ? st->rct.dstart = 0 : 0;
	st->rct.dend = st->rct.lheight / 2 + st->winh / 2;
	(st->rct.dend >= st->winh) ? st->rct.dend = st->winh - 1 : 0;
	st->rct.tnum = st->map[st->rct.mpx][st->rct.mpy] - '0' - 1;
	if (st->rct.side == 0 || st->rct.side == 2)
		st->rct.xwall = st->posy + st->rct.pwalld * st->rct.raydiry;
	else
		st->rct.xwall = st->posx + st->rct.pwalld * st->rct.raydirx;
	st->rct.xwall -= floor((st->rct.xwall));
	st->rct.texx = (int)(st->rct.xwall * (float)TW);
	if ((st->rct.side == 0 || st->rct.side == 2) && st->rct.raydirx > 0)
		st->rct.texx = TW - st->rct.texx - 1;
	if ((st->rct.side == 1 || st->rct.side == 3) && st->rct.raydiry < 0)
		st->rct.texx = TW - st->rct.texx - 1;
}

static	void	walls_calc_text(t_str *st, int x)
{
	int y;

	y = 0;
	if ((st->rct.side == 0 || st->rct.side == 2) && st->rct.raydirx >= 0)
		st->rct.tnum = 1;
	else if ((st->rct.side == 0 || st->rct.side == 2) && st->rct.raydirx < 0)
		st->rct.tnum = 0;
	else if ((st->rct.side == 1 || st->rct.side == 3) && st->rct.raydiry < 0)
		st->rct.tnum = 2;
	else
		st->rct.tnum = 3;
	st->rct.step = 1.0 * TH / st->rct.lheight;
	st->rct.tpos = (st->rct.dstart - st->winh / 2 +\
	st->rct.lheight / 2) * st->rct.step;
	y = st->rct.dstart - 1;
	while (++y < st->rct.dend)
	{
		st->rct.texy = (int)st->rct.tpos & (TH - 1);
		st->rct.tpos += st->rct.step;
		st->buf[y][x] = st->texture[st->rct.tnum][TH *\
		st->rct.texy + st->rct.texx];
	}
	st->zbuffer[x] = st->rct.pwalld;
}

void			walls(t_str *st)
{
	int x;

	x = -1;
	floor_ceiling(st);
	while (++x < st->winw)
	{
		st->rct.cam = 2 * x / (float)st->winw - 1;
		st->rct.raydirx = st->dirx + st->planex * st->rct.cam;
		st->rct.raydiry = st->diry + st->planey * st->rct.cam;
		st->rct.mpx = (int)st->posx;
		st->rct.mpy = (int)st->posy;
		st->rct.ddistx = fabs(1 / st->rct.raydirx);
		st->rct.ddisty = fabs(1 / st->rct.raydiry);
		st->rct.hit = 0;
		wall_dist(st);
		is_hit(st);
		calculate_walls(st);
		walls_calc_text(st, x);
	}
	ft_read_spr(st);
}
