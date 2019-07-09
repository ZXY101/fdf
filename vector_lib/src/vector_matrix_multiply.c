/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:17:45 by stenner           #+#    #+#             */
/*   Updated: 2019/07/09 14:41:48 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector_lib.h"

t_vector	vector_matrix_multiply(t_vector vector, t_matrix m)
{
	t_vector ret;

	ret.x = vector.x * m.m[0][0] + vector.y * m.m[1][0] +
	vector.z * m.m[2][0] + m.m[3][0];
	ret.y = vector.x * m.m[0][1] + vector.y * m.m[1][1] +
	vector.z * m.m[2][1] + m.m[3][1];
	ret.z = vector.x * m.m[0][2] + vector.y * m.m[1][2] +
	vector.z * m.m[2][2] + m.m[3][2];
	ret.w = vector.x * m.m[0][3] + vector.y * m.m[1][3] +
	vector.z * m.m[2][3] + m.m[3][2];
	if (ret.w != 0)
	{
		ret.x /= ret.w;
		ret.y /= ret.w;
		ret.z /= ret.w;
	}
	return (ret);
}
