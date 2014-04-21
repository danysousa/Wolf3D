/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:10:22 by dsousa            #+#    #+#             */
/*   Updated: 2014/01/19 15:33:31 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H
# define SCREEN_X 800
# define SCREEN_Y 500
# define CEILING 0x95CDFE
# define BEHIND 0xE0EBEB
# define LEFT 0xD75541
# define RIGHT 0xDADADA
# define FRONT 0xFDFAF7
# define FLOOR 0xA5C48A

typedef struct		s_counter
{
	double			x;
	double			x_old;
	double			y;
	double			y_old;
	int				success;
	int				tmp;
}					t_count;

typedef struct		s_ray
{
	double			x;
	double			y;
	double			dir;
	double			angle;
	double			coef;
	double			proj;
	int				color;
	int				tbl[16][13];
	t_count			tmp;
}					t_ray;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_ray			*ray;
}					t_env;

typedef struct		s_result
{
	double			x;
	double			y;
}					t_result;

void		ray_init(t_ray *ray);
void		tmp_init(t_count *count, int value);
double		rise_read(t_ray *ray, int dir);
double		decrease_read(t_ray *ray, int dir);
void		ray_projection(t_env *e, t_ray *ray);
void		print(int size, int pos_x, t_env *e);
void		creat_map(t_ray *ray);

#endif /* WOLF_3D_H */
