/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:31:09 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 16:31:27 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	sort_num(t_pair *num, int count)
{
	t_pair	sprites;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count - 1)
		{
			if (num[j].first > num[j + 1].first)
			{
				sprites.second = num[j].second;
				sprites.first = num[j].first;
				num[j].second = num[j + 1].second;
				num[j].first = num[j + 1].first;
				num[j + 1].second = sprites.second;
				num[j + 1].first = sprites.first;
			}
		}
	}
}

void	sortspr(int *num, float *dist, int count)
{
	t_pair	*sprites;
	int		i;

	i = -1;
	sprites = (t_pair*)malloc(sizeof(t_pair) * count);
	while (++i < count)
	{
		sprites[i].second = num[i];
		sprites[i].first = dist[i];
	}
	sort_num(sprites, count);
	i = -1;
	while (++i < count)
	{
		num[i] = sprites[count - i - 1].second;
		dist[i] = sprites[count - i - 1].first;
	}
	free(sprites);
}
