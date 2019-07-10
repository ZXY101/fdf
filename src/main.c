/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/10 17:28:00 by stenner          ###   ########.fr       */
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
	////
	t_vector v;
	t_matrix mx,my,mz,mm, mp;
	mx = matrix_rotate_x(1);
	my = matrix_rotate_y(-1);
	mz = matrix_rotate_z(1);
	mm = matrix_matrix_multiply(mx,my);
	mp = matrix_projection(70, WINDOW_LENGTH/WINDOW_HEIGHT, 1, 100);
	(void)mx;
	(void)my;
	(void)mz;
	(void)mm;
	(void)mp;
	int i = 0;
	while (i < env.map_data.coord_count)
	{
		FILL_VECTOR(v, env.coords[i].x,env.coords[i].y,env.coords[i].z,1);
		v = vector_multiply(v, 1);
		v = matrix_vector_multiply(v, mx);
		v = matrix_vector_multiply(v, my);
		//v = matrix_vector_multiply(v, mz);
		//v = matrix_vector_multiply(v, mm);
		v = matrix_vector_multiply(v, mp);
		FILL_COORD(env.coords[i], v.x+200, v.y+300);
		i++;
	}
	i = 0;
	t_rgb rgb;
	FILL_RGB(rgb, 255,0,50);
		//pixel_put_image(&env.img, 0xffffff, env.coords[i].x, env.coords[i].y);
		draw_faces(&env, rgb);
		put_image(&env, &env.img);
	////
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
