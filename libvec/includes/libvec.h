/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:21:26 by stenner           #+#    #+#             */
/*   Updated: 2019/07/10 12:16:17 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H
# define FILL_VECTOR(V, X, Y, Z, W) V.x = X, V.y = Y, V.z = Z, V.w = W
# include <math.h>

typedef struct	s_vector
{
	double x;
	double y;
	double z;
	double w;
}				t_vector;

typedef struct	s_matrix
{
	double m[4][4];
}				t_matrix;

/*
**Vector Functions
*/

t_vector		vector_matrix_multiply(t_vector vector, t_matrix m);
t_vector		vector_add(t_vector v1, t_vector v2);
t_vector		vector_subtract(t_vector v1, t_vector v2);
t_vector		vector_multiply(t_vector v, double k);
t_vector		vector_divide(t_vector v, double k);
double			vector_dot_product(t_vector v1, t_vector v2);
double			vector_length(t_vector v);
t_vector		vector_normalise(t_vector v);
t_vector		vector_cross_product(t_vector v1, t_vector v2);

/*
**Matrix Functions
*/

t_matrix		matrix_make_identity();
t_matrix		matrix_rotate_x(double theta);

#endif
