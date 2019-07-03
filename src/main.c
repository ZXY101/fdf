/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/03 17:39:00 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

t_coord	*get_coords(int fd, t_environment *env)
{
	char	*line;
	char	**x_coords;
	int		length;
	int		height;
	int		i;
	int		x;

	t_coord coord;
	t_coord *coords;

	coords = (t_coord*)malloc(sizeof(t_coord) * 200000);
	length = 0;
	height = 0;
	x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		x_coords = ft_strsplit(line, ' ');
		while (x_coords[i] != '\0')
		{
			coord.x = i;
			coord.y = height;
			coord.z = ft_atoi(x_coords[i]);
			coords[x] = coord;
			i++;
			x++;
		}
		height++;
		length += i;
		free(x_coords);
		free(line);
	}
	i = 0;
	t_coord old_point;
	t_rgb rgb, rgb2;
	FILL_RGB(rgb, 100, 100, 255);
	FILL_RGB(rgb2, 255, 100, 100);

	FILL_COORD(old_point, 0, 0);
	while (i < x)
	{
		FILL_COORD(coords[i], coords[i].x*100, coords[i].y*100);
		pixel_put_image(&env->img, ft_rgbtoi(5,250,55), coords[i].x * 100, coords[i].y * 100);
		draw_line(old_point, coords[i], &env->img, rgb);
		draw_line(old_point, coords[i + 1], &env->img, rgb2);

		old_point = coords[i];
		i++;
	}
	//pixel_put_image(&env->img, ft_rgbtoi(255,250,255), coord.x, coord.y);
	put_image(env, &env->img);

	printf("Length: %d\nHeight: %d\n", length, height);
	return (coords);
}

int		main(int ac, char **av)
{
	t_environment	env;
	t_coord			*coords;
	int				fd;

	if (ac < 2)
	{
		ft_putendl("Not Enough Arguments!");
		return (0);
	}
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"fdf");
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	mlx_key_hook(env.win_ptr, key_input, (void *)0);
	mlx_hook(env.win_ptr, 17, 0L, finish, &env);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
			ft_putendl("Invalid map");
			return (0);
	}
	coords = get_coords(fd, &env);
	if (close(fd) == -1)
			return (0);
	mlx_loop(env.mlx_ptr);
	return (0);
}
