/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/06/30 23:36:22 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <math.h>

int rgb(int r, int g, int b)
{
	int rgb;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;

	rgb = 65536 * r + 256 * g + b;
	return rgb;
}

struct Coord
{
		int x;
		int y;
};

int draw_line(struct Coord c1, struct Coord c2,	void *mlx_ptr, void *win_ptr)
{
	int deltaX;
	int deltaY;
	int i;
	int j;
	int e;

	deltaX = c2.x - c1.x;
	deltaY = c2.y - c1.y;
	j = c1.y;
	i = c1.x;
	if (deltaX < 0 && deltaY < 0)
		e = deltaY - deltaX;
	else
		e = deltaY / deltaY;
	while (i < c2.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, rgb(0,0,255));
		if (e > 0)
		{
			j++;
			e -= deltaX;
		}
		i++;
		e+= deltaY;
	}
	return (0);
}

int test(int key, void *param)
{
	(void)param;
	if (key == 0xff1b)
	{
		exit(0);
	}
	return (0);
}

int test2(int button, int x, int y, void *param)
{
	void **point = (void**)param;
	if (button == 1)
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
	struct Coord c1;
	struct Coord c2;
	c1.x = 10;
	c1.y = 10;
	c2.x = 100;
	c2.y = 10;
	draw_line(c1, c2, mlx_ptr, win_ptr);
	params[0] = mlx_ptr;
	params[1] = win_ptr;
	//mlx_string_put(mlx_ptr, win_ptr, 250, 300, rgb(255, 255, 0), "Hello World!");
	mlx_key_hook(win_ptr, test,(void *)0);
	mlx_mouse_hook (win_ptr, test2, (void *)params);
	mlx_loop(mlx_ptr);
	return (0);
}
