/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:13:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/03 11:14:49 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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