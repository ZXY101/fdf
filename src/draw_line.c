/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:26:45 by stenner           #+#    #+#             */
/*   Updated: 2019/07/02 15:09:12 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
static void	draw_line_lower(t_coord c1, t_coord c2, t_mlx_image *img, t_rgb rgb)
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
		pixel_put_image(img, ft_rgbtoi(rgb.r * l.iq, rgb.g * l.iq, rgb.b * l.iq)
		,c1.x + i, c1.y + i * l.grad);
		pixel_put_image(img, ft_rgbtoi(rgb.r * l.q, rgb.g * l.q, rgb.b * l.q),
		c1.x + i, (c1.y + i * l.grad) + 1);
		i++;
	}
}

static void	draw_line_upper(t_coord c1, t_coord c2, t_mlx_image *img, t_rgb rgb)
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
		pixel_put_image(img, ft_rgbtoi(rgb.r * l.iq, rgb.g * l.iq, rgb.b * l.iq)
		,c1.x + i * l.grad, c1.y + i);
		pixel_put_image(img, ft_rgbtoi(rgb.r * l.q, rgb.g * l.q, rgb.b * l.q),
		(c1.x + i * l.grad) + 1, c1.y + i);
		i++;
	}
}

void		draw_line(t_coord c1, t_coord c2, t_mlx_image *img, t_rgb rgb)
{
	int			delta_x;
	int			delta_y;

	delta_x = c2.x - c1.x;
	delta_y = c2.y - c1.y;
	if (abs(delta_x) < abs(delta_y))
		draw_line_upper(c1, c2, img, rgb);
	else
		draw_line_lower(c1, c2, img, rgb);
}
