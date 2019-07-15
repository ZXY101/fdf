/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:45:25 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 18:27:22 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_matrix	matrix_projection(double fov, double a_r, double near, double far)
{
	t_matrix m;
	double fov_rad;

	init_to_zero(&m);
	fov_rad = 1 / tan(fov * 0.5 / 180 * M_PI);
	m.m[0][0] = near / (a_r * fov_rad);
	m.m[1][1] = near / fov_rad;
	m.m[2][2] = -(far + near) / (far - near);
	m.m[3][2] = (-2 * far * near) / (far - near);
	m.m[2][3] = -1;

	return (m);
}
