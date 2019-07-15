/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:01 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 11:34:22 by stenner          ###   ########.fr       */
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

	arrow_keys(key, env);
	if (key == 24)
	{
		t_vector v;

		int i = 0;
		while (i < env->map_data.coord_count)
		{
			FILL_VECTOR(v, env->coords[i].x ,env->coords[i].y,env->coords[i].z,1);
			v = vector_multiply(v, 1.1);
			FILL_COORD(env->coords[i], v.x, v.y, v.z);
			i++;
		}
		update_image(env);
	}
	if (key == 27)
	{
		t_vector v;

		int i = 0;
		while (i < env->map_data.coord_count)
		{
			FILL_VECTOR(v, env->coords[i].x ,env->coords[i].y,env->coords[i].z,1);
			v = vector_divide(v, 1.1);
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
