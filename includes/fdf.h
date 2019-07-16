/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:46:30 by stenner           #+#    #+#             */
/*   Updated: 2019/07/15 18:06:31 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_LENGTH 1280
# define WINDOW_HEIGHT 720
# define FILL_COORD(C, X, Y, Z) C.x = X, C.y = Y, C.z = Z
# define FILL_RGB(RGB, R, G, B) RGB.r = R, RGB.g = G, RGB.b = B
# include "../libft/includes/libft.h"
# include "../libvec/includes/libvec.h"
# include <mlx.h>
# include <math.h>
//REMOVE
# include <stdio.h>

enum	e_translate
{
	left,
	right,
	up,
	down
};

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

typedef struct	s_mlx_image
{
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	char		*raw_data;
	int			width;
	int			height;
	t_vector		pos;
}				t_mlx_image;

typedef struct	s_environment
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_image	img;
	t_vector	*coords;
	t_map_data	map_data;
	t_rgb		rgb;
	t_vector	*vectors;
	char		*map_name;
	t_vector	rotation;
	t_vector	scale;
	t_vector	translation;
	int			speed;
	int			keys[512];
	int			buttons[10];
	int			auto_rotate;
	int			auto_rotate_dir;
}				t_environment;

/*
**Utility
*/

void			draw_line(t_vector c1, t_vector c2, t_mlx_image *img, t_rgb rgb);
void			draw_faces(t_environment *env, t_rgb rgb);
t_vector		ndc_to_screen_space(t_vector coord);
int				rgbtoi(int r, int g, int b);
void			update_image(t_environment *env);
void			map_translate(t_environment *env, enum e_translate t);

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

int				key_input(int key, t_environment *env);
int				finish(void *none);
void			handle_hooks(void *win_ptr, t_environment *env);

/*
**Keys
*/

void			arrow_keys(int key, t_environment *env);
void			zoom(int key, t_environment *env);
void			rgb_keys(t_environment *env);


/*
**Coords
*/

void		handle_coords(int ac, char **av, t_environment *env);
#endif
