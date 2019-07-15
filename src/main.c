/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 10:46:20 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_environment	env;

	if (ac < 2)
	{
		ft_putendl("Not Enough Arguments!");
		return (0);
	}
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"fdf");
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	handle_coords(ac, av, &env);
	
	t_vector v, vo;
	t_matrix mx,my,mz,mp,mt,wm;
	mx = matrix_rotate_x(45);
	my = matrix_rotate_y(1);
	mz = matrix_rotate_z(70);
	mp = matrix_projection(70, WINDOW_LENGTH/WINDOW_HEIGHT, 1, 100);
	mt = matrix_translate(0, 0, 4);
	wm = matrix_make_identity();
	wm = matrix_matrix_multiply(mz, mx);
	wm = matrix_matrix_multiply(wm, mt);
	FILL_VECTOR(vo, 0,0,0,1);
	int i = 0;
	while (i < env.map_data.coord_count)
	{
		FILL_VECTOR(v, env.coords[i].x ,env.coords[i].y ,env.coords[i].z,1);
		v = vector_multiply(v, 1);
		v = matrix_vector_multiply(v, wm);
		v = matrix_vector_multiply(v, mp);

		v = vector_divide(v, v.w);
		
		v = vector_add(v, vo);
		
		FILL_COORD(env.coords[i], v.x, v.y, v.z);
		env.coords[i] = ndc_to_screen_space(env.coords[i]);
		i++;
		
	}
	update_image(&env);
	
	
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
