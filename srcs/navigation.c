/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:26:21 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 16:26:40 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_navigation(t_str *st, char c)
{
	if (c == 'W' || c == 'E')
	{
		st->dirx = 0;
		st->diry = (c == 'W') ? -1 : 1;
		st->planex = (c == 'W') ? -0.66 : 0.66;
		st->planey = 0;
	}
	if (c == 'N' || c == 'S')
	{
		st->dirx = (c == 'N') ? -1 : 1;
		st->diry = 0;
		st->planex = 0;
		st->planey = (c == 'N') ? 0.66 : -0.66;
	}
}
