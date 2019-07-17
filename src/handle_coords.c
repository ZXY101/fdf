/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:53:17 by stenner           #+#    #+#             */
/*   Updated: 2019/07/17 11:53:30 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	erro_call(int error)
{
	if (error == 0)
	{
		ft_putendl("Invalid map.");
		exit(0);
	}
	if (error == 1)
	{
		ft_putendl("Not enough arguments.");
		exit(0);
	}
	if (error == 2)
	{
		ft_putendl("Too many arguments.");
		exit(0);
	}
}

static void	malloc_coords(int fd, t_environment *env)
{
	env->map_data.coord_count = 0;
	env->map_data.x_coords = 0;
	env->map_data.y_coords = 0;
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
			erro_call(0);
		free(env->map_data.line_split);
		free(env->map_data.line);
	}
	env->coords = (t_vector*)malloc(sizeof(t_vector) *
	env->map_data.coord_count);
	env->vectors = (t_vector*)malloc(sizeof(t_vector) *
	env->map_data.coord_count);
}

void		get_vectors(int fd, t_environment *env)
{
	t_map_data	map_data;
	t_vector	coord;

	map_data.coord_count = 0;
	map_data.x_coords = 0;
	map_data.y_coords = 0;
	while (get_next_line(fd, &map_data.line) > 0)
	{
		map_data.x_coords = 0;
		map_data.line_split = ft_strsplit(map_data.line, ' ');
		while (map_data.line_split[map_data.x_coords])
		{
			coord.x = map_data.x_coords - (env->map_data.x_coords - 1) * 0.5;
			coord.y = map_data.y_coords - (env->map_data.y_coords - 1) * 0.5;
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
		erro_call(1);
	else if (ac > 2)
		erro_call(2);
	if (!ft_strstr(av[1], ".fdf\0"))
		erro_call(0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		erro_call(0);
	malloc_coords(fd, env);
	if (close(fd) == -1)
		erro_call(0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		erro_call(0);
	get_vectors(fd, env);
	if (close(fd) == -1)
		erro_call(0);
}
