/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:21:26 by stenner           #+#    #+#             */
/*   Updated: 2019/07/09 11:34:24 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LIB_H
# define VECTOR_LIB_H
# define FILL_VECTOR(V, X, Y, Z, W) V.x = X, V.y = Y, V.z = Z, V.w = W

typedef struct	s_vector
{
	double x;
	double y;
	double z;
	double w;
} 				t_vector;

typedef struct	s_matrix
{
	double m[4][4];
}				t_matrix;

t_vector	vector_multiply(t_vector vector, t_matrix m);

#endif