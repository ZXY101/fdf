/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:01 by stenner           #+#    #+#             */
/*   Updated: 2019/07/03 12:01:21 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int key_input(int key, void *param)
{
	(void)param;
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}

int finish(void *none)
{
	(void)none;
	exit(0);
}