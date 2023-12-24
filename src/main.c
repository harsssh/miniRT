/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:34:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 06:02:48 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "tracer.h"
#include <stdio.h>
#include <limits.h>

# define WIDTH 1024
# define HEIGHT 768
# define TITLE "miniRT"

int main(int argc, char **argv)
{
	const t_parse_option opt = {.max_light = UINT_MAX};
	t_scene *scene;
	t_mlx *mlx;

	if (argc != 2)
	{
		printf("Usage: %s <scene_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	scene = parse_scene(argv[1], opt);
	mlx = new_mlx(WIDTH, HEIGHT, TITLE);
	render_scene(mlx, scene);
	render_loop(mlx);
}