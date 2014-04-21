/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:09:51 by dsousa            #+#    #+#             */
/*   Updated: 2014/01/19 15:20:27 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf_3d.h"

void		ray_projection(t_env *e, t_ray *ray)
{
	int			x;

	x = 0;
	ray->angle = ray->dir - 30 < 0 ? ray->dir + 330 : ray->dir - 30;
	while (x < SCREEN_X)
	{
		ray->coef = tan((M_PI * ray->angle) / 180);
		if (ray->angle < 90)
			print((int)((ray->proj * 64) / rise_read(ray, -1)), x, e);
		else if (ray->angle >= 90 && ray->angle < 180)
			print((int)((ray->proj * 64) / rise_read(ray, 1)), x, e);
		else if (ray->angle >= 180 && ray->angle < 270)
			print((int)((ray->proj * 64) / decrease_read(ray, 1)), x, e);
		else if (ray->angle >= 270)
			print((int)((ray->proj * 64) / decrease_read(ray, -1)), x, e);
		ray->angle = ray->angle + 0.075 >= 360 ? ray->angle - 360 : ray->angle;
		ray->angle += 0.075;
		while ((ray->angle < 92 && ray->angle > 88)
			|| (ray->angle < 272 && ray->angle > 268))
			ray->angle++;
		x++;
	}
}
