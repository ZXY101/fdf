/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:01:37 by stenner           #+#    #+#             */
/*   Updated: 2019/07/10 13:04:23 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_vector	vector_normalise(t_vector v)
{
	t_vector	ret;
	double		len;

	len = vector_length(v);
	ret.x = v.x / len;
	ret.y = v.y / len;
	ret.z = v.z / len;
	return (ret);
}
