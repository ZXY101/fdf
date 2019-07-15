/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:32:08 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 11:36:20 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	arrow_keys(int key, t_environment *env)
{
	enum e_translate t;

	if (key == 123)
	{
		t = left;
		map_translate(env, t);
	}
	if (key == 124)
	{
		t = right;
		map_translate(env, t);
	}
	if (key == 125)
	{
		t = down;
		map_translate(env, t);
	}
	if (key == 126)
	{
		t = up;
		map_translate(env, t);
	}
}
