/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:22:49 by stenner           #+#    #+#             */
/*   Updated: 2019/07/12 13:29:34 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"
#include <stdio.h>

t_matrix	matrix_translate(double x, double y, double z)
{
	t_matrix m;


	init_to_zero(&m);
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	m.m[3][0] = x;
	m.m[3][1] = y;
	m.m[3][2] = z;
	return (m);
}