/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 04:52:42 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 04:55:10 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tracer.h"

static t_vec3	camera_vup(t_camera_conf conf)
{
	if (vec3_parallel(conf.orientation, vec3_axis_y()))
		return (vec3_axis_z());
	return (vec3_axis_y());
}

void	render_scene(t_mlx *mlx, t_scene *scene)
{
	const t_camera	camera = new_camera(
			scene->camera, camera_vup(scene->camera),
			(double)mlx->width / mlx->height);
	t_ray			ray;
	t_rgb			color;
	int				x;
	int				y;

	x = 0;
	while (x < mlx->width)
	{
		y = 0;
		while (y < mlx->height)
		{
			ray = camera_get_ray(
					camera,
					(double)x / (mlx->width - 1),
					(double)y / (mlx->height - 1));
			color = ray_color(scene, ray);
			put_pixel_to_image(mlx, x, y, rgb_to_int(color));
			y++;
		}
		x++;
	}
}
