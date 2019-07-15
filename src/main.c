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
	env.map_name = ft_strsub(av[1],0 , ft_strlen(av[1]) - 4);
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"fdf");
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	FILL_RGB(env.rgb, 255, 255, 255);
	FILL_VECTOR(env.rotation, 45 ,0 ,0 ,1);
	FILL_VECTOR(env.scale, 10 ,10 ,10 ,1);
	FILL_VECTOR(env.translation, WINDOW_LENGTH * 0.5 ,WINDOW_HEIGHT * 0.5, -9 ,1);
	
	// t_vector v, vo;
	// t_matrix mx,my,mz,mp,mt,wm;
	// mx = matrix_rotate_x(60);
	// my = matrix_rotate_y(20);
	// mz = matrix_rotate_z(-30);
	// mp = matrix_projection(70, WINDOW_LENGTH/WINDOW_HEIGHT, 1, 100);
	// mt = matrix_translate(20, 250, 16);
	// wm = matrix_make_identity();
	// wm = matrix_matrix_multiply(my, mz);
	// wm = matrix_matrix_multiply(wm, mx);
	// wm = matrix_matrix_multiply(wm, mt);
	// FILL_VECTOR(vo, 0,0,0,1);
	// int i = 0;
	// while (i < env.map_data.coord_count)
	// {
	
	// 	FILL_VECTOR(v, env.coords[i].x ,env.coords[i].y ,env.coords[i].z,1);
	// 	v = vector_multiply(v, 50);
	// 	v = matrix_vector_multiply(v, wm);
	// 	v = matrix_vector_multiply(v, mp);
	// 	FILL_COORD(env.coords[i], v.x, v.y, v.z);
	// 	i++;
	// }
	update_image(&env);
	
	
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
