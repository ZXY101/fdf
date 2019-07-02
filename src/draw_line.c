/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:26:45 by stenner           #+#    #+#             */
/*   Updated: 2019/07/02 12:23:53 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../testing/test.c"
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

///////////////////////////////////////////
static void	draw_line_lower(t_coord c1, t_coord c2, t_environment *env)
{
	int			i;
	t_line_math l;

	if (c1.x > c2.x)
		ft_swap(&c1, &c2, sizeof(t_coord));
	l.delta_x = c2.x - c1.x;
	l.delta_y = c2.y - c1.y;
	l.grad = l.delta_y / (double)l.delta_x;
	i = 0;
	while (i < l.delta_x)
	{
		l.q = ((c1.y + i * l.grad) - (int)(c1.y + i * l.grad));
		l.iq = 1 - l.q;
		pixel_put_image(&env->img, ft_rgbtoi(0 * l.iq, 255 * l.iq, 255 * l.iq),
		c1.x + i, c1.y + i * l.grad);
		pixel_put_image(&env->img, ft_rgbtoi(0 * l.q, 255 * l.q, 255 * l.q),
		c1.x + i, (c1.y + i * l.grad) + 1);
		i++;
	}
}

static void	draw_line_upper(t_coord c1, t_coord c2, t_environment *env)
{
	int			i;
	t_line_math l;

	if (c1.y > c2.y)
		ft_swap(&c1, &c2, sizeof(t_coord));
	l.delta_x = c2.x - c1.x;
	l.delta_y = c2.y - c1.y;
	l.grad = l.delta_x / (double)l.delta_y;
	i = 0;
	while (i < l.delta_y)
	{
		l.q = ((c1.x + i * l.grad) - (int)(c1.x + i * l.grad));
		l.iq = 1 - l.q;
		pixel_put_image(&env->img, ft_rgbtoi(0 * l.iq, 255 * l.iq, 255 * l.iq),
		c1.x + i * l.grad, c1.y + i);
		pixel_put_image(&env->img, ft_rgbtoi(0 * l.q, 255 * l.q, 255 * l.q),
		(c1.x + i * l.grad) + 1, c1.y + i);
		i++;
	}
}

void		draw_line(t_coord c1, t_coord c2, t_environment *env)
{
	int			delta_x;
	int			delta_y;

	delta_x = c2.x - c1.x;
	delta_y = c2.y - c1.y;
	if (abs(delta_x) < abs(delta_y))
		draw_line_upper(c1, c2, env);
	else
		draw_line_lower(c1, c2, env);
}
