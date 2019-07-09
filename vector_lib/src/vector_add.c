/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:36:12 by stenner           #+#    #+#             */
/*   Updated: 2019/07/09 14:40:46 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector_lib.h"

t_vector	vector_add(t_vector v1, t_vector v2)
{
	t_vector ret;
	
	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.z = v1.z + v2.z;
	return (ret);
}
