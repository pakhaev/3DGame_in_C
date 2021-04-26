/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:49:32 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/15 20:49:33 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	main(int ac, char **av)
{
	t_str	st;

	if (ac == 3)
	{
		if (!(ft_strncmp(av[2], "--save", 7)))
		{
			st.save = 1;
			create_game_conf(&st, av[1]);
		}
		else
			ft_error(-7, &st);
	}
	else if (ac == 1)
		ft_error(-16, &st);
	else if (ac == 2)
		create_game_conf(&st, av[1]);
	else
		ft_error(-17, &st);
	return (0);
}
