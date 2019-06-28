/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/06/28 17:22:10 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>

int		main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 600, "Test");
	mlx_string_put(mlx_ptr, win_ptr, 300, 300, 16777215, "Hello World!");
	mlx_loop(mlx_ptr);
	return (0);
}
