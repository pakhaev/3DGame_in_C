/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:32:46 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 16:33:18 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	key_cont(t_str *st)
{
	if (st->key_w)
	{
		if (st->map[(int)(st->posx + st->dirx * MVSPEED)]\
			[(int)(st->posy)] == '0')
			st->posx += st->dirx * MVSPEED;
		if (st->map[(int)(st->posx)][(int)(st->posy + st->diry \
			* MVSPEED)] == '0')
			st->posy += st->diry * MVSPEED;
	}
	if (st->key_s)
	{
		if (st->map[(int)(st->posx - st->dirx * MVSPEED)]\
			[(int)(st->posy)] == '0')
			st->posx -= st->dirx * MVSPEED;
		if (st->map[(int)(st->posx)][(int)(st->posy - st->diry \
			* MVSPEED)] == '0')
			st->posy -= st->diry * MVSPEED;
	}
}

void			key_da(t_str *st)
{
	if (st->key_a)
	{
		if (st->map[(int)(st->posx - st->planex * MVSPEED)]\
			[(int)(st->posy)] == '0')
			st->posx -= st->planex * MVSPEED;
		if (st->map[(int)(st->posx)][(int)(st->posy - st->planey \
			* MVSPEED)] == '0')
			st->posy -= st->planey * MVSPEED;
	}
	if (st->key_d)
	{
		if (st->map[(int)(st->posx + st->planex * MVSPEED)]\
			[(int)(st->posy)] == '0')
			st->posx += st->planex * MVSPEED;
		if (st->map[(int)(st->posx)][(int)(st->posy + st->planey \
			* MVSPEED)] == '0')
			st->posy += st->planey * MVSPEED;
	}
	(st->key_esc) ? exit(0) : 0;
	key_cont(st);
}

void			keys(t_str *st)
{
	double olddirx;
	double oldplanex;

	if (st->key_right)
	{
		olddirx = st->dirx;
		st->dirx = st->dirx * cos(-RTSPEED) - st->diry *\
		sin(-RTSPEED);
		st->diry = olddirx * sin(-RTSPEED) + st->diry *\
		cos(-RTSPEED);
		oldplanex = st->planex;
		st->planex = st->planex * cos(-RTSPEED) - st->planey \
		* sin(-RTSPEED);
		st->planey = oldplanex * sin(-RTSPEED) + st->planey \
		* cos(-RTSPEED);
	}
	key_l(st);
}

int				press_k(int key, t_str *st)
{
	if (key == K_ESC)
		ft_free_exit(st);
	else if (key == K_W)
		st->key_w = 1;
	else if (key == K_LEFT)
		st->key_left = 1;
	else if (key == K_S)
		st->key_s = 1;
	else if (key == K_RIGHT)
		st->key_right = 1;
	else if (key == K_A)
		st->key_a = 1;
	else if (key == K_D)
		st->key_d = 1;
	return (0);
}

int				reset_k(int key, t_str *st)
{
	if (key == K_W)
		st->key_w = 0;
	else if (key == K_LEFT)
		st->key_left = 0;
	else if (key == K_S)
		st->key_s = 0;
	else if (key == K_RIGHT)
		st->key_right = 0;
	else if (key == K_A)
		st->key_a = 0;
	else if (key == K_D)
		st->key_d = 0;
	else if (key == K_ESC)
		ft_free_exit(st);
	return (0);
}
