/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:41:30 by fguzman           #+#    #+#             */
/*   Updated: 2019/11/11 03:45:26 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "libft.h"
# include "minilibx_macos/mlx.h"
# define WIN_WIDTH (1000)
# define WIN_HEIGHT (1000)

typedef struct	s_draw
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
}				t_draw;

typedef struct	s_mlx
{
	void *init;
	void *win;
	void *img;
}				t_mlx;

typedef struct	s_map
{
	int x;
	int y;
	int z;
	int xt;
	int yt;
	int color;
	int zcol;
}				t_map;

typedef struct	s_proj
{

	int offset;
	int scale;
	int z;
	int ud;
	int lr;
}				t_proj;

typedef struct	s_coords
{
	int height;
	int size;
	int *intarray;
	int **rows;

}				t_coords;

typedef	struct	s_fdf
{
	t_mlx		mlx;
	t_map		map;
	t_proj		proj;
	t_draw		draw;
	t_coords	coords;
	int			para;
}				t_fdf;

t_coords		tdia(char *argv);
void			proj_h(t_coords parsed, t_proj p, t_mlx *mlx);
void			proj_v(t_coords parsed, t_proj p, t_mlx *mlx);
int				keys(int key, t_fdf *fdf);
t_proj			get_scale_and_offset(t_coords parsed);
t_map			do_iso(int x, int y, int z, t_proj scaled);
void			proj_parah(t_coords parsed, t_proj p, t_mlx *mlx);
void			proj_parav(t_coords parsed, t_proj p, t_mlx *mlx);
t_map			do_para(int x, int y, int z, t_proj cool);
void			draw_line(t_map pa, t_map pb, t_mlx *mlx, int color);
void			para_udlr(int key, t_fdf *fdf);
void			para_projio(int key, t_fdf *fdf);
void			para_zoomio(int key, t_fdf *fdf);
int				keys2(int key, t_fdf *fdf);
void			reset_iso(t_fdf *fdf);
void			draw_line(t_map pa, t_map pb, t_mlx *mlx, int color);
int				keys2(int key, t_fdf *fdf);
unsigned int	a_value(int point);

#endif
