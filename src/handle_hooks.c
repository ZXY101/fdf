/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:01 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 18:28:25 by stenner          ###   ########.fr       */
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
	//arrow_keys(key, env);
	env->keys[key] = 1;
	return (0);
}

int		key_release(int key, t_environment *env)
{
	env->keys[key] = 0;
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

int fun(t_environment *env)
{
	if (env->keys[0])
		env->rotation.y += 5;
	if (env->keys[2])
		env->rotation.y -= 5;
	if (env->keys[13])
		env->rotation.x += 5;
	if (env->keys[1])
		env->rotation.x -= 5;
	if (env->keys[14])
		env->rotation.z += 5;
	if (env->keys[12])
		env->rotation.z -= 5;

	if (env->keys[123])
		env->translation.x += 5;
	if (env->keys[124])
		env->translation.x -= 5;
	if (env->keys[126])
		env->translation.y += 5;
	if (env->keys[125])
		env->translation.y -= 5;


	if (env->keys[24])
	{
		env->scale = vector_multiply(env->scale, 1.1);
		env->scale.w = 1;
	}
	if (env->keys[27])
	{
		env->scale = vector_multiply(env->scale, 0.9);
		env->scale.w = 1;
	}
	env->rotation.y++;
	rgb_keys(env);
	update_image(env);
	return 0;
}

void	handle_hooks(void *win_ptr, t_environment *env)
{
	mlx_hook(win_ptr, 2, 0L, key_input, env);
	mlx_hook(win_ptr, 3, 0L, key_release, env);
	mlx_hook(win_ptr, 17, 0L, finish, env);
	mlx_loop_hook(env->mlx_ptr, fun, env);
}
