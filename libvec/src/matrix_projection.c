/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:45:25 by stenner           #+#    #+#             */
/*   Updated: 2019/07/10 14:54:25 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_matrix	matrix_projection(double fov, double a_r, double near, double far)
{
	t_matrix m;
	double fov_rad;

	fov_rad = 1 / tan(fov * 0.5 / 180 * 3.14159);
	m.m[0][0] = a_r * fov_rad;
	m.m[1][1] = fov_rad;
	m.m[2][2] = far / (far - near);
	m.m[3][2] = (-far * near) / (far - near);
	m.m[2][3] = 1;
	m.m[3][3] = 0;
	return (m);
}
