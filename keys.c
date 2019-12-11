/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:36:12 by fguzman           #+#    #+#             */
/*   Updated: 2019/11/13 01:03:17 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoomio(int key, t_fdf *fdf)
{
	if (key == 6)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.scale += 1;
		proj_h(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_v(fdf->coords, fdf->proj, fdf->mlx.init);
	}
	else if (key == 7)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.scale -= 1;
		proj_h(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_v(fdf->coords, fdf->proj, fdf->mlx.init);
	}
}

void		projio(int key, t_fdf *fdf)
{
	if (key == 34)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.z += 1;
		proj_h(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_v(fdf->coords, fdf->proj, fdf->mlx.init);
	}
	else if (key == 31)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.z -= 1;
		proj_h(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_v(fdf->coords, fdf->proj, fdf->mlx.init);
	}
}

void		udlr(int key, t_fdf *fdf)
{
	if (key == 123 || key == 124)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.lr += 10 * (key == 123 ? -1 : 1);
		proj_h(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_v(fdf->coords, fdf->proj, fdf->mlx.init);
	}
	if (key == 125 || key == 126)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.ud += 10 * (key == 125 ? 1 : -1);
		proj_h(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_v(fdf->coords, fdf->proj, fdf->mlx.init);
	}
}

void		handle_proj(int key, t_fdf *fdf)
{
	if (key == 18)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj = get_scale_and_offset(fdf->coords);
		proj_h(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_v(fdf->coords, fdf->proj, fdf->mlx.init);
		fdf->para = 1;
	}
	if (key == 19)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj = get_scale_and_offset(fdf->coords);
		proj_parah(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_parav(fdf->coords, fdf->proj, fdf->mlx.init);
		fdf->para = 2;
	}
}

int			keys(int key, t_fdf *fdf)
{
	if (fdf->para == 0)
		handle_proj(key, fdf);
	if (fdf->para == 2)
		keys2(key, fdf);
	if (key == 53 && fdf->para == 1)
	{
		mlx_destroy_window(fdf->mlx.init, fdf->mlx.win);
		exit(0);
	}
	if ((key >= 6 && key <= 7) && fdf->para == 1)
		zoomio(key, fdf);
	if ((key == 34 || key == 31) && fdf->para == 1)
		projio(key, fdf);
	if (key >= 123 && key <= 126 && fdf->para == 1)
		udlr(key, fdf);
	if (key == 15 && fdf->para == 1)
		reset_iso(fdf);
	if (key >= 18 && key <= 19)
		handle_proj(key, fdf);
	return (0);
}
