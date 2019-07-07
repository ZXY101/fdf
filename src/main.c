/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/05 17:20:57 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define FILL_VECTOR(V, X, Y, Z, W) V.x = X, V.y = Y, V.z = Z, V.w = W

t_vector vector_multiply(t_vector vector, t_matrix m)
{
	t_vector ret;

	ret.x = vector.x * m.matrix[0] + vector.y * m.matrix[4] + vector.z * m.matrix[8] + m.matrix[12];
	ret.y = vector.x * m.matrix[1] + vector.y * m.matrix[5] + vector.z * m.matrix[9] + m.matrix[13];
	ret.z = vector.x * m.matrix[2] + vector.y * m.matrix[6] + vector.z * m.matrix[10] + m.matrix[14];
	ret.w = vector.x * m.matrix[3] + vector.y * m.matrix[7] + vector.z * m.matrix[11] + m.matrix[15];
	if (ret.w != 0)
	{
		ret.x /= ret.w;
		ret.y /= ret.w;
		ret.z /= ret.w;
	}
	return (ret);
}

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
}
int		main(int ac, char **av)
{
	t_environment	env;
	t_coord		*coords;
	t_map_data	map_data;

	if (ac < 2)
	{
		ft_putendl("Not Enough Arguments!");
		return (0);
	}
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"fdf");
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	handle_coords(ac, av, &coords, &map_data);

	/////////////////
	t_matrix projection_matrix, rotation_matrixz, rotation_matrixx;
	projection_matrix = init_projection_matrix();
	rotation_matrixz = init_rotatez_matrix();
	rotation_matrixx = init_rotatex_matrix();

	t_vector vector;
	////////////////
	int i = 0;
	t_rgb rgb,rgb2;
	FILL_RGB(rgb,255,0,255);
	FILL_RGB(rgb2,0,255,255);
	(void)rgb;
	(void)rgb2;
	///////////////////
	while (i < map_data.coord_count)
	{
		FILL_VECTOR(vector, coords[i].x, coords[i].y, coords[i].z + 3, 1);
		vector = vector_multiply(vector, projection_matrix);
		vector = vector_multiply(vector, rotation_matrixz);
		vector = vector_multiply(vector, rotation_matrixx);

		coords[i].x = -vector.x/2 ;
		coords[i].y = vector.y/2 ;
	

		coords[i] = ndc_to_screen_space(coords[i]);
		i++;
	}
	i = 0;
	int x = 1;
	int y = 1;
	while (i < map_data.coord_count)
	{
		if(x != map_data.x_coords)
			draw_line(coords[i], coords[i + 1], &env.img, rgb2);
		else
		{
			x = 0;
			y++;
		}
		if (y != map_data.y_coords && i+ 1 != map_data.coord_count)
			draw_line(coords[i], coords[i + map_data.x_coords], &env.img, rgb2);
		if (y != map_data.y_coords &&x != map_data.x_coords)
			draw_line(coords[i + 1], coords[i + map_data.x_coords], &env.img, rgb2);
		
		pixel_put_image(&env.img, rgbtoi(255,0,0), coords[i].x, coords[i].y);
		i++;
		x++;
	}
	////////////////////
	handle_hooks(env.win_ptr, &env);

	put_image(&env, &env.img);

	mlx_loop(env.mlx_ptr);
	return (0);
}
