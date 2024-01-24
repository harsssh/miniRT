/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conical_bump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 02:22:26 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/11 02:24:19 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static t_vec3	uv_to_conical(t_object *cone, t_vec3 uv)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cone->conf;
	const double			theta = (1 - (uv.x + 0.5)) * M_PI;
	const double			height = uv.y * conf.height;

	return ((t_vec3){
		.x = conf.radius * height / conf.height * sin(theta),
		.y = height,
		.z = conf.radius * height / conf.height * cos(theta),
	});
}

t_vec3	get_conical_normal(t_object *cone, t_hit_record *rec, t_vec3 uv)
{
	const t_cone_conf	conf = *(t_cone_conf *)cone->conf;
	const t_vec3		pc = vec3_sub(rec->point, conf.apex);
	const t_vec3		normal = vec3_normalize(vec3_sub(pc, vec3_scale(
					conf.axis, vec3_dot(pc, pc) / vec3_dot(conf.axis, pc))));
	const t_height_map	map = cone->material.height_map;
	t_vec_pair			p;

	if (map.img == NULL)
		return (normal);
	p.first = vec3_normalize(vec3_sub(uv_to_conical(cone, vec3(
						uv.x - map.pixel_w, uv.y, uv.z)), uv_to_conical(
					cone, vec3(uv.x + map.pixel_w, uv.y, uv.z))));
	p.second = vec3_normalize(vec3_sub(uv_to_conical(cone, vec3(
						uv.x, uv.y - map.pixel_h, uv.z)), uv_to_conical(
					cone, vec3(uv.x, uv.y + map.pixel_h, uv.z))));
	return (get_normal_at(map, uv, p, normal));
}
