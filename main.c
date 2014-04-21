/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 11:46:14 by dsousa            #+#    #+#             */
/*   Updated: 2014/02/13 15:21:05 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "wolf_3d.h"
#include <time.h>

static int		expose_hook(t_env *e)
{
	if (!e->ray->x)
		ray_init(e->ray);
	ray_projection(e, e->ray);
	return (0);
}

static void		movement(int keycode, t_env *e)
{
	double		x;
	double		y;

	if (keycode == 65362)
	{
		x = e->ray->x - cos((M_PI * e->ray->dir) / 180) * 8;
		y = e->ray->y - sin((M_PI * e->ray->dir) / 180) * 8;
		if (e->ray->tbl[(int)(y / 64)][(int)(x / 64)] == 0)
		{
			e->ray->x = x;
			e->ray->y = y;
		}
	}
	else if (keycode == 65364)
	{
		x = e->ray->x + cos((M_PI * e->ray->dir) / 180) * 8;
		y = e->ray->y + sin((M_PI * e->ray->dir) / 180) * 8;
		if (e->ray->tbl[(int)(y / 64)][(int)(x / 64)] == 0)
		{
			e->ray->x = x;
			e->ray->y = y;
		}
	}
}

static int		key_hook(int keycode, t_env *e)
{
	if (!e->ray->x)
		ray_init(e->ray);
	if (keycode == 65307)
		exit(0);
	movement(keycode, e);
	if (keycode == 65361)
		e->ray->dir -= 19;
	if (keycode == 65363)
		e->ray->dir += 19;
	e->ray->dir = e->ray->dir >= 360 ? 0 : e->ray->dir;
	e->ray->dir = e->ray->dir < 0 ? e->ray->dir + 360 : e->ray->dir;
	ray_projection(e, e->ray);
	return (0);
}

int				main(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, SCREEN_X, SCREEN_Y, "Wolf_3D");
	mlx_do_key_autorepeaton(e.mlx);
	mlx_hook(e.win, 2, 1, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
