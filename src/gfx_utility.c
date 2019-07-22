/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:13:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/22 11:35:55 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file contains any handy functions that can be used in a gfx project
*/

#include "../includes/fdf.h"

/*
**Set Starting size
*/

void		starting_scale(t_environment *env)
{
	if (ft_strcmp("cube", env->map_name) == 0)
		FILL_VECTOR(env->scale, 300, 300, 300, 1);
	else if (env->map_data.coord_count < 250)
		FILL_VECTOR(env->scale, 30, 30, 30, 1);
	else if (env->map_data.coord_count < 500)
		FILL_VECTOR(env->scale, 25, 25, 25, 1);
	else if (env->map_data.coord_count < 750)
		FILL_VECTOR(env->scale, 20, 20, 20, 1);
	else if (env->map_data.coord_count < 1500)
		FILL_VECTOR(env->scale, 15, 15, 10, 1);
	else if (env->map_data.coord_count < 50000)
		FILL_VECTOR(env->scale, 5, 5, 5, 1);
	else
		FILL_VECTOR(env->scale, 2, 2, 2, 1);
}

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

int			rgbtoi(int r, int g, int b)
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

void		apply_transforms(t_environment *env)
{
	t_matrix	mvp;
	t_matrix	model;
	t_matrix	scale_mat;
	t_matrix	trans_mat;
	int			i;

	if (env->clearer == 1)
		clear_image(&env->img, 0x000000);
	model = matrix_rotate(env->rotation);
	scale_mat = matrix_scale(env->scale);
	model = matrix_matrix_multiply(model, scale_mat);
	trans_mat = matrix_translate(env->translate);
	model = matrix_matrix_multiply(model, trans_mat);
	mvp = matrix_make_identity();
	mvp = matrix_matrix_multiply(mvp, model);
	i = 0;
	while (i < env->map_data.coord_count)
	{
		env->vectors[i] = matrix_vector_multiply(env->coords[i], mvp);
		env->vectors[i] = env->norm_world == 1 ?
		vector_normalise(env->vectors[i]) : env->vectors[i];
		env->vectors[i] = env->norm_world == 1 ?
		ndc_to_screen_space(env->vectors[i]) : env->vectors[i];
		i++;
	}
}

void		update_image(t_environment *env)
{
	apply_transforms(env);
	if (ft_strcmp("cube", env->map_name) != 0)
		draw_faces(env, env->rgb);
	else
		draw_cube(env, env->rgb);
	put_image(env, &env->img);
	put_text(env);
}
