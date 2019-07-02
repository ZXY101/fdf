/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/02 13:04:31 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int test(int key, void *param)
{
	(void)param;
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}

int test2(int x, int y, t_environment *env)
{
	t_coord origin;
	t_coord dest;

	origin.x = 300;
	origin.y = 300;
	dest.x = x;
	dest.y = y;
	clear_image(&env->img, 0x00000000);
	draw_line(origin, dest, env);
	put_image(env, &env->img);
	return (0);
}

int finish(void *none)
{
	(void)none;
	exit(0);
}

// 4 Press
// 5 release
// 6 move

int		main(void)
{
	t_environment env;

	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, 600, 600, "Test");
	init_image(&env, &env.img, 600, 600);
	mlx_key_hook(env.win_ptr, test,(void *)0);
	mlx_hook(env.win_ptr, 6, 0L, test2, &env);
	mlx_hook(env.win_ptr, 17, 0L, finish, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
