/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:26:45 by stenner           #+#    #+#             */
/*   Updated: 2019/07/11 10:16:38 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file includes all functions needed to draw a line between two points
*/

#include "../includes/fdf.h"

/*
**Line drawing algorithm for when m < 1
*/

static void	draw_line_lower(t_coord c1, t_coord c2, t_mlx_image *img, t_rgb rgb)
{
	int			i;
	t_line_math l;

	if (c1.x > c2.x)
		ft_swap(&c1, &c2, sizeof(t_coord));
	l.delta_x = c2.x - c1.x;
	l.delta_y = c2.y - c1.y;
	l.grad = l.delta_y / (double)l.delta_x;
	i = 0;
	while (i < l.delta_x)
	{
		l.q = ((c1.y + i * l.grad) - (int)(c1.y + i * l.grad));
		l.iq = 1 - l.q;
		pixel_put_image(img, rgbtoi(rgb.r * l.iq, rgb.g * l.iq, rgb.b * l.iq)
		, c1.x + i, c1.y + i * l.grad);
		pixel_put_image(img, rgbtoi(rgb.r * l.q, rgb.g * l.q, rgb.b * l.q)
		, c1.x + i, (c1.y + i * l.grad) + 1);
		i++;
	}
}

/*
**Line drawing algorithm for when m > 1
*/

static void	draw_line_upper(t_coord c1, t_coord c2, t_mlx_image *img, t_rgb rgb)
{
	int			i;
	t_line_math l;

	if (c1.y > c2.y)
		ft_swap(&c1, &c2, sizeof(t_coord));
	l.delta_x = c2.x - c1.x;
	l.delta_y = c2.y - c1.y;
	l.grad = l.delta_x / (double)l.delta_y;
	i = 0;
	while (i < l.delta_y)
	{
		l.q = ((c1.x + i * l.grad) - (int)(c1.x + i * l.grad));
		l.iq = 1 - l.q;
		pixel_put_image(img, rgbtoi(rgb.r * l.iq, rgb.g * l.iq, rgb.b * l.iq)
		, c1.x + i * l.grad, c1.y + i);
		pixel_put_image(img, rgbtoi(rgb.r * l.q, rgb.g * l.q, rgb.b * l.q),
		(c1.x + i * l.grad) + 1, c1.y + i);
		i++;
	}
}

/*
**Check to see which algorithm to use
*/

void		draw_line(t_coord c1, t_coord c2, t_mlx_image *img, t_rgb rgb)
{
	int			delta_x;
	int			delta_y;

	delta_x = c2.x - c1.x;
	delta_y = c2.y - c1.y;
	if (abs(delta_x) < abs(delta_y))
		draw_line_upper(c1, c2, img, rgb);
	else
		draw_line_lower(c1, c2, img, rgb);
}

void		draw_faces(t_environment *env, t_rgb rgb)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < env->map_data.coord_count)
	{
		if (j < env->map_data.x_coords)
			draw_line(env->coords[i], env->coords[i + 1], &env->img, rgb);
		else
			j = 0;
		i++;
		j++;
	}
	i = 0;
	while (i < env->map_data.coord_count - env->map_data.x_coords)
	{
		draw_line(env->coords[i], env->coords[i + env->map_data.x_coords],
			&env->img, rgb);
		i++;
	}
}
