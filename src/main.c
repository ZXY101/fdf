/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/05 14:25:14 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	malloc_coords(int fd, t_coord **coords, t_map_data *map_data)
{
	map_data->coord_count = 0;
	map_data->x_coords = 0;
	map_data->y_coords = 0;
	map_data->i = 0;
	while (get_next_line(fd, &map_data->line) > 0)
	{
		map_data->i = 0;
		map_data->line_split = ft_strsplit(map_data->line, ' ');
		while (map_data->line_split[map_data->i])
		{
			map_data->i++;
			map_data->coord_count++;
		}
		map_data->y_coords++;
		if (map_data->i == map_data->coord_count)
			map_data->x_coords = map_data->i;
		if (map_data->x_coords != map_data->i)
		{
			ft_putendl("Invalid map");
			exit (2);
		}
		free(map_data->line_split);
		free(map_data->line);
	}
	*coords = (t_coord*)malloc(sizeof(t_coord) * map_data->coord_count);
	printf("Coord Count: %d\nX Count: %d\nY Count: %d\n", map_data->coord_count, map_data->x_coords, map_data->y_coords);

}

t_coord	*get_coords(int fd, t_coord *coords)
{
	t_map_data	map_data;
	t_coord coord;

	map_data.coord_count = 0;
	map_data.x_coords = 0;
	map_data.y_coords = 0;
	map_data.i = 0;

	while (get_next_line(fd, &map_data.line) > 0)
	{
		map_data.i = 0;
		map_data.line_split = ft_strsplit(map_data.line, ' ');
		while (map_data.line_split[map_data.i])
		{
			coord.x = map_data.i;
			coord.y = map_data.y_coords;
			coord.z = ft_atoi(map_data.line_split[map_data.i]);
			coords[map_data.coord_count] = coord;
			map_data.i++;
			map_data.coord_count++;

		}
		map_data.y_coords++;
		free(map_data.line_split);
		free(map_data.line);
	}
	map_data.x_coords = map_data.i;
	return(coords);
} 

void	handle_coords(int ac, char **av, t_environment *env)
{
	int fd;
	t_coord *coords;
	t_map_data map_data;

	if (ac < 2)
	{
		ft_putendl("Not enough arguments.");
		exit (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Invalid map");
		exit (2);
	}
	malloc_coords(fd, &coords, &map_data);
	if (close(fd) == -1)
		exit (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Invalid map");
		exit (2);
	}
	coords = get_coords(fd, coords);
	int i;
	i = 0;
	while (i < map_data.coord_count)
	{
		pixel_put_image(&env->img, ft_rgbtoi(5,250,55), coords[i].x * 100, coords[i].y * 100);
		i++;
	}
	put_image(env, &env->img);
}

int		main(int ac, char **av)
{
	t_environment	env;
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
	handle_coords(ac, av, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
