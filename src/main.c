/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:34:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/26 10:38:45 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "mlx_utils.h"
#include "tracer.h"
#include <limits.h>
#include <stdio.h>

static bool	is_rt_file(char *filename)
{
	const size_t	len = ft_strlen(filename);

	if (len < 3)
		return (false);
	return (ft_strcmp(filename + len - 3, ".rt") == 0);
}

int	main(int argc, char **argv)
{
	t_parse_option	opt;
	t_scene			*scene;
	t_mlx			*mlx;

	if (argc != 2)
	{
		printf("Usage: %s <scene_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (!is_rt_file(argv[1]))
	{
		printf("Error: %s is not a .rt file\n", argv[1]);
		return (EXIT_FAILURE);
	}
	mlx = new_mlx(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	opt.mlx = mlx;
	opt.max_light = UINT_MAX;
	scene = parse_scene(argv[1], opt);
	render_scene(mlx, scene);
	render_loop(mlx);
}
