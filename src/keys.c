/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:32:08 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 14:29:56 by stenner          ###   ########.fr       */
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
