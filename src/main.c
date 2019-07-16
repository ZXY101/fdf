/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 18:22:20 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_environment	env;

	handle_coords(ac, av, &env);
	env.map_name = av[1];
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"fdf");
	env.auto_rotate = 1;
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	FILL_RGB(env.rgb, 255, 255, 255);
	FILL_VECTOR(env.rotation, 45 ,0 ,0 ,1);
	FILL_VECTOR(env.scale, 10 ,10 ,10 ,1);
	FILL_VECTOR(env.translation, WINDOW_LENGTH * 0.5 ,WINDOW_HEIGHT * 0.5, -9 ,1);
	update_image(&env);
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
