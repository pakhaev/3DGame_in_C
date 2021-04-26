/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:34:16 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/01/09 16:35:53 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include "const.h"

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

typedef struct	s_fc
{
	float	rayx0;
	float	rayy0;
	float	rayx1;
	float	rayy1;
	int		p;
	float	posz;
	float	rdist;
	float	stepx;
	float	stepy;
	float	floorx;
	float	floory;
	int		cellx;
	int		celly;
	int		tx;
	int		ty;
	int		floortex;
	int		ceilingtex;
	int		color;
}				t_fc;

typedef struct	s_spr
{
	int		*num;
	float	*dist;
	float	sprx;
	float	spry;
	float	distce;
	float	trx;
	float	trry;
	int		scrnx;
	int		mscrnx;
	int		height;
	int		dstry;
	int		dendy;
	int		width;
	int		dstrx;
	int		dendx;
	int		tex;
	int		texy;
	int		color;
	int		d;
}				t_spr;

typedef	struct	s_bmp
{
	int			i;
	int			j;
	int			tmp;
	int			fd;
}				t_bmp;

typedef struct	s_rct
{
	float		cam;
	float		raydirx;
	float		raydiry;
	int			mpx;
	int			mpy;
	float		sdistx;
	float		sdisty;
	float		ddistx;
	float		ddisty;
	float		pwalld;
	float		step;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lheight;
	int			dstart;
	int			dend;
	int			tnum;
	float		xwall;
	int			texx;
	float		tpos;
	int			texy;
}				t_rct;

typedef	struct	s_str
{
	int			heightm;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		*f;
	char		*c;
	char		*k;
	long long	winw;
	long long	winh;
	char		*str;
	int			count;
	t_sprite	*sprite;
	int			numspr;
	t_fc		fc;
	t_spr		spr;
	t_bmp		bmp;
	t_rct		rct;
	char		**map;
	float		posx;
	float		posy;
	float		dirx;
	float		diry;
	float		planex;
	float		planey;
	void		*mlx;
	void		*win;
	int			key_a;
	int			key_left;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_right;
	int			key_esc;
	t_img		img;
	int			**buf;
	float		*zbuffer;
	int			**texture;
	int			save;
	int			i;
	int			j;
	int			x;
	int			n;
}				t_str;

typedef struct	s_pair
{
	float		first;
	int			second;
}				t_pair;

void			ft_navigation(t_str *st, char c);

void			ft_player_pos(t_str *st);

void			ft_sprites(t_str *st);

void			make_map(t_list **head, t_str *st);

void			parsing_map(char *av, t_str *st);

void			parsing_flags2(char *line, t_str *st);

void			parsing_flags(char *av, t_str *st);

void			sort_num(t_pair *num, int count);

void			sortspr(int *num, float *dist, int count);

void			draw(t_str *st);

int				start_app(t_str *st);

void			keys(t_str *st);

int				press_k(int key, t_str *st);

int				reset_k(int key, t_str *st);

void			load_texture(t_str *st);

void			subst(t_str *st, int *texture, char *path, t_img *img);

void			walls(t_str *st);

void			floor_ceiling(t_str *st);

void			ft_window(t_str st);

int				ft_free(t_str *st);

void			struct_init(t_str *st);

void			ft_error(int x, t_str *st);

void			ft_parse_error(t_str *st);

void			ft_read_spr(t_str *st);

void			correct_wh(t_str *st);

void			create_game_conf(t_str *st, char *str);

void			ft_for_malloc(t_str *st);

int				save_bmp(t_str *st);

void			ckeck_close_map(int x, int y, t_str *st, int height);

void			check_close(t_str *st);

void			ft_wall_casting(t_str *st);

int				xpm_correct(char *str, t_str *st, char *nstr, int fl);

char			*ft_convert(char *line, t_str *st, int j);

void			key_l(t_str *st);

int				ft_free_exit(t_str *st);

void			key_da(t_str *st);

void			ft_putstr(char *str);

#endif
