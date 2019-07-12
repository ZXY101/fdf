/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:13:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/12 11:17:48 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file contains any handy functions that can be used in a gfx project
*/

#include "../includes/fdf.h"

/*
**Function to convert Normalised Device Coordinates to screen space
*/

t_coord	ndc_to_screen_space(t_coord coord)
{
	t_coord ret;

	ret = coord;
	ret.x /= 2;
	ret.y /= 2;
	ret.y *= -1;
	ret.x += 0.5;
	ret.y += 0.5;
	ret.x *= WINDOW_LENGTH;
	ret.y *= WINDOW_HEIGHT;
	return (ret);
}

/*
**Function to take 3 rgb values and returns a the colour integer
*/

int		rgbtoi(int r, int g, int b)
{
	int rgb;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	rgb = 0x010000 * r + 0x000100 * g + b;
	return (rgb);
}

/*
**Update the 3D model
*/

void	update_image(t_environment *env)
{
	t_rgb rgb;
	FILL_RGB(rgb, 200, 0, 255);
	clear_image(&env->img, 0x000000);
	draw_faces(env,rgb);
	put_image(env, &env->img);
}
