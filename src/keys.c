/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:32:08 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 18:06:23 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define ZOOM 1.1

void	zoom(int key, t_environment *env)
{
	t_vector	v;
	int			i;

	i = 0;
	while (i < env->map_data.coord_count)
	{
		FILL_VECTOR(v, env->coords[i].x, env->coords[i].y, env->coords[i].z, 1);
		if (key == 24)
			v = vector_multiply(v, ZOOM);
		else if (key == 27)
			v = vector_divide(v, ZOOM);
		FILL_COORD(env->coords[i], v.x, v.y, v.z);
		i++;
	}
	update_image(env);
}

void	arrow_keys(int key, t_environment *env)
{
	enum e_translate t;

	if (key == 123)
	{
		t = left;
		map_translate(env, t);
	}
	if (key == 124)
	{
		t = right;
		map_translate(env, t);
	}
	if (key == 125)
	{
		t = down;
		map_translate(env, t);
	}
	if (key == 126)
	{
		t = up;
		map_translate(env, t);
	}
}

void	rgb_keys(t_environment *env)
{
	if (env->keys[83] && env->rgb.r < 255)
		env->rgb.r = env->rgb.r + 15;
	if (env->keys[84] && env->rgb.g < 255)
		env->rgb.g= env->rgb.g + 15;
	if (env->keys[85] && env->rgb.b < 255)
		env->rgb.b = env->rgb.b + 15;
	if (env->keys[86] && env->rgb.r > 0)
		env->rgb.r = env->rgb.r - 15;
	if (env->keys[87] && env->rgb.g > 0)
		env->rgb.g= env->rgb.g - 15;
	if (env->keys[88] && env->rgb.b > 0)
		env->rgb.b = env->rgb.b - 15;
}
