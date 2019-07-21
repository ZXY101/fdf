/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Shaun <Shaun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:46:03 by Shaun             #+#    #+#             */
/*   Updated: 2019/07/21 17:37:55 by Shaun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_cube(t_environment *env, t_rgb rgb)
{
	if (is_in_window(env->vectors, 0, 1))
		draw_line(env->vectors[0], env->vectors[1], &env->img, rgb);
	if (is_in_window(env->vectors, 1, 2))
		draw_line(env->vectors[1], env->vectors[2], &env->img, rgb);
	if (is_in_window(env->vectors, 2, 3))
		draw_line(env->vectors[2], env->vectors[3], &env->img, rgb);
	if (is_in_window(env->vectors, 3, 0))
		draw_line(env->vectors[3], env->vectors[0], &env->img, rgb);

	if (is_in_window(env->vectors, 4, 5))
		draw_line(env->vectors[4], env->vectors[5], &env->img, rgb);
	if (is_in_window(env->vectors, 5, 6))
		draw_line(env->vectors[5], env->vectors[6], &env->img, rgb);
	if (is_in_window(env->vectors, 6, 7))
		draw_line(env->vectors[6], env->vectors[7], &env->img, rgb);
	if (is_in_window(env->vectors, 7, 4))
		draw_line(env->vectors[7], env->vectors[4], &env->img, rgb);

	if (is_in_window(env->vectors, 0, 4))
		draw_line(env->vectors[0], env->vectors[4], &env->img, rgb);
	if (is_in_window(env->vectors, 1, 5))
		draw_line(env->vectors[1], env->vectors[5], &env->img, rgb);
	if (is_in_window(env->vectors, 2, 6))
		draw_line(env->vectors[2], env->vectors[6], &env->img, rgb);
	if (is_in_window(env->vectors, 3, 7))
		draw_line(env->vectors[3], env->vectors[7], &env->img, rgb);

}
void	exec_cube(t_environment *env)
{
	env->coords = malloc(sizeof(t_vector) * 8);
	env->vectors = malloc(sizeof(t_vector) * 8);
	FILL_VECTOR(env->coords[0], 0, 0, 0, 1);
	FILL_VECTOR(env->coords[1], 1, 0, 0, 1);
	FILL_VECTOR(env->coords[2], 1, 1, 0, 1);
	FILL_VECTOR(env->coords[3], 0, 1, 0, 1);

	FILL_VECTOR(env->coords[4], 0, 0, 1, 1);
	FILL_VECTOR(env->coords[5], 1, 0, 1, 1);
	FILL_VECTOR(env->coords[6], 1, 1, 1, 1);
	FILL_VECTOR(env->coords[7], 0, 1, 1, 1);

	env->map_data.coord_count = 8;
	env->map_data.x_coords = 0;
	env->map_data.y_coords = 0;
	// env->mlx_ptr = mlx_init();
	// env->win_ptr = mlx_new_window(env->mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	// "fdf");
	// init_image(env, &env->img, WINDOW_LENGTH, WINDOW_HEIGHT);
	// mlx_loop(env->mlx_ptr);
}
