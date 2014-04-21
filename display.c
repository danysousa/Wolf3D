/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 11:22:27 by dsousa            #+#    #+#             */
/*   Updated: 2014/01/18 14:17:31 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf_3d.h"

void	print(int size, int pos_x, t_env *e)
{
	int		y;

	y = 0;
	while (y <= ((SCREEN_Y - size) / 2))
		mlx_pixel_put(e->mlx, e->win, pos_x, y++, CEILING);
	while (y <= (SCREEN_Y + size) / 2)
		mlx_pixel_put(e->mlx, e->win, pos_x, y++, e->ray->color);
	while (y <= SCREEN_Y)
		mlx_pixel_put(e->mlx, e->win, pos_x, y++, FLOOR);
}
