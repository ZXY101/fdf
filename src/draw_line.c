/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Shaun <Shaun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:26:45 by stenner           #+#    #+#             */
/*   Updated: 2019/07/21 16:42:44 by Shaun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file includes all functions needed to draw a line between two points
*/

#include "../includes/fdf.h"

/*
**Line drawing algorithm for when m < 1
*/

static void	draw_line_lower(t_vector c1, t_vector c2, t_mlx_image *img, t_rgb c)
{
	int			i;
	t_line_math l;

	if (c1.x > c2.x)
		ft_swap(&c1, &c2, sizeof(t_vector));
	l.delta_x = c2.x - c1.x;
	l.delta_y = c2.y - c1.y;
	l.grad = l.delta_y / (double)l.delta_x;
	i = 0;
	while (i < l.delta_x)
	{
		l.q = ((c1.y + i * l.grad) - (int)(c1.y + i * l.grad));
		l.iq = 1 - l.q;
		pixel_put_image(img, rgbtoi(c.r * l.iq, c.g * l.iq, c.b * l.iq)
		, c1.x + i, c1.y + i * l.grad);
		pixel_put_image(img, rgbtoi(c.r * l.q, c.g * l.q, c.b * l.q)
		, c1.x + i, (c1.y + i * l.grad) + 1);
		i++;
	}
}

/*
**Line drawing algorithm for when m > 1
*/

static void	draw_line_upper(t_vector c1, t_vector c2, t_mlx_image *img, t_rgb c)
{
	int			i;
	t_line_math l;

	if (c1.y > c2.y)
		ft_swap(&c1, &c2, sizeof(t_vector));
	l.delta_x = c2.x - c1.x;
	l.delta_y = c2.y - c1.y;
	l.grad = l.delta_x / (double)l.delta_y;
	i = 0;
	while (i < l.delta_y)
	{
		l.q = ((c1.x + i * l.grad) - (int)(c1.x + i * l.grad));
		l.iq = 1 - l.q;
		pixel_put_image(img, rgbtoi(c.r * l.iq, c.g * l.iq, c.b * l.iq)
		, c1.x + i * l.grad, c1.y + i);
		pixel_put_image(img, rgbtoi(c.r * l.q, c.g * l.q, c.b * l.q),
		(c1.x + i * l.grad) + 1, c1.y + i);
		i++;
	}
}

/*
**Check to see which algorithm to use
*/

void		draw_line(t_vector c1, t_vector c2, t_mlx_image *img, t_rgb rgb)
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

int			is_in_window(t_vector *coords, int i, int j)
{
	int ret;

	ret = (coords[i].x > 0 && coords[i].x < WINDOW_LENGTH &&
	coords[i].y > 0 && coords[i].y < WINDOW_HEIGHT) ||
	(coords[j].x > 0 && coords[j].x < WINDOW_LENGTH &&
	coords[j].y > 0 && coords[j].y < WINDOW_HEIGHT)
	? 1 : 0;
	return (ret);
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
		{
			if (is_in_window(env->vectors, i, i + 1))
				draw_line(env->vectors[i], env->vectors[i + 1], &env->img, rgb);
		}
		else
			j = 0;
		i++;
		j++;
	}
	i = 0;
	while (i < env->map_data.coord_count - env->map_data.x_coords)
	{
		if (is_in_window(env->vectors, i, i + env->map_data.x_coords) == 1)
			draw_line(env->vectors[i], env->vectors[i + env->map_data.x_coords],
			&env->img, rgb);
		i++;
	}
}
