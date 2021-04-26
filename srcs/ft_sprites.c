/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:46:45 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 21:46:47 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	spr_calculate(t_str *st, int i)
{
	st->spr.sprx = st->sprite[st->spr.num[i]].x - st->posx;
	st->spr.spry = st->sprite[st->spr.num[i]].y - st->posy;
	st->spr.distce = 1.0 / (st->planex * st->diry - st->dirx * st->planey);
	st->spr.trx = st->spr.distce * (st->diry * st->spr.sprx - st->dirx \
	* st->spr.spry);
	st->spr.trry = st->spr.distce * (-st->planey * st->spr.sprx + st->planex \
	* st->spr.spry);
	st->spr.scrnx = (int)((st->winw / 2) * (1 + st->spr.trx \
	/ st->spr.trry));
	st->spr.mscrnx = (int)(0.0 / st->spr.trry);
	st->spr.height = (int)fabs((st->winh / st->spr.trry) / 1);
	st->spr.dstry = -st->spr.height / 2 + st->winh / 2 + st->spr.mscrnx;
}

static	void	spr_conditions(t_str *st)
{
	if (st->spr.dstry < 0)
		st->spr.dstry = 0;
	st->spr.dendy = (st->spr.height / 2) + (st->winh / 2) + st->spr.mscrnx;
	if (st->spr.dendy >= st->winh)
		st->spr.dendy = st->winh - 1;
	st->spr.width = (int)fabs((st->winh / st->spr.trry) / 1);
	st->spr.dstrx = -st->spr.width / 2 + st->spr.scrnx;
	if (st->spr.dstrx < 0)
		st->spr.dstrx = 0;
	st->spr.dendx = st->spr.width / 2 + st->spr.scrnx;
	if (st->spr.dendx >= st->winw)
		st->spr.dendx = st->winw - 1;
}

static	void	spr_tex(t_str *st, int i)
{
	int j;
	int k;

	k = 0;
	j = st->spr.dstrx - 1;
	while (++j < st->spr.dendx)
	{
		st->spr.tex = (int)((256 * (j - (-st->spr.width / 2 + st->spr.scrnx))\
		* TW / st->spr.width) / 256);
		if (st->spr.trry > 0 && j > 0 && j < st->winw && st->spr.trry <\
		st->zbuffer[j])
		{
			k = st->spr.dstry - 1;
			while (++k < st->spr.dendy)
			{
				st->spr.d = (k - st->spr.mscrnx) * 256 - st->winh \
				* 128 + st->spr.height * 128;
				st->spr.texy = ((st->spr.d * TH) / st->spr.height) / 256;
				st->spr.color = st->texture[st->sprite[st->spr.num[i]].\
				texture][TW * st->spr.texy + st->spr.tex];
				if ((st->spr.color & 0x00FFFFFF) != 0)
					st->buf[k][j] = st->spr.color;
			}
		}
	}
}

void			ft_read_spr(t_str *st)
{
	int i;
	int j;

	i = 0;
	j = 0;
	i = -1;
	while (++i < st->numspr)
	{
		st->spr.num[i] = i;
		st->spr.dist[i] = ((st->posx - st->sprite[i].x) *\
		(st->posx - st->sprite[i].x) + (st->posy - st->sprite[i].y) \
		* (st->posy - st->sprite[i].y));
	}
	sortspr(st->spr.num, st->spr.dist, st->numspr);
	i = -1;
	while (++i < st->numspr)
	{
		spr_calculate(st, i);
		spr_conditions(st);
		spr_tex(st, i);
	}
}
