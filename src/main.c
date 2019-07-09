/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/09 12:23:16 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


/* 

t_matrix	init_projection_matrix()
{
	double near = 0.1;
	double far = 1000;
	double fov = 90;
	double aspect_ratio = (double)WINDOW_HEIGHT/ WINDOW_LENGTH;
	double fov_rad = 1 / tan(fov * 0.5 / 180 * 3.14159);
	t_matrix m;
	int i;

	i = 0;
	while (i < 16)
		{
			m.matrix[i] = 0;
			i++;
		}
	m.matrix[0] = aspect_ratio * fov_rad;
	m.matrix[5] = fov_rad;
	m.matrix[10] = far / (far - near);
	m.matrix[11] = 1;
	m.matrix[14] = (-far * near) / (far - near);
	
	return (m);
}

t_matrix	init_rotatez_matrix()
{
	double theta = 1;
	t_matrix m;
	int i;

	i = 0;
	while (i < 16)
	{
		m.matrix[i] = 0;
		i++;
	}
	m.matrix[0] = cos(theta);
	m.matrix[1] = sin(theta);

	m.matrix[4] = -sin(theta);
	m.matrix[5] = cos(theta);

	m.matrix[9] = 1;

	m.matrix[15] = 1;
	
	return (m);
}

t_matrix	init_rotatex_matrix()
{
	static double theta = 1;
	t_matrix m;
	int i;

	i = 0;
	while (i < 16)
	{
		m.matrix[i] = 0;
		i++;
	}
	m.matrix[0] = 1;
	m.matrix[4] = cos(theta * 0.5);

	m.matrix[5] = sin(theta * 0.5);
	m.matrix[8] = -sin(theta) * 0.5;

	m.matrix[9] = cos(theta * 0.5);

	m.matrix[15] = 1;
	
	return (m);
} */
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
	handle_coords(ac, av, &env.coords, &env.map_data);
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
