/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:01 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 14:30:12 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file has all of the functions that handle events
*/

#include "../includes/fdf.h"

/*
**Handle any key presses
*/


int		key_input(int key, t_environment *env)
{
	if (key == 53 || key == 0xff1b)
		exit(0);
	if (key == 24 || key == 27)
		zoom(key, env);
	arrow_keys(key, env);
	return (0);
}

/*
**Quit the program when the close button is clicked
*/

int		finish(void *none)
{
	(void)none;
	exit(0);
}

/*
**All of the hooks
*/

void	handle_hooks(void *win_ptr, t_environment *env)
{
	mlx_key_hook(win_ptr, key_input, env);
	mlx_hook(win_ptr, 17, 0L, finish, env);
}
