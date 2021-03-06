/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/22 11:29:07 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_environment	env;

	if (ac == 2 && ft_strcmp("cube", av[1]) == 0)
		exec_cube(&env);
	else
		handle_coords(ac, av, &env);
	init_env(&env, av);
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	FILL_RGB(env.rgb, 255, 255, 255);
	FILL_VECTOR(env.rotation, 45, 0, 0, 1);
	starting_scale(&env);
	FILL_VECTOR(env.translate, WINDOW_LENGTH * 0.5,
	WINDOW_HEIGHT * 0.5, -9, 1);
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
