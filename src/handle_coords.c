/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:53:17 by stenner           #+#    #+#             */
/*   Updated: 2019/07/12 12:25:48 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		malloc_coords(int fd, t_environment *env)
{
	env->map_data.coord_count = 0;
	env->map_data.x_coords = 0;
	env->map_data.y_coords = 0;
	env->map_data.i = 0;
	while (get_next_line(fd, &env->map_data.line) > 0)
	{
		env->map_data.i = 0;
		env->map_data.line_split = ft_strsplit(env->map_data.line, ' ');
		while (env->map_data.line_split[env->map_data.i])
		{
			free(env->map_data.line_split[env->map_data.i]);
			env->map_data.i++;
			env->map_data.coord_count++;
		}
		env->map_data.y_coords++;
		if (env->map_data.i == env->map_data.coord_count)
			env->map_data.x_coords = env->map_data.i;
		if (env->map_data.x_coords != env->map_data.i)
		{
			ft_putendl("Invalid map");
			exit(2);
		}
		free(env->map_data.line_split);
		free(env->map_data.line);
	}
	env->coords = (t_coord*)malloc(sizeof(t_coord) * env->map_data.coord_count);
}

void		get_coords(int fd, t_environment *env)
{
	t_map_data	map_data;
	t_coord		coord;

	map_data.coord_count = 0;
	map_data.x_coords = 0;
	map_data.y_coords = 0;
	while (get_next_line(fd, &map_data.line) > 0)
	{
		map_data.x_coords = 0;
		map_data.line_split = ft_strsplit(map_data.line, ' ');
		while (map_data.line_split[map_data.x_coords])
		{
			
			coord.x = map_data.x_coords;
			coord.y = map_data.y_coords;
			coord.z = ft_atoi(map_data.line_split[map_data.x_coords]);
			free(map_data.line_split[map_data.x_coords]);
			env->coords[map_data.coord_count] = coord;
			map_data.x_coords++;
			map_data.coord_count++;
		}
		map_data.y_coords++;
		free(map_data.line_split);
		free(map_data.line);
	}
}

void		handle_coords(int ac, char **av, t_environment *env)
{
	int			fd;

	if (ac < 2)
	{
		ft_putendl("Not enough arguments.");
		exit(0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Invalid map");
		exit(2);
	}
	malloc_coords(fd, env);
	if (close(fd) == -1)
		exit(0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Invalid map");
		exit(2);
	}
	get_coords(fd, env);
	if (close(fd) == -1)
		exit(0);
}
