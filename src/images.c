/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:45:17 by stenner           #+#    #+#             */
/*   Updated: 2019/07/02 12:51:07 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
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
