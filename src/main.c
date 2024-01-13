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

#include "mlx_utils.h"
#include "tracer.h"
#include <limits.h>
#include <stdio.h>

#define WIDTH 1024
#define HEIGHT 768
#define TITLE "miniRT"

static bool	is_rt_file(char *filename)
{
	const size_t	len = ft_strlen(filename);

	if (len < 3)
		return (false);
	return (ft_strcmp(filename + len - 3, ".rt") == 0);
}

int	main(int argc, char **argv)
{
	const t_parse_option	opt = {.max_light = UINT_MAX};
	t_scene					*scene;
	t_mlx					*mlx;

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
	scene = parse_scene(argv[1], opt);
	mlx = new_mlx(WIDTH, HEIGHT, TITLE);
	render_scene(mlx, scene);
	render_loop(mlx);
}
