# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 14:29:08 by rvoltigo          #+#    #+#              #
#    Updated: 2021/01/16 14:29:10 by rvoltigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME   =	cub3D
FL     =	-Werror -Wextra -Wall -g
FLMLX  =	-framework OpenGL -framework AppKit
HEAD   =	inc/cub3d.h
LIBFT  =	libft/libft.a
MLXLIB =	mlx/libmlx.a
GNL    =	libft/gnl/*.c

SOURCES =	srcs/bmp.c \
		srcs/draw.c \
		srcs/floor_ceiling.c \
		srcs/free_allocated.c \
		srcs/ft_errors.c \
		srcs/ft_malloc.c \
		srcs/ft_sprites.c \
		srcs/ft_walls.c \
		srcs/ft_window.c \
		srcs/init_map.c \
		srcs/key_l.c \
		srcs/key_release.c \
		srcs/loads.c \
		srcs/navigation.c \
		srcs/parse.c \
		srcs/read_sprites.c \
		srcs/sort_sprites.c \
		srcs/start_app.c \
		srcs/struct_init.c \
		srcs/utils.c \

OBJ =	$(SOURCES:.c=.o)

RM = rm -f

$(NAME): $(OBJ) $(HEAD) $(LIBFT) $(MLXLIB)
	gcc cub3d.c $(OBJ) $(FLMLX) $(LIBFT) $(MLXLIB) -o $(NAME) $(GNL)

$(LIBFT): $(MLXLIB)
	@$(MAKE) -C libft
	@make bonus -C libft

$(MLXLIB):
	@$(MAKE) -C mlx

$(OBJ): %.o:%.c $(HEAD)
	gcc $(FL) -c $< -o $@

all:	$(NAME)

clean:
		$(RM) $(OBJ)
		@make clean -C libft
		@make clean -C mlx
		$(RM) *.bmp

fclean:	clean
		$(RM) $(NAME)
		@make fclean -C libft

re:		fclean all

.PHONY:		all clean fclean re
