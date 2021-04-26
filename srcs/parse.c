/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:30:11 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 16:30:33 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	char	*ft_parse(char *line, t_str *st)
{
	char	*nstr;

	while (*line == 'N' || *line == 'O' || *line == 'S' || *line == 'W' \
		|| *line == 'E' || *line == 'A' || *line == ' ' || *line == 'F' \
		|| *line == 'C' || *line == 'K')
		line++;
	st->count++;
	if (!(nstr = ft_strdup(line)))
		ft_error(-1, st);
	return (nstr);
}

static	int		parse_num(t_str *st, int fl)
{
	int	num;

	num = 0;
	while (*st->str == 'R' || *st->str == ' ' || *st->str == ',')
		st->str++;
	if (fl == 0)
	{
		while (*st->str >= '0' && *st->str <= '9')
		{
			num = num * 10 + (*st->str - '0');
			st->str++;
		}
	}
	else
	{
		if (st->winw && st->winh && *st->str >= '0' && *st->str <= '9')
			return (-1);
	}
	return (num);
}

static	void	parssing_flags3(char *line, t_str *st)
{
	if (line[0] == 'E' && line[1] == 'A' && st->ea)
		ft_error(-6, st);
	else if (line[0] == 'E' && line[1] == 'A' && !st->ea)
		st->ea = ft_parse(line, st);
	if (line[0] == 'S' && line[1] == ' ' && st->s)
		ft_error(-6, st);
	else if (line[0] == 'S' && line[1] == ' ' && !st->s)
		st->s = ft_parse(line, st);
	if (line[0] == 'K' && line[1] == ' ' && st->k)
		ft_error(-6, st);
	else if (line[0] == 'K' && line[1] == ' ' && !st->k)
		st->k = ft_parse(line, st);
	if (line[0] == 'F' && st->f)
		ft_error(-6, st);
	else if (line[0] == 'F' && !st->f)
		st->f = ft_parse(line, st);
	if (line[0] == 'C' && st->c)
		ft_error(-6, st);
	else if (line[0] == 'C' && !st->c)
		st->c = ft_parse(line, st);
}

void			parsing_flags2(char *line, t_str *st)
{
	if (line[0] == 'R' && (st->winw || st->winh))
		ft_error(-6, st);
	else if (line[0] == 'R' && (!st->winw && !st->winh))
	{
		st->winw = parse_num(st, 0);
		st->winh = parse_num(st, 0);
		if (parse_num(st, 1) == -1)
			ft_error(-13, st);
	}
	if (line[0] == 'N' && line[1] == 'O' && st->no)
		ft_error(-6, st);
	else if (line[0] == 'N' && line[1] == 'O' && !st->no)
		st->no = ft_parse(line, st);
	if (line[0] == 'S' && line[1] == 'O' && st->so)
		ft_error(-6, st);
	else if (line[0] == 'S' && line[1] == 'O' && !st->so)
		st->so = ft_parse(line, st);
	if (line[0] == 'W' && line[1] == 'E' && st->we)
		ft_error(-6, st);
	else if (line[0] == 'W' && line[1] == 'E' && !st->we)
		st->we = ft_parse(line, st);
	parssing_flags3(line, st);
}

void			parsing_flags(char *av, t_str *st)
{
	int		fd;
	char	*line;
	int		i;

	(!(fd = open(av, O_RDONLY))) ? ft_error(-2, st) : 0;
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strchr("RNSWEFCK", line[0]))
		{
			st->str = line;
			parsing_flags2(line, st);
			(st->count == 8 && st->n == 1) ? ft_error(-15, st) : 0;
		}
		else
		{
			st->n = 1;
			st->map[i] = ft_convert(line, st, i);
			i++;
		}
		free(line);
	}
	st->map[i] = ft_convert(line, st, i);
	free(line);
	close(fd);
}
