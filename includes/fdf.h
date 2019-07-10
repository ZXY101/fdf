/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:46:30 by stenner           #+#    #+#             */
/*   Updated: 2019/07/10 17:05:28 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_LENGTH 1000
# define WINDOW_HEIGHT 600
# define FILL_COORD(C, X, Y) C.x = X, C.y = Y
# define FILL_RGB(RGB, R, G, B) RGB.r = R, RGB.g = G, RGB.b = B
# include "../libft/includes/libft.h"
# include "../libvec/includes/libvec.h"
# include <mlx.h>
# include <math.h>
//REMOVE
# include <stdio.h>

typedef struct	s_map_data
{
	char		*line;
	char		**line_split;
	int			coord_count;
	int			x_coords;
	int			y_coords;
	int			i;
}				t_map_data;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

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
	double		x;
	double		y;
	double		z;
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
	t_coord		*coords;
	t_map_data	map_data;
}				t_environment;

/*
**Utility
*/

void			draw_line(t_coord c1, t_coord c2, t_mlx_image *img, t_rgb rgb);
void			draw_faces(t_environment *env, t_rgb rgb);
t_coord			ndc_to_screen_spaqce(t_coord coord);
int				rgbtoi(int r, int g, int b);

/*
**Images
*/

void			pixel_put_image(t_mlx_image *img, int colour, int x, int y);
void			clear_image(t_mlx_image *img, int colour);
void			init_image(t_environment *env, t_mlx_image *img,
				int width, int height);
void			put_image(t_environment *env, t_mlx_image *img);

/*
**Hooks
*/

int				key_input(int key, void *param);
int				finish(void *none);
void			handle_hooks(void *win_ptr, t_environment *env);

/*
**Coords
*/

void			malloc_coords(int fd, t_environment *env);
void			get_coords(int fd, t_environment *env);
void			handle_coords(int ac, char **av, t_environment *env);
#endif
