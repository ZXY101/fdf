/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:47:23 by stenner           #+#    #+#             */
/*   Updated: 2019/07/10 14:42:55 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_matrix	matrix_rotate_x(double theta)
{
	t_matrix m;


	m.m[0][0] = 1;
	m.m[1][1] = cos(theta);
	m.m[1][2] = sin(theta);
	m.m[2][1] = -sin(theta);
	m.m[2][2] = cos(theta);
	m.m[3][3] = 1;
	return m;
}

t_matrix	matrix_rotate_y(double theta)
{
	t_matrix m;


	m.m[0][0] = cos(theta);
	m.m[0][2] = sin(theta);
	m.m[2][0] = -sin(theta);
	m.m[1][1] = 1;
	m.m[2][2] = cos(theta);
	m.m[3][3] = 1;
	return m;
}

t_matrix	matrix_rotate_z(double theta)
{
	t_matrix m;


	m.m[0][0] = cos(theta);
	m.m[0][1] = sin(theta);
	m.m[1][0] = -sin(theta);
	m.m[1][1] = cos(theta);
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return m;
}