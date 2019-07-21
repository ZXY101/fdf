/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key_release_down.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Shaun <Shaun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:23:42 by stenner           #+#    #+#             */
/*   Updated: 2019/07/21 12:54:53 by Shaun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_down(int key, t_environment *env)
{
	if (key == 53)
		exit(0);
	fun_bools(key, env);
	if (key == 7)
		env->rot_dirs[key] *= -1;
	if (key == 6)
		env->rot_dirs[key] *= -1;
	if (key == 16)
		env->rot_dirs[key] *= -1;
	if (key == 15)
		FILL_VECTOR(env->translate, WINDOW_LENGTH / 2, WINDOW_HEIGHT / 2, 0, 0);
	if (key == 82)
		FILL_RGB(env->rgb, 255, 255, 255);
	if (key == 65)
		FILL_RGB(env->rgb, 0, 0, 0);
	fixed_rotate(key, env);
	env->keys[key] = 1;
	return (0);
}

int		key_release(int key, t_environment *env)
{
	env->keys[key] = 0;
	return (0);
}

int		mouse_down(int key, int x, int y, t_environment *env)
{
	(void)x;
	(void)y;
	if (key == 4)
	{
		env->scale = vector_multiply(env->scale, 1.1);
		env->scale.w = 1;
	}
	if (key == 5)
	{
		env->scale = vector_multiply(env->scale, 0.9);
		env->scale.w = 1;
	}
	return (0);
}

int		mouse_release(int key, int x, int y, t_environment *env)
{
	(void)x;
	(void)y;
	env->buttons[key] = 0;
	return (0);
}
