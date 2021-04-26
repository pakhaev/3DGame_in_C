/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:13:57 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 20:13:58 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	struct_init(t_str *st)
{
	st->posx = 0.0;
	st->posy = 0.0;
	st->numspr = 0;
	st->count = 0;
	st->key_a = 0;
	st->key_w = 0;
	st->key_s = 0;
	st->key_d = 0;
	st->key_left = 0;
	st->key_right = 0;
	st->key_esc = 0;
	st->n = 0;
}
