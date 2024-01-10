/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_height_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 02:32:52 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/11 02:33:01 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "scene.h"

t_height_map	load_height_map(char *path, t_mlx *mlx)
{
	t_height_map	map;

	map.img = mlx_xpm_file_to_image(mlx->mlx, path, &map.width, &map.height);
	if (map.img == NULL)
		exit_with_error(EXIT_FAILURE, "failed to load height map");
	if (map.width == 0 || map.height == 0)
		exit_with_error(EXIT_FAILURE, "invalid size of height map");
	map.addr = mlx_get_data_addr(map.img, &map.bpp, &map.line_length,
			&map.endian);
	map.pixel_w = 1.0 / map.width;
	map.pixel_h = 1.0 / map.height;
	return (map);
}
