/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:23:02 by dsousa            #+#    #+#             */
/*   Updated: 2014/01/19 15:20:16 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "wolf_3d.h"

static void		rise_loop(t_ray *ray, int dir, t_result *r)
{
	ray->tmp.y = ray->coef * (ray->x + ray->tmp.x + 1);
	ray->tmp.y -= (ray->x * ray->coef - ray->y);
	while (ray->tmp.y_old >= ray->tmp.y && ray->tmp.success == 0)
	{
		r->y = ray->tmp.y_old;
		r->x = (ray->tmp.x + ray->x);
		if (ray->tbl[(int)(r->y / 64)][(int)(r->x / 64)] == 1)
			ray->tmp.success = 1;
		ray->tmp.y_old--;
	}
	ray->tmp.y_old = ray->tmp.success == 1 ? ray->tmp.y_old : ray->tmp.y;
	ray->tmp.x += (double)dir;
}

double			rise_read(t_ray *ray, int dir)
{
	t_result	r;
	double		dist;

	tmp_init(&ray->tmp, 0);
	ray->tmp.y_old = ray->y;
	while (ray->tmp.success != 1)
		rise_loop(ray, dir, &r);
	if ((int)r.x % 64 == 0)
		ray->color = FRONT;
	else if ((dir < 0 && ((int)r.x % 64 > 62)))
		ray->color = BEHIND;
	else
		ray->color = LEFT;
	r.x = (ray->tmp.x) * (ray->tmp.x);
	r.y = (ray->y - (ray->tmp.y_old)) * (ray->y - (ray->tmp.y_old));
	dist = sqrt(r.x + r.y);
	return (dist);
}

static void		decrease_loop(t_ray *ray, int dir, t_result *r)
{
	ray->tmp.y = ray->coef * (ray->x + ray->tmp.x + 1);
	ray->tmp.y -= (ray->x * ray->coef - ray->y);
	while (ray->tmp.y_old <= ray->tmp.y && ray->tmp.success == 0)
	{
		r->y = ray->tmp.y_old;
		r->x = (ray->tmp.x + ray->x);
		if (ray->tbl[(int)(r->y / 64)][(int)(r->x / 64)] != 0)
			ray->tmp.success = 1;
		ray->tmp.y_old++;
	}
	r->y = ray->tmp.y_old - 1;
	r->x = (ray->tmp.x + ray->x);
	if (ray->tbl[(int)(r->y / 64)][(int)(r->x / 64)] != 0
		&& ray->tmp.y_old != ray->y)
		ray->tmp.success = 1;
	ray->tmp.y_old = ray->tmp.success == 1 ? ray->tmp.y_old : ray->tmp.y;
	ray->tmp.x += (double)dir;
}

double			decrease_read(t_ray *ray, int dir)
{
	double		dist;
	t_result	r;

	tmp_init(&ray->tmp, 0);
	ray->tmp.y_old = ray->y;
	while (ray->tmp.success != 1)
		decrease_loop(ray, dir, &r);
	if ((int)r.y % 64 == 0 && (int)r.x % 64 < 62)
		ray->color = RIGHT;
	else if ((int)r.x % 64 > 62)
		ray->color = BEHIND;
	else
		ray->color = FRONT;
	r.x = (ray->tmp.x) * (ray->tmp.x);
	r.y = (ray->y - (ray->tmp.y_old)) * (ray->y - (ray->tmp.y_old));
	dist = sqrt(r.x + r.y);
	return (dist);
}
