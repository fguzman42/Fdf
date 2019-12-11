/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:38:54 by fguzman           #+#    #+#             */
/*   Updated: 2019/11/09 22:27:57 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	do_iso(int x, int y, int z, t_proj cool)
{
	t_map	grid;
	int		prev_x;
	int		prev_y;

	x *= cool.scale;
	y *= cool.scale;
	z *= cool.scale + cool.z;
	prev_x = x;
	prev_y = y;
	grid.xt = (prev_x - prev_y) * cos(0.523599);
	grid.yt = -z + (prev_x + prev_y) * sin(0.523599);
	grid.yt += cool.offset + cool.ud;
	grid.xt += cool.offset + cool.lr;
	return (grid);
}

t_map	do_para(int x, int y, int z, t_proj cool)
{
	t_map	grid;
	int		prev_x;
	int		prev_y;

	x *= cool.scale;
	y *= cool.scale;
	z *= cool.scale + cool.z;
	prev_x = x - 150;
	prev_y = y - 75;
	grid.xt = (x - 150) + z;
	grid.yt = (y - 75) + z;
	grid.yt += cool.offset + cool.ud;
	grid.xt += cool.offset + cool.lr;
	return (grid);
}

void	proj_parav(t_coords parsed, t_proj p, t_mlx *mlx)
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
			color = (parsed.rows[y][x] == parsed.rows[y + 1][x])
			? 0xFF8615 : 0xFF787A;
			draw_line(do_para(x, y, parsed.rows[y][x], p),
			do_para(x, y + 1, parsed.rows[y + 1][x], p), mlx, color);
			y++;
		}
		x++;
	}
}

void	proj_parah(t_coords parsed, t_proj p, t_mlx *mlx)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < parsed.height)
	{
		x = 0;
		while (x + 1 < parsed.size)
		{
			color = (parsed.rows[y][x] == parsed.rows[y][x + 1])
			? 0xFFFF15 : 0xFF787A;
			draw_line(do_para(x, y, parsed.rows[y][x], p),
			do_para(x + 1, y, parsed.rows[y][x + 1], p), mlx, color);
			x++;
		}
		y++;
	}
}

void	draw_line(t_map pa, t_map pb, t_mlx *mlx, int color)
{
	t_draw	bres;

	bres.dx = a_value(pa.xt - pb.xt);
	bres.sx = (pa.xt < pb.xt) ? 1 : -1;
	bres.dy = a_value(pa.yt - pb.yt);
	bres.sy = (pa.yt < pb.yt) ? 1 : -1;
	bres.err = (bres.dx > bres.dy ? bres.dx : -bres.dy) / 2;
	while (1)
	{
		mlx_pixel_put(mlx->init, mlx->win, pa.xt, pa.yt, color);
		if (pa.xt == pb.xt && pa.yt == pb.yt)
			break ;
		bres.e2 = bres.err;
		if (bres.e2 > -bres.dx)
		{
			bres.err -= bres.dy;
			pa.xt += bres.sx;
		}
		if (bres.e2 < bres.dy)
		{
			bres.err += bres.dx;
			pa.yt += bres.sy;
		}
	}
}
