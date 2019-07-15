/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:13:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 14:17:02 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file contains any handy functions that can be used in a gfx project
*/

#include "../includes/fdf.h"

/*
**Function to convert Normalised Device Coordinates to screen space
*/

t_coord	ndc_to_screen_space(t_coord coord)
{
	t_coord ret;

	ret = coord;
	ret.x /= 2;
	ret.y /= 2;
	ret.y *= -1;
	ret.x += 0.5;
	ret.y += 0.5;
	ret.x *= WINDOW_LENGTH;
	ret.y *= WINDOW_HEIGHT;
	return (ret);
}

/*
**Function to take 3 rgb values and returns a the colour integer
*/

int		rgbtoi(int r, int g, int b)
{
	int rgb;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	rgb = 0x010000 * r + 0x000100 * g + b;
	return (rgb);
}

/*
**Update the 3D model
*/

void	update_image(t_environment *env)
{
	t_rgb rgb;

	FILL_RGB(rgb, 0, 200, 255);
	clear_image(&env->img, 0x000000);
	draw_faces(env, rgb);
	put_image(env, &env->img);
}

/*
**Move the 3D Model
*/

void	map_translate(t_environment *env, enum e_translate t)
{
	t_vector	v;
	t_matrix	tm;
	int			i;

	i = 0;
	if (t == left)
		tm = matrix_translate(100, 0, 0);
	else if (t == right)
		tm = matrix_translate(-100, 0, 0);
	else if (t == up)
		tm = matrix_translate(0, 100, 0);
	else if (t == down)
		tm = matrix_translate(0, -100, 0);
	while (i < env->map_data.coord_count)
	{
		FILL_VECTOR(v, env->coords[i].x, env->coords[i].y, env->coords[i].z, 1);
		v = matrix_vector_multiply(v, tm);
		FILL_COORD(env->coords[i], v.x, v.y, v.z);
		i++;
	}
	update_image(env);
}
