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

typedef struct s_vector
{
	double x;
	double y;
	double z;
	double w;
} 				t_vector;

typedef struct s_matrix
{
	double matrix[16];
}				t_matrix;

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
	double fov = 200;
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

t_matrix	init_rotate_matrix()
{
	double theta = 0.5;
	t_matrix m;
	
	m.matrix[0] = cos(theta);
	m.matrix[1] = sin(theta);
	m.matrix[2] = 0;
	m.matrix[3] = 0;

	m.matrix[4] = -sin(theta);
	m.matrix[5] = cos(theta);
	m.matrix[6] = 0;
	m.matrix[7] = 0;

	m.matrix[8] = 0;
	m.matrix[9] = 1;
	m.matrix[10] = 0;
	m.matrix[11] = 0;

	m.matrix[12] = 0;
	m.matrix[13] = 0;
	m.matrix[14] = 0;
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
	t_matrix projection_matrix, rotation_matrix;
	projection_matrix = init_projection_matrix();
	rotation_matrix = init_rotate_matrix();

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
		vector = vector_multiply(vector, rotation_matrix);

		coords[i].x = -vector.x/2;
		coords[i].y = vector.y/2;

		coords[i] = ndc_to_screen_space(coords[i]);
		pixel_put_image(&env.img, rgbtoi(500 - i , 50, i), coords[i].x, coords[i].y);
	//	mlx_string_put(env.mlx_ptr, env.win_ptr, coords[i].x, coords[i].y, 0xffffff, ft_itoa(i));
		i++;
	}
	////////////////////

	handle_hooks(env.win_ptr, &env);

	put_image(&env, &env.img);

	mlx_loop(env.mlx_ptr);
	return (0);
}
