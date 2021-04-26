/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:33:28 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 16:33:45 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	subst(t_str *st, int *texture, char *path, t_img *img)
{
	int i;
	int j;

	i = -1;
	j = -1;
	img->img = mlx_xpm_file_to_image(st->mlx, path, &img->img_width, \
	&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, \
	&img->endian);
	while (++i < img->img_height)
	{
		j = -1;
		while (++j < img->img_width)
			texture[img->img_width * i + j] = img->data[img->img_width * i + j];
	}
	mlx_destroy_image(st->mlx, img->img);
}

void	load_texture(t_str *st)
{
	t_img	img;

	subst(st, st->texture[0], st->no, &img);
	subst(st, st->texture[1], st->so, &img);
	subst(st, st->texture[2], st->we, &img);
	subst(st, st->texture[3], st->ea, &img);
	subst(st, st->texture[4], st->f, &img);
	subst(st, st->texture[5], st->c, &img);
	subst(st, st->texture[6], st->s, &img);
	subst(st, st->texture[7], st->k, &img);
}
