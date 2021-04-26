/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:47:02 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 19:47:03 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	free_arrays(t_str *st, int fl)
{
	int	i;
	int	k;

	k = 0;
	if (fl == 0)
		k = st->count;
	else if (fl == 1)
		k = st->heightm;
	i = 0;
	while (i < k)
	{
		(fl == 0 && st->texture[i]) ? free(st->texture[i]) : 0;
		(fl == 1 && st->map[i]) ? free(st->map[i]) : 0;
		i++;
	}
	(fl == 0 && st->texture) ? free(st->texture) : 0;
	(fl == 1 && st->map) ? free(st->map) : 0;
}

int				ft_free(t_str *st)
{
	(st->no) ? free(st->no) : 0;
	(st->so) ? free(st->so) : 0;
	(st->we) ? free(st->we) : 0;
	(st->ea) ? free(st->ea) : 0;
	(st->s) ? free(st->s) : 0;
	(st->f) ? free(st->f) : 0;
	(st->c) ? free(st->c) : 0;
	(st->k) ? free(st->k) : 0;
	exit(0);
	return (0);
}

int				ft_free_exit(t_str *st)
{
	(st->texture) ? free_arrays(st, 0) : 0;
	(st->map) ? free_arrays(st, 1) : 0;
	(st->no) ? free(st->no) : 0;
	(st->so) ? free(st->so) : 0;
	(st->we) ? free(st->we) : 0;
	(st->ea) ? free(st->ea) : 0;
	(st->s) ? free(st->s) : 0;
	(st->f) ? free(st->f) : 0;
	(st->c) ? free(st->c) : 0;
	(st->k) ? free(st->k) : 0;
	(st->sprite) ? free(st->sprite) : 0;
	(st->zbuffer) ? free(st->zbuffer) : 0;
	(st->spr.num) ? free(st->spr.num) : 0;
	(st->spr.dist) ? free(st->spr.dist) : 0;
	(st->img.img) ? free(st->img.img) : 0;
	exit(0);
	return (0);
}
