/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreachi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:41:14 by stenner           #+#    #+#             */
/*   Updated: 2019/06/11 13:28:51 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreachi(int *arr, size_t n, void (*f)(int))
{
	size_t i;

	i = 0;
	while (i < n)
	{
		f(arr[i]);
		i++;
	}
}
