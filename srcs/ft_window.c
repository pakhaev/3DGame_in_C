/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:42:38 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 19:42:41 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	correct_wh(t_str *st)
{
	if (st->winw == 0 || st->winh == 0)
		ft_error(-13, st);
	(st->winw > MAX_DISPLAY_W) ? st->winw = MAX_DISPLAY_W : 0;
	(st->winh > MAX_DISPLAY_H) ? st->winh = MAX_DISPLAY_H : 0;
	(st->winw < 0) ? st->winw = MAX_DISPLAY_W : 0;
	(st->winh < 0) ? st->winh = MAX_DISPLAY_H : 0;
}

void	ft_window(t_str st)
{
	st.win = mlx_new_window(st.mlx, st.winw, st.winh, \
	"Cub3D_rvoltigo");
	st.img.img = mlx_new_image(st.mlx, st.winw, st.winh);
	st.img.data = (int *)mlx_get_data_addr(st.img.img, &st.img.bpp, \
	&st.img.size_l, &st.img.endian);
	if (st.save)
	{
		start_app(&st);
		save_bmp(&st);
	}
	mlx_loop_hook(st.mlx, &start_app, &st);
	mlx_hook(st.win, 2, 0, &press_k, &st);
	mlx_hook(st.win, 3, 0, &reset_k, &st);
	mlx_hook(st.win, 17, 1L << 17, ft_free_exit, &st);
	mlx_loop(st.mlx);
}
