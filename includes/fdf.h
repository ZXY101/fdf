/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:46:30 by stenner           #+#    #+#             */
/*   Updated: 2019/07/02 12:21:51 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_line_math
{
	int			delta_x;
	int			delta_y;
	double		grad;
	double		q;
	double		iq;
}				t_line_math;

typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
}				t_coord;

typedef struct	s_mlx_image
{
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	char		*raw_data;
	int			width;
	int			height;
	t_coord		pos;
}				t_mlx_image;

typedef struct	s_environment
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_image	img;
}				t_environment;

void			draw_line(t_coord c1, t_coord c2, t_environment *env);
#endif
