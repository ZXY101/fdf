/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/02 12:25:22 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include "../src/draw_line.c"
#include <stdio.h>
/*
void pixel_put_image(t_mlx_image *img, int colour, int x, int y)
{
	int *data;

	if (x >= img->width || x < 0)
		return;
	if (y >= img->height || y < 0)
		return;
	data = (int*)&img->raw_data[x * 4 + y * img->size_line];

	*data = colour;
}

void clear_image(t_mlx_image *img, int colour)
{
	int *data = (int*)img->raw_data;
	int i;

	i = 0;
	while (i < (img->width * img->height))
	{
		data[i] = colour;
		i++;
	}
}

void init_image(t_environment *env, t_mlx_image *img, int width, int height)
{
	img->img_ptr = mlx_new_image(env->mlx_ptr, width, height);
	img->raw_data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
	&img->endian);
	img->width = width;
	img->height = height;
	img->pos.x = 0;
	img->pos.y = 0;
	printf("bbp: %d\nwidth: %d\nheight: %d\nsize_line: %d\nendian: %d\nx: %d\ny: %d\n",
	img->bpp,img->width,img->height,img->size_line,img->endian,img->pos.x,img->pos.y);
	clear_image(img, 0x000000ff);
}

void put_image(t_environment *env, t_mlx_image *img)
{
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, img->img_ptr,
	img->pos.x, img->pos.y);
}
*/
int test(int key, void *param)
{
	(void)param;
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}

int test2(int x, int y, t_environment *env)
{
	t_coord origin;
	t_coord dest;

	origin.x = 300;
	origin.y = 300;
	dest.x = x;
	dest.y = y;
	clear_image(&env->img, 0x00000000);
	draw_line(origin, dest, env);
	put_image(env, &env->img);
	return (0);
}

int finish(void *none)
{
	(void)none;
	exit(0);
}

// 4 Press
// 5 release
// 6 move

int		main(void)
{
	t_environment env;

	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, 600, 600, "Test");
	init_image(&env, &env.img, 600, 600);
	mlx_key_hook(env.win_ptr, test,(void *)0);
	mlx_hook(env.win_ptr, 6, 0L, test2, &env);
	mlx_hook(env.win_ptr, 17, 0L, finish, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
