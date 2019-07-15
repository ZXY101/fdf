/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_make_identity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:35:51 by stenner           #+#    #+#             */
/*   Updated: 2019/07/12 14:02:53 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_matrix	matrix_make_identity(void)
{
	t_matrix m;

	init_to_zero(&m);
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}
