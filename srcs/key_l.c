/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:27:12 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/15 20:27:33 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void		key_l(t_str *st)
{
	double olddirx;
	double oldplanex;

	if (st->key_left)
	{
		olddirx = st->dirx;
		st->dirx = st->dirx * cos(RTSPEED) - st->diry \
		* sin(RTSPEED);
		st->diry = olddirx * sin(RTSPEED) + st->diry \
		* cos(RTSPEED);
		oldplanex = st->planex;
		st->planex = st->planex * cos(RTSPEED) - st->planey \
		* sin(RTSPEED);
		st->planey = oldplanex * sin(RTSPEED) + st->planey \
		* cos(RTSPEED);
	}
	key_da(st);
}
