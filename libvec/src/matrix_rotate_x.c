/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:47:23 by stenner           #+#    #+#             */
/*   Updated: 2019/07/10 13:04:23 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_matrix	matrix_rotate_x(double theta)
{
	t_matrix m;
	int i;
	int j;

	i = 0;
	j = 0;
	(void)theta;
	m.m[0][1] = 1;
	// while (i < 4)
	// {
	// 	j = 0;
	// 	while (j < 4)
	// 	{
	// 		m.m[i][j] = 0;
	// 		j++;
	// 	}
	// 	i++;
	// }
	//m.m[0][0] = 1;
	return m;
}