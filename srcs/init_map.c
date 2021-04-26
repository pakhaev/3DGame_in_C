/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:27:36 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/15 20:40:24 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	player_pos(char c, t_str *st, int i, int j)
{
	if ((c == 'N' || c == 'E' || c == 'W' || c == 'S') && !st->posx)
	{
		ft_navigation(st, c);
		st->posx = (float)j + 0.5;
		st->posy = (float)i + 0.5;
	}
	else
		ft_error(-9, st);
}

char			*ft_convert(char *line, t_str *st, int j)
{
	int		i;
	int		c;
	char	*new;

	i = 0;
	c = ft_strlen(line) + 1;
	if (!(new = (char*)malloc(c * sizeof(char))))
		ft_error(-1, st);
	while (line[i])
	{
		if ((line[i] == 'N' || line[i] == 'E' || line[i] == 'W' \
		|| line[i] == 'S'))
		{
			player_pos(line[i], st, i, j);
			line[i] = '0';
		}
		new[i] = line[i];
		if (new[i] == '2' || new[i] == '3')
			st->numspr++;
		i++;
	}
	new[c - 1] = '\0';
	new[c] = '\0';
	return (new);
}

void			make_map(t_list **head, t_str *st)
{
	int		i;
	t_list	*tmp;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		st->map[i] = ft_convert(tmp->content, st, i);
		tmp = tmp->next;
		i++;
	}
}

void			parsing_map(char *av, t_str *st)
{
	int		fd;
	char	*line;

	if (!(fd = open(av, O_RDONLY)))
		ft_error(-2, st);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!(ft_strchr("RNSWEFCK", line[0])))
			st->heightm++;
		free(line);
	}
	free(line);
	st->heightm++;
	close(fd);
}

void			create_game_conf(t_str *st, char *str)
{
	xpm_correct(str, st, ".cub", 0);
	if (open(str, O_RDONLY) == -1)
		ft_error(-2, st);
	struct_init(st);
	if (!(st->mlx = mlx_init()))
		ft_error(-10, st);
	parsing_map(str, st);
	if (!(st->map = (char**)malloc((st->heightm + 1) * sizeof(char*))))
		ft_error(-1, st);
	parsing_flags(str, st);
	ft_parse_error(st);
	correct_wh(st);
	if (!st->posx || !st->posy)
		ft_error(-11, st);
	ft_for_malloc(st);
	load_texture(st);
	check_close(st);
	ft_window(*st);
}
