/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:17:01 by stenner           #+#    #+#             */
/*   Updated: 2019/06/26 15:46:38 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_sqrt(long num)
{
	long i;

	if (num < 0)
		return (0);
	i = 1;
	while ((i * i) <= num)
	{
		if ((i * i) == num)
			return (i);
		i++;
	}
	return (0);
}
