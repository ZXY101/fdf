/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/02 15:43:13 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int test(int key, void *param)
{
	(void)param;
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}


t_coord	ndc_to_screen_space(t_coord coord)
{
	t_coord ret;

	ret = coord;
	ret.y *= -1;
	ret.x += 0.5;
	ret.y += 0.5;
	ret.x *= WINDOW_LENGTH;
	ret.y *= WINDOW_HEIGHT;
	return (ret);
}

int loop_hook(t_environment *env)
{
	t_coord center, left, right, up, down;

	FILL_COORD(center, 0, 0); // 0, 0
	FILL_COORD(left, -0.25, 0); // -0.5, 0 
	FILL_COORD(right, 0.25, 0); // 0.5, 0
	FILL_COORD(up, 0, 0.25); // 0, -0.5
	FILL_COORD(down, 0, -0.25); // 0, 0.5
	center = ndc_to_screen_space(center);
	left = ndc_to_screen_space(left);
	right = ndc_to_screen_space(right);
	up = ndc_to_screen_space(up);
	down = ndc_to_screen_space(down);
	clear_image(&env->img, 0x00000000);
	t_rgb red, blue, green, yellow, white;
	FILL_RGB(red, 255, 0, 0);
	FILL_RGB(blue, 0, 0, 255);
	FILL_RGB(green, 0, 255, 0);
	FILL_RGB(yellow, 255, 255, 0);
	FILL_RGB(white, 255, 255, 255);
	draw_line(down, left, &env->img, red);
	draw_line(left, up, &env->img, blue);
	draw_line(up, right, &env->img, green);
	draw_line(right, down, &env->img, yellow);
	pixel_put_image(&env->img, ft_rgbtoi(255, 255, 255), center.x, center.y);	
	pixel_put_image(&env->img, ft_rgbtoi(255, 255, 255), left.x, left.y);	
	pixel_put_image(&env->img, ft_rgbtoi(255, 255, 255), right.x, right.y);	
	pixel_put_image(&env->img, ft_rgbtoi(255, 255, 255), up.x, up.y);	
	pixel_put_image(&env->img, ft_rgbtoi(255, 255, 255), down.x, down.y);	
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
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"Test");
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	mlx_key_hook(env.win_ptr, test,(void *)0);
//	mlx_hook(env.win_ptr, 6, 0L, mouse_line_follow, &env);
	mlx_hook(env.win_ptr, 17, 0L, finish, &env);
	mlx_loop_hook(env.mlx_ptr, loop_hook, &env);
	pixel_put_image(&env.img, ft_rgbtoi(255, 255, 255), 300, 300);	
	mlx_loop(env.mlx_ptr);
	return (0);
}
