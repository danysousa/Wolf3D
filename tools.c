/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:33:05 by dsousa            #+#    #+#             */
/*   Updated: 2014/01/19 14:42:30 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf_3d.h"
#include <stdlib.h>

void		tmp_init(t_count *count, int value)
{
	count->x = (double)value;
	count->x_old = (double)value;
	count->y = (double)value;
	count->y_old = (double)value;
	count->success = value;
}

void		creat_map(t_ray *ray)
{
	int		x;
	int		y;

	x = 0;
	while (x < 16)
	{
		y = 0;
		while (y < 13)
		{
			if (x == 0 || x == 13 - 1 || y == 0 || y == 16 - 1
				|| (y == 7 && x != 5) || (x == 4 && y > 9))
				ray->tbl[x][y] = 1;
			else
				ray->tbl[x][y] = 0;
			y++;
		}
		x++;
	}
}

void		ray_init(t_ray *ray)
{
	ray->x = 2 * 64 + 10;
	ray->y = 4 * 64 + 32;
	ray->dir = 180;
	ray->angle = ray->dir - 30;
	ray->proj = (SCREEN_X / 2) * (1 / tan((M_PI * 30 /180)));
	creat_map(ray);
}
