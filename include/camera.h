/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 04:35:55 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 04:35:59 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "scene.h"
# include "ray.h"
# include "vector.h"

/*
 * `t_camera` is a struct that represents a camera in a 3D space.
 * `origin` is the origin of the camera.
 * `upper_left_corner` is the upper left corner of the viewport.
 * `viewport_horizontal` is the vector pointing right of the viewport.
 * `viewport_vertical` is the vector pointing downward of the viewport.
 */
typedef struct s_camera
{
	t_vec3	origin;
	t_vec3	upper_left_corner;
	t_vec3	viewport_horizontal;
	t_vec3	viewport_vertical;
}			t_camera;

t_camera	new_camera(t_camera_conf conf, t_vec3 vup, double aspect_ratio);
t_ray		camera_get_ray(t_camera camera, double x, double y);

#endif
