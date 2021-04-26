/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:27:10 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/19 12:27:11 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	bmpt(t_str *st)
{
	unsigned char	buf[14];

	st->bmp.i = 0;
	ft_bzero(buf, 14);
	buf[0] = (unsigned char)('B');
	buf[1] = (unsigned char)('M');
	st->bmp.tmp = 4 * (st->winw * st->winh) + 14 + 40;
	buf[2] = (unsigned char)(st->bmp.tmp % 256);
	buf[3] = (unsigned char)(st->bmp.tmp / 256 % 256);
	buf[4] = (unsigned char)(st->bmp.tmp / 256 / 256 % 256);
	buf[5] = (unsigned char)(st->bmp.tmp / 256 / 256 / 256);
	buf[10] = (unsigned char)(54);
	write(st->bmp.fd, buf, 14);
}

static void	bmpi(t_str *st)
{
	unsigned char	buf[40];

	st->bmp.i = 0;
	while (st->bmp.i < 40)
		buf[st->bmp.i++] = 0;
	buf[0] = (unsigned char)(40);
	buf[4] = (unsigned char)(st->winw % 256);
	buf[5] = (unsigned char)(st->winw / 256 % 256);
	buf[6] = (unsigned char)(st->winw / 256 / 256 % 256);
	buf[7] = (unsigned char)(st->winw / 256 / 256 / 256);
	buf[8] = (unsigned char)(st->winh % 256);
	buf[9] = (unsigned char)(st->winh / 256 % 256);
	buf[10] = (unsigned char)(st->winh / 256 / 256 % 256);
	buf[11] = (unsigned char)(st->winh / 256 / 256 / 256);
	buf[12] = (unsigned char)(1);
	buf[14] = (unsigned char)(32);
	write(st->bmp.fd, buf, 40);
}

static void	bmpd(t_str *st)
{
	unsigned char	buf[4];

	st->bmp.i = st->winh - 1;
	while (st->bmp.i >= 0)
	{
		st->bmp.j = -1;
		while (++st->bmp.j < st->winw)
		{
			st->bmp.tmp = st->img.data[st->bmp.j + st->bmp.i \
			* st->winw];
			buf[0] = (unsigned char)(st->bmp.tmp % 256);
			buf[1] = (unsigned char)(st->bmp.tmp / 256 % 256);
			buf[2] = (unsigned char)(st->bmp.tmp / 256 / 256);
			buf[3] = (unsigned char)(0);
			write(st->bmp.fd, buf, 4);
		}
		st->bmp.i--;
	}
}

int			save_bmp(t_str *st)
{
	if (!(st->bmp.fd = open("new_img.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0700)))
		ft_error(-14, st);
	bmpt(st);
	bmpi(st);
	bmpd(st);
	close(st->bmp.fd);
	ft_free(st);
	return (0);
}
