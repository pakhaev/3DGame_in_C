/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:18:18 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 20:18:19 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void			ft_error(int x, t_str *st)
{
	(x == -1) ? ft_putstr("Error\ntrying to try memory!") : 0;
	(x == -2) ? ft_putstr("Error\ncan not open the file!") : 0;
	(x == -3) ? ft_putstr("Error\nMap extension is incorrect!") : 0;
	(x == -4) ? ft_putstr("Error\nInvalid number of arguments!") : 0;
	(x == -5) ? ft_putstr("Error\nFlags error!") : 0;
	(x == -6) ? ft_putstr("Error\nDuplicate flag!") : 0;
	(x == -7) ? ft_putstr("Error\nPlease, write '--save'") : 0;
	(x == -8) ? ft_putstr("Error\ncan't open the textures!") : 0;
	(x == -9) ? ft_putstr("Error\nDublicate player position!") : 0;
	(x == -10) ? ft_putstr("Error\ncan't creating mlx!") : 0;
	(x == -11) ? ft_putstr("Error\nNo player positions!") : 0;
	(x == -12) ? ft_putstr("Error\nInvalid texture extension!") : 0;
	(x == -13) ? ft_putstr("Error\ncalculating resolution!") : 0;
	(x == -14) ? ft_putstr("Error\nCan't create screenshot!") : 0;
	(x == -15) ? ft_putstr("Error\nMap error") : 0;
	(x == -16) ? ft_putstr("Error\nIndicate map!") : 0;
	(x == -17) ? ft_putstr("Error\nIndicate try arguments!") : 0;
	ft_free(st);
}

void			ft_parse_error(t_str *st)
{
	char *str;

	str = ".xpm";
	if (!st->no || !st->so || !st->we || !st->ea \
		|| !st->s || !st->f || !st->c || !st->k)
		ft_error(-5, st);
	xpm_correct(st->no, st, str, 1);
	xpm_correct(st->so, st, str, 1);
	xpm_correct(st->we, st, str, 1);
	xpm_correct(st->ea, st, str, 1);
	xpm_correct(st->s, st, str, 1);
	xpm_correct(st->f, st, str, 1);
	xpm_correct(st->c, st, str, 1);
	xpm_correct(st->k, st, str, 1);
	if ((open(st->no, O_RDONLY) == -1) || (open(st->so, O_RDONLY) == -1) \
		|| (open(st->we, O_RDONLY) == -1) || (open(st->ea, O_RDONLY) \
		== -1) || (open(st->s, O_RDONLY) == -1) || (open(st->f, O_RDONLY) \
		== -1) || (open(st->c, O_RDONLY) == -1) \
		|| (open(st->k, O_RDONLY) == -1))
		ft_error(-8, st);
	if (!st->winw && !st->winh)
		ft_error(-13, st);
}

static	void	check_symbols(t_str *st)
{
	st->i = -1;
	while (++st->i < st->heightm)
	{
		st->j = 0;
		while (st->map[st->i][st->j])
		{
			if (st->map[st->i][st->j] != '1' && st->map[st->i][st->j] != '2'\
			&& st->map[st->i][st->j] != '3' && st->map[st->i][st->j] != '0'\
			&& st->map[st->i][st->j] != ' ')
				ft_error(-15, st);
			st->j++;
		}
	}
}

void			check_close(t_str *st)
{
	ckeck_close_map(st->posx - 0.5, st->posy \
	- 0.5, st, st->heightm);
	st->i = -1;
	while (++st->i < st->heightm)
	{
		st->j = 0;
		while (st->map[st->i][st->j])
		{
			if (st->map[st->i][st->j] == 'Z')
				st->map[st->i][st->j] = '0';
			if (st->map[st->i][st->j] == 'M')
				st->map[st->i][st->j] = '2';
			if (st->map[st->i][st->j] == 'N')
				st->map[st->i][st->j] = '3';
			st->j++;
		}
	}
	check_symbols(st);
}

void			ckeck_close_map(int x, int y, t_str *st, int height)
{
	if (x > height - 1 || x < 0 || y > (int)(ft_strlen(st->map[x])) \
	- 1 || y < 0 || st->map[x][y] == ' ')
		ft_error(-15, st);
	if (st->map[x][y] == '1' || st->map[x][y] == 'Z' \
	|| st->map[x][y] == 'N' || st->map[x][y] == 'M')
		return ;
	if (st->map[x][y] != '1' && st->map[x][y] != '2' && \
	st->map[x][y] != '3' && st->map[x][y] != '0')
		ft_error(-15, st);
	if (st->map[x][y] == '0')
		st->map[x][y] = 'Z';
	if (st->map[x][y] == '2')
		st->map[x][y] = 'M';
	if (st->map[x][y] == '3')
		st->map[x][y] = 'N';
	ckeck_close_map(x + 1, y, st, height);
	ckeck_close_map(x + 1, y - 1, st, height);
	ckeck_close_map(x - 1, y, st, height);
	ckeck_close_map(x - 1, y - 1, st, height);
	ckeck_close_map(x, y + 1, st, height);
	ckeck_close_map(x, y - 1, st, height);
}
