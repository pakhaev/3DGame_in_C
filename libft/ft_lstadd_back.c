/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:29:32 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/10 17:37:36 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n_lst;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			n_lst = ft_lstlast(*(lst));
			n_lst->next = new;
		}
	}
}
