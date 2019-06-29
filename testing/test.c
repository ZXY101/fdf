/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/06/29 16:38:13 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int rgb(int r, int g, int b)
{
	int rgb;

	rgb = 65536 * r + 256 * g + b;
	return rgb;
}

int test(int key, void *param)
{
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}

int test2(int button, int x, int y, void *param)
{
	void **point = (void**)param;
	if (button == 1)
		//mlx_string_put(point[0],point[1], x, y, 255);
		mlx_string_put(point[0], point[1], x, y, 2672885, "A");
	else if (button == 2)
		mlx_string_put(point[0], point[1], x, y, 16711680, "B");
	else if (button == 3)
		mlx_string_put(point[0], point[1], x, y, 65280, "C");
	else
		mlx_pixel_put(point[0], point[1], x, y, 16777215);
	return (0);
}

int		main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	void *params[2];

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 600, "Test");
	params[0] = mlx_ptr;
	params[1] = win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, 250, 300, rgb(255, 255, 0), "Hello World!");
	mlx_key_hook(win_ptr, test,(void *)0);
	mlx_mouse_hook (win_ptr, test2, (void *)params);
	mlx_loop(mlx_ptr);
	return (0);
}
