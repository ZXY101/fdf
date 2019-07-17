/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:32:08 by stenner           #+#    #+#             */
/*   Updated: 2019/07/17 11:52:33 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_keys(t_environment *env)
{
	env->rotation.y += env->keys[0] ? env->speed : 0;
	env->rotation.y -= env->keys[2] ? env->speed : 0;
	env->rotation.x += env->keys[13] ? env->speed : 0;
	env->rotation.x -= env->keys[1] ? env->speed : 0;
	env->rotation.z += env->keys[14] ? env->speed : 0;
	env->rotation.z -= env->keys[12] ? env->speed : 0;
}

void	zoom_keys(t_environment *env)
{
	if (env->keys[24])
	{
		env->scale = env->keys[257] ? vector_multiply(env->scale, 1.1) :
		vector_multiply(env->scale, 1.05);
		env->scale.w = 1;
	}
	if (env->keys[27])
	{
		env->scale = env->keys[257] ? vector_multiply(env->scale, 0.9) :
		vector_multiply(env->scale, 0.95);
		env->scale.w = 1;
	}
}

void	arrow_keys(t_environment *env)
{
	env->translation.x -= env->keys[123] ? env->speed : 0;
	env->translation.x += env->keys[124] ? env->speed : 0;
	env->translation.y -= env->keys[126] ? env->speed : 0;
	env->translation.y += env->keys[125] ? env->speed : 0;
}

void	rgb_keys(t_environment *env)
{
	env->rgb.r += env->keys[86] && env->rgb.r < 255 ? 5 : 0;
	env->rgb.g += env->keys[87] && env->rgb.g < 255 ? 5 : 0;
	env->rgb.b += env->keys[88] && env->rgb.b < 255 ? 5 : 0;
	env->rgb.r -= env->keys[83] && env->rgb.r > 0 ? 5 : 0;
	env->rgb.g -= env->keys[84] && env->rgb.g > 0 ? 5 : 0;
	env->rgb.b -= env->keys[85] && env->rgb.b > 0 ? 5 : 0;
}
