/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:59:53 by fguzman           #+#    #+#             */
/*   Updated: 2019/11/11 03:46:20 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_proj			get_scale_and_offset(t_coords parsed)
{
	int		scalex;
	int		scaley;
	t_proj	cool;

	scalex = 800 / parsed.size;
	scaley = 800 / parsed.height;
	cool.offset = 400;
	cool.scale = (scalex + scaley) / 2 / 2;
	cool.z = 0;
	cool.ud = 0;
	cool.lr = 0;
	return (cool);
}

unsigned int	a_value(int point)
{
	int				abs;
	unsigned int	pos;

	pos = point;
	abs = -1;
	if (point <= 0)
		pos = abs * point;
	return (pos);
}

void			proj_h(t_coords parsed, t_proj p, t_mlx *mlx)
{
	int x;
	int y;
	int	color;

	y = 0;
	while (y < parsed.height)
	{
		x = 0;
		while (x + 1 < parsed.size)
		{
			color = (parsed.rows[y][x] ==
			parsed.rows[y][x + 1]) ? 0xBB1ff0 : 0xaaffff;
			draw_line(do_iso(x, y, parsed.rows[y][x], p),
			do_iso(x + 1, y, parsed.rows[y][x + 1], p), mlx, color);
			x++;
		}
		y++;
	}
}

void			proj_v(t_coords parsed, t_proj p, t_mlx *mlx)
{
	int x;
	int y;
	int color;

	x = 0;
	while (x < parsed.size)
	{
		y = 0;
		while (y + 1 < parsed.height)
		{
			color = (parsed.rows[y][x] ==
			parsed.rows[y + 1][x]) ? 0xff8431 : 0xaaffff;
			draw_line(do_iso(x, y, parsed.rows[y][x], p),
			do_iso(x, y + 1, parsed.rows[y + 1][x], p), mlx, color);
			y++;
		}
		x++;
	}
}

int				main(int argc, char **argv)
{
	t_fdf fdf;

	fdf.mlx.init = mlx_init();
	fdf.mlx.win = mlx_new_window(fdf.mlx.init,
	WIN_HEIGHT, WIN_WIDTH, "Franco's FDF");
	fdf.coords = tdia(argv[1]);
	fdf.proj = get_scale_and_offset(fdf.coords);
	fdf.para = 0;
	if (argc == 2)
	{
		mlx_string_put(fdf.mlx.init, fdf.mlx.win, 225, 350, 0xffffff,
		"PRESS 1 TO START WITH ISOMETRIC OR 2 TO START WITH PARALELL");
		mlx_key_hook(fdf.mlx.win, keys, (void *)&fdf.mlx);
		mlx_loop(fdf.mlx.init);
	}
	return (0);
}
