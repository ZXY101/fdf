/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/03 12:00:13 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(void)
{
	t_environment env;

	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"fdf");
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	//Handle Key Presses
	mlx_key_hook(env.win_ptr, key_input,(void *)0);
	//Quit Program When You Close The Window
	mlx_hook(env.win_ptr, 17, 0L, finish, &env);

	mlx_loop(env.mlx_ptr);
	return (0);
}