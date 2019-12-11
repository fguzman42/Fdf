/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 01:57:48 by fguzman           #+#    #+#             */
/*   Updated: 2019/11/10 01:57:50 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	para_zoomio(int key, t_fdf *fdf)
{
	if (key == 6)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.scale += 1;
		proj_parah(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_parav(fdf->coords, fdf->proj, fdf->mlx.init);
	}
	else if (key == 7)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.scale -= 1;
		proj_parah(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_parav(fdf->coords, fdf->proj, fdf->mlx.init);
	}
}

void	para_projio(int key, t_fdf *fdf)
{
	if (key == 34)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.z += 1;
		proj_parah(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_parav(fdf->coords, fdf->proj, fdf->mlx.init);
	}
	else if (key == 31)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.z -= 1;
		proj_parah(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_parav(fdf->coords, fdf->proj, fdf->mlx.init);
	}
}

void	reset_iso(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
	fdf->proj = get_scale_and_offset(fdf->coords);
	proj_h(fdf->coords, fdf->proj, fdf->mlx.init);
	proj_v(fdf->coords, fdf->proj, fdf->mlx.init);
}

void	para_udlr(int key, t_fdf *fdf)
{
	if (key == 123 || key == 124)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.lr += 10 * (key == 123 ? -1 : 1);
		proj_parah(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_parav(fdf->coords, fdf->proj, fdf->mlx.init);
	}
	if (key == 125 || key == 126)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj.ud += 10 * (key == 125 ? 1 : -1);
		proj_parah(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_parav(fdf->coords, fdf->proj, fdf->mlx.init);
	}
}

int		keys2(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx.init, fdf->mlx.win);
		exit(0);
	}
	if (key == 6 || key == 7)
		para_zoomio(key, fdf);
	if (key >= 123 && key <= 126)
		para_udlr(key, fdf);
	if (key == 15)
	{
		mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
		fdf->proj = get_scale_and_offset(fdf->coords);
		proj_parah(fdf->coords, fdf->proj, fdf->mlx.init);
		proj_parav(fdf->coords, fdf->proj, fdf->mlx.init);
	}
	if (key == 34 || key == 31)
		para_projio(key, fdf);
	if (key == 18)
		return (1);
	return (0);
}
