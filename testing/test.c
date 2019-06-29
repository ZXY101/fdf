/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/06/29 16:14:59 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		mlx_pixel_put(point[0], point[1], x, y, 255);
	else
		mlx_pixel_put(point[0], point[1], x, y, 16711680);
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
	mlx_string_put(mlx_ptr, win_ptr, 300, 300, 16777215, "Hello World!");
	mlx_key_hook(win_ptr, test,(void *)0);
	mlx_mouse_hook (win_ptr, test2, (void *)params);
	mlx_loop(mlx_ptr);
	return (0);
}
