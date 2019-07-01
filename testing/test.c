/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/01 16:59:31 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

int rgb(int r, int g, int b)
{
	int rgb;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	rgb = 0x010000 * r + 0x000100 * g + b;
	return rgb;
}

typedef struct	s_coord
{
		int x;
		int y;
}				t_coord;

typedef struct 	s_mlx_image
{
	void *img_ptr;
	int bpp;
	int size_line;
	int endian;
	char *raw_data;
	int width;
	int height;
	t_coord pos;
} 				t_mlx_image;

typedef struct s_environment
{
	void *mlx_ptr;
	void *win_ptr;
	t_mlx_image img;
} 				t_environment;

void pixel_put_image(t_mlx_image *img, int colour, int x, int y)
{
	int *data;

	if (x > img->width)
		x = img->width;
	if (y > img->height)
		y = img->height;
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

int draw_line_lower(t_coord c1, t_coord c2, t_environment *env)
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
	e = deltaY - deltaX;
	while (i < c2.x)
	{
		//mlx_pixel_put(env->mlx_ptr, env->win_ptr, i, j, rgb(255,0,255));
		pixel_put_image(&env->img, 0xff00ff, i, j);
		if (e > 0)
		{
			j++;
			e -= deltaX;
		}
		i++;
		e+= deltaY;
	}
	mlx_string_put(env->mlx_ptr, env->win_ptr, 400, 200, rgb(255, 0,255), ft_itoa(deltaY));
	return (0);
}

int draw_line_upper(t_coord c1, t_coord c2, t_environment *env)
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
	e = deltaY - deltaX;
	while (j < c2.y)
	{
		//mlx_pixel_put(env->mlx_ptr, env->win_ptr, i, j, rgb(0,255,255));
		pixel_put_image(&env->img, 0x00ffff, i, j);
		if (e > 0)
		{
			i++;
			e -= deltaY;
		}
		j++;
		e+= deltaX;
	}
	mlx_string_put(env->mlx_ptr, env->win_ptr, 400, 100, rgb(0,255,255), ft_itoa(deltaY));
	return (0);
}

int colour(t_environment *env, int colour)
{
	int i;
	int j;

	i = 0;
	while (i < 600)
	{
		j = 0;
		while (j < 600)
		{
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, i, j, colour);
			j++;
		}
		i++;
	}
	return (0);
}

void draw_line(t_coord c1, t_coord c2, t_environment* env)
{
	//if ((c2.y - c1.y) / ((c2.x - c1.x) == 0 ? 0.000001f : c2.x - c1.x) <= 1)
	int deltaX = c2.x - c1.x;
	int deltaY = c2.y - c1.y;

	if (deltaX < deltaY)
		draw_line_upper(c1, c2, env);
	else
		draw_line_lower(c1, c2, env);
}

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
