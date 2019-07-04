/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:55 by stenner           #+#    #+#             */
/*   Updated: 2019/07/04 15:52:43 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

/* int		malloc_coords(int ac, char **av, t_coord **coords)
{
	char	*line;
	char	**line_split;
	int		fd;
	int		coord_count;
	int		x_coords;
	int		y_coords;
	int		i;

	coord_count = 0;
	x_coords = 0;
	y_coords = 0;
	i = 0;
	if (ac < 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (2);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		line_split = ft_strsplit(line, ' ');
		while (line_split[i] != '\0')
		{
			i++;
			coord_count++;
		}
		y_coords++;
		if (i ==coord_count)
			x_coords = i;
		if (x_coords != i)
			return (2);
		free(line_split);
		free(line);
	}
	*coords = (t_coord*)malloc(sizeof(t_coord) * coord_count);
	printf("x: %d\ny: %d\ntotal: %d\n");
	if (close(fd) == -1)
			return (2);
	return (0); 
} */

/* t_coord	*get_coords(int fd, t_environment *env)
{
	char	*line;
	char	**x_coords;
	int		coord_count;
	int		x_cords;
	int		y_cords;
	int		i;

	t_coord coord;
	t_coord *coords;

	coords = (t_coord*)malloc(sizeof(t_coord) * 129089012890);
	coord_count = 0;
	x_cords = 0;
	y_cords = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		x_coords = ft_strsplit(line, ' ');
		while (x_coords[i] != '\0')
		{
			coord.x = i;
			coord.y = y_cords;
			coord.z = ft_atoi(x_coords[i]);
			coords[coord_count] = coord;
			i++;
			coord_count++;
		}
		y_cords++;
		free(x_coords);
		free(line);
	}
	x_cords = i;
	i = 0;
	t_rgb rgb, rgb2;
	FILL_RGB(rgb, 100, 100, 255);
	FILL_RGB(rgb2, 255, 100, 100);

	while (i < coord_count)
	{
		pixel_put_image(&env->img, ft_rgbtoi(5,250,55), coords[i].x * 100, coords[i].y * 100);
		i++;
	}
	put_image(env, &env->img);

	printf("Coord Count: %d\nx_cords: %d\nHeight: %d\n", coord_count, x_cords, y_cords);
	return (coords);
} */


int	test(int button,int x,int y,char *words)
{
	printf("%d, %d\n mouse: %d\n%s",x, y, button, words);
	//mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, ft_rgbtoi(255,255,255));
	return (0);
}

int line_follow(int x, int y, t_environment *env)
{
	t_coord center, dest;
	t_rgb rgb;
	FILL_RGB(rgb, 255,0,0);
	FILL_COORD(center, 0, 0);
	center = ndc_to_screen_space(center);
	FILL_COORD(dest, x, y);
	
	/* clear_image(&env->img, ft_rgbtoi(0,0,0));
	pixel_put_image(&env->img, ft_rgbtoi(0, 250, 255), x, y);
	put_image(env,&env->img); */

	clear_image(&env->img, ft_rgbtoi(0,100,0));
	draw_line(center, dest, &env->img, rgb);
	put_image(env,&env->img);

	return (0);
}

int		main(int ac, char **av)
{
	t_environment	env;
	t_coord			*coords;
	(void)coords;
	(void)av;
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
	mlx_hook(env.win_ptr, 6, 0L, line_follow, &env);
	mlx_mouse_hook(env.win_ptr, test, "words");
	//malloc_coords(ac, av, &coords);
	mlx_loop(env.mlx_ptr);
	return (0);
}
