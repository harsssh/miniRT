/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 04:37:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 04:51:59 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "ft_math.h"
#include "libft.h"
#include "vector.h"

// (u, v, w) are the orthonormal basis of the camera.
// The distance between the camera and the viewport is 1.
t_camera	new_camera(t_camera_conf conf, t_vec3 vup, double aspect_ratio)
{
	const double	viewport_width = 2.0 * tan(ft_to_radian(conf.fov) / 2.0);
	const double	viewport_height = viewport_width / aspect_ratio;
	const t_vec3	w = vec3_normalize(conf.orientation);
	const t_vec3	u = vec3_normalize(vec3_cross(w, vup));
	const t_vec3	v = vec3_cross(w, u);

	return ((t_camera){
		.origin = conf.position,
		.viewport_horizontal = vec3_scale(u, viewport_width),
		.viewport_vertical = vec3_scale(v, viewport_height),
		.upper_left_corner = vec3_add_scaled(
			vec3_add(conf.position, w),
			vec3_add(
				vec3_scale(u, viewport_width), vec3_scale(v, viewport_height)
			),
			-0.5
		)
	});
}

// (x, y) are coordinates on the viewport, normalized between [0, 1].
t_ray	camera_get_ray(t_camera camera, double x, double y)
{
	const t_vec3	screen_point = vec3_add_3(
			camera.upper_left_corner,
			vec3_scale(camera.viewport_horizontal, x),
			vec3_scale(camera.viewport_vertical, y));

	return (new_ray(camera.origin, vec3_sub(screen_point, camera.origin)));
}
