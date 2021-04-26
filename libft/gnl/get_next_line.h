/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:49:40 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/21 17:34:34 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 30

# include <unistd.h>
# include <stdlib.h>

size_t		ft_gnlen(char *str, int f);
char		*ft_gnldup(char *str);
char		*ft_gnljoin(char *s1, char *s2);
int			ft_returning(char *s);
int			get_next_line(int fd, char **line);
char		*ft_strgnldup(char *str);

#endif
