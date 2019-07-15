/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:13:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 18:27:33 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file contains any handy functions that can be used in a gfx project
*/

#include "../includes/fdf.h"

/*
**Function to convert Normalised Device Coordinates to screen space
*/

t_vector	ndc_to_screen_space(t_vector coord)
{
	t_vector ret;

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

void	apply_transforms(t_environment *env)
{
	t_matrix mvp;
	t_matrix model;
	t_matrix scale_mat;
	t_matrix trans_mat;

	int i;

	model = matrix_rotate(env->rotation);
	scale_mat = matrix_scale(env->scale);
	model = matrix_matrix_multiply(model, scale_mat);
	trans_mat = matrix_translate(env->translation);
	model = matrix_matrix_multiply(model, trans_mat);
	mvp = matrix_make_identity();
	mvp = matrix_matrix_multiply(mvp, model);
	// scale_mat = matrix_projection(90, WINDOW_LENGTH / (double)WINDOW_HEIGHT, 0.00001, 10000);
	// mvp = matrix_matrix_multiply(mvp, scale_mat);
	
	i = 0;
	while (i < env->map_data.coord_count)
	{
		env->vectors[i] = matrix_vector_multiply(env->coords[i], mvp);
		i++;
	}
}

void	update_image(t_environment *env)
{
	clear_image(&env->img, 0x000000);
	apply_transforms(env);
	draw_faces(env, env->rgb);
	put_image(env, &env->img);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 5,
	rgbtoi(env->rgb.r, env->rgb.g, env->rgb.b), env->map_name);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 30, 0xff0f0f, "R:");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 30, 0xff0f0f, ft_itoa(env->rgb.r));
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 50, 0x0fff0f, "G:");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 50, 0x0fff0f, ft_itoa(env->rgb.g));
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70, 0x0f0fff, "B:");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 70, 0x0f0fff, ft_itoa(env->rgb.b));

}

/*
**Move the 3D Model
*/

void	map_translate(t_environment *env, enum e_translate t)
{
/* 	t_vector	v;
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
	update_image(env); */
	(void)env;
	(void)t;
}
