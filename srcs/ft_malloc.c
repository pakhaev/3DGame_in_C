/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:48:01 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/12 18:48:02 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_sprmalloc(t_str *st)
{
	if (!(st->spr.num = (int*)malloc(sizeof(int) * st->numspr)))
		ft_error(-1, st);
	if (!(st->spr.dist = (float*)malloc(sizeof(float) * st->numspr)))
		ft_error(-1, st);
}

static void	ft_for_malloc2(t_str *st)
{
	int i;

	i = -1;
	if (!(st->texture = (int **)malloc(sizeof(int *) * st->count)))
		ft_error(-1, st);
	while (++i < st->count)
		if (!(st->texture[i] = (int *)malloc(sizeof(int) * (TH \
		* TW))))
			ft_error(-1, st);
	i = -1;
	while (++i < st->count)
		ft_bzero(st->texture[i], TH * TW);
	ft_sprmalloc(st);
}

void		ft_for_malloc(t_str *st)
{
	int i;

	i = -1;
	if (!(st->sprite = (t_sprite*)malloc(sizeof(t_sprite) \
	* st->numspr)))
		ft_error(-1, st);
	ft_sprites(st);
	if (!(st->buf = (int**)malloc(sizeof(int*) * st->winh)))
		ft_error(-1, st);
	while (++i < st->winh)
		if (!(st->buf[i] = (int*)malloc(st->winw * sizeof(int))))
			ft_error(-1, st);
	if (!(st->zbuffer = (float*)malloc(sizeof(float) * st->winw)))
		ft_error(-1, st);
	i = -1;
	while (++i < st->winh)
		ft_bzero(st->buf[i], st->winw);
	ft_for_malloc2(st);
}
