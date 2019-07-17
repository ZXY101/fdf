/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:01 by stenner           #+#    #+#             */
/*   Updated: 2019/07/17 12:10:33 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file has all of the functions that handle events
*/

#include "../includes/fdf.h"

/*
**Quit the program when the close button is clicked
*/

static int	finish(void *none)
{
	(void)none;
	exit(0);
}

/*
**All of the hooks
*/

static int	fun(t_environment *env)
{
	env->speed = env->keys[257] ? 14 : 5;
	rotate_keys(env);
	arrow_keys(env);
	zoom_keys(env);
	rgb_keys(env);
	if (env->auto_rotate == 1)
		env->rotation.y += env->auto_rotate_dir == 1 ? 1 : -1;
	update_image(env);
	return (0);
}

void		handle_hooks(void *win_ptr, t_environment *env)
{
	mlx_hook(win_ptr, 2, 0L, key_down, env);
	mlx_hook(win_ptr, 3, 0L, key_release, env);
	mlx_hook(win_ptr, 4, 0L, mouse_down, env);
	mlx_hook(win_ptr, 5, 0L, mouse_release, env);
	mlx_hook(win_ptr, 17, 0L, finish, env);
	mlx_loop_hook(env->mlx_ptr, fun, env);
}
