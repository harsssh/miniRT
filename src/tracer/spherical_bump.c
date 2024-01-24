/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spherical_bump.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 02:27:44 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/11 02:28:43 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static t_vec3	uv_to_spherical(t_object *sphere, t_vec3 uv)
{
	const t_sphere_conf	conf = *(t_sphere_conf *)sphere->conf;
	const double		theta = (1 - (uv.x + 0.5)) * M_PI;
	const double		phi = uv.y * M_PI;

	return ((t_vec3){
		.x = conf.radius * sin(phi) * sin(theta),
		.y = conf.radius * cos(phi),
		.z = conf.radius * sin(phi) * cos(theta),
	});
}

t_vec3	get_spherical_normal(t_object *sphere, t_hit_record *rec, t_vec3 uv)
{
	const t_sphere_conf	conf = *(t_sphere_conf *)sphere->conf;
	const t_vec3		normal = vec3_div(vec3_sub(rec->point, conf.center),
			conf.radius);
	const t_height_map	map = sphere->material.height_map;
	t_vec_pair			p;

	if (map.img == NULL)
		return (normal);
	p.first = vec3_normalize(vec3_sub(
				uv_to_spherical(sphere, vec3(uv.x - map.pixel_w, uv.y, uv.z)),
				uv_to_spherical(sphere, vec3(uv.x + map.pixel_w, uv.y, uv.z))));
	p.second = vec3_normalize(vec3_sub(
				uv_to_spherical(sphere, vec3(uv.x, uv.y - map.pixel_h, uv.z)),
				uv_to_spherical(sphere, vec3(uv.x, uv.y + map.pixel_h, uv.z))));
	return (get_normal_at(map, uv, p, normal));
}
