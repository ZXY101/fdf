/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:01 by stenner           #+#    #+#             */
/*   Updated: 2019/07/03 12:16:12 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**Handle any key presses
*/
int key_input(int key, void *param)
{
	(void)param;
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}

/*
**Quit the program when the close button is clicked
*/
int finish(void *none)
{
	(void)none;
	exit(0);
}