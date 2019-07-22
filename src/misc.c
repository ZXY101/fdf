/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:33:03 by Shaun             #+#    #+#             */
/*   Updated: 2019/07/22 11:36:35 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_env(t_environment *env, char **av)
{
	env->map_name = av[1];
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"fdf");
	env->colour_trip = -1;
	env->clearer = 1;
	env->auto_rotate = -1;
	env->norm_world = -1;
	env->auto_rotate_dir = 1;
	env->speed = 5;
	env->rot_dirs[16] = 1;
	env->rot_dirs[6] = -1;
	env->rot_dirs[7] = -1;
}

void	fun_bools(int key, t_environment *env)
{
	if (key == 45)
	{
		env->norm_world *= -1;
		if (env->norm_world == -1)
			FILL_VECTOR(env->translate, WINDOW_LENGTH / 2,
			WINDOW_HEIGHT / 2, 0, 0);
		else
			FILL_VECTOR(env->translate, -50, 100, 0, 0);
	}
	env->auto_rotate = key == 49 ? env->auto_rotate * -1 : env->auto_rotate;
	env->colour_trip = key == 36 ? env->colour_trip * -1 : env->colour_trip;
	env->clearer = key == 51 ? env->clearer * -1 : env->clearer;
	env->auto_rotate_dir = key == 78 ? 1 : env->auto_rotate_dir;
	env->auto_rotate_dir = key == 69 ? -1 : env->auto_rotate_dir;
}

void	put_text(t_environment *env)
{
	char *val1;
	char *val2;
	char *val3;

	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 5,
	rgbtoi(env->rgb.r, env->rgb.g, env->rgb.b), env->map_name);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 30, 0xff0f0f, "R:");
	val1 = ft_itoa(env->rgb.r);
	mlx_string_put(env->mlx_ptr, env->win_ptr,
	30, 30, 0xff0f0f, val1);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 50, 0x0fff0f, "G:");
	val2 = ft_itoa(env->rgb.g);
	mlx_string_put(env->mlx_ptr, env->win_ptr,
	30, 50, 0x0fff0f, val2);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70, 0x0f0fff, "B:");
	val3 = ft_itoa(env->rgb.b);
	mlx_string_put(env->mlx_ptr, env->win_ptr,
	30, 70, 0x0f0fff, val3);
	free(val1);
	free(val2);
	free(val3);
}
