/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Shaun <Shaun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/21 13:10:27 by Shaun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_environment	env;

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
