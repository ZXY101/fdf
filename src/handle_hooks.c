/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:01 by stenner           #+#    #+#             */
/*   Updated: 2019/07/12 13:21:00 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file has all of the functions that handle events
*/

#include "../includes/fdf.h"

/*
**Handle any key presses
*/

int		key_input(int key, t_environment *env)
{
	if (key == 53 || key == 0xff1b)
		exit(0);

	if (key == 123)
	{
		t_vector v, vo;
		t_matrix mt;
		mt = matrix_translate(100, 0, 0);
		FILL_VECTOR(vo, 1,1,0,1);
		
		int i = 0;
		while (i < env->map_data.coord_count)
		{
			FILL_VECTOR(v, env->coords[i].x ,env->coords[i].y,env->coords[i].z,1);
			v = matrix_vector_multiply(v, mt);
			 FILL_COORD(env->coords[i], v.x, v.y, v.z);

			i++;
		}

		update_image(env);
	}
	if (key == 124)
	{
		t_vector v, vo;
		t_matrix mt;
		mt = matrix_translate(-100, 0, 0);
		FILL_VECTOR(vo, 1,1,0,1);
		
		int i = 0;
		while (i < env->map_data.coord_count)
		{
			FILL_VECTOR(v, env->coords[i].x ,env->coords[i].y,env->coords[i].z,1);
			v = matrix_vector_multiply(v, mt);


		FILL_COORD(env->coords[i], v.x, v.y, v.z);

			i++;
		}
		update_image(env);
	}

	if (key == 125)
	{
		t_vector v, vo;
		t_matrix mt;
		mt = matrix_translate(0, -100, 0);
		FILL_VECTOR(vo, 1,1,0,1);
		
		int i = 0;
		while (i < env->map_data.coord_count)
		{
			FILL_VECTOR(v, env->coords[i].x ,env->coords[i].y,env->coords[i].z,1);
			v = matrix_vector_multiply(v, mt);
		FILL_COORD(env->coords[i], v.x, v.y, v.z);

			i++;
		}
		update_image(env);
	}
	if (key == 126)
	{
		t_vector v, vo;
		t_matrix mt;
		mt = matrix_translate(0, 100, 0);
		FILL_VECTOR(vo, 1,1,0,1);
		
		int i = 0;
		while (i < env->map_data.coord_count)
		{
			FILL_VECTOR(v, env->coords[i].x ,env->coords[i].y,env->coords[i].z,1);
			v = matrix_vector_multiply(v, mt);


		FILL_COORD(env->coords[i], v.x, v.y, v.z);

			i++;
		}
		update_image(env);
	}
	return (0);
}

/*
**Quit the program when the close button is clicked
*/

int		finish(void *none)
{
	(void)none;
	exit(0);
}

/*
**All of the hooks
*/

void	handle_hooks(void *win_ptr, t_environment *env)
{
	mlx_key_hook(win_ptr, key_input, env);
	mlx_hook(win_ptr, 17, 0L, finish, env);
}
