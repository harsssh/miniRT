/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:55:59 by kemizuki          #+#    #+#             */
/*   Updated: 2024/01/02 07:44:22 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static t_vec3	circular_map(t_object *circ, t_vec3 p)
{
	const t_circle_conf	conf = *(t_circle_conf *)circ->conf;
	const t_vec3		planar_uv = planar_map(&(t_object){
			.conf = &(t_plane_conf){.normal = conf.normal}
		}, vec3_sub(p, conf.center));
	const double		theta = atan2(planar_uv.x, planar_uv.y);
	const double		raw_u = theta / (2 * M_PI);
	const double		r = vec3_length(planar_uv);

	return ((t_vec3){
		.x = 1 - (raw_u + 0.5),
		.y = fmod(r / conf.radius, 1),
	});
}

static t_checkers	get_cap_checkers(t_object *circ, t_checkers root)
{
	const t_circle_conf	conf = *(t_circle_conf *)circ->conf;
	double				height;

	if (conf.parent->type == OBJ_CYLINDER)
		height = root.height * conf.radius
			/ (((t_cylinder_conf *)conf.parent->conf)->height
				+ conf.radius * 2);
	else
		height = root.height;
	return (create_checkers(root.width, height, root.color_b, root.color_a));
}

static t_rgb	get_color_at(t_object *circ, t_vec3 point)
{
	const t_circle_conf	conf = *(t_circle_conf *)circ->conf;
	const t_checkers	root = create_cylindrical_checkers(conf.parent);
	const t_checkers	checkers = get_cap_checkers(circ, root);
	const t_vec3		circular_point = circular_map(circ, point);

	return (get_checker_color_at(checkers, circular_point));
}

bool	hit_circle(t_object *circ, t_ray ray, double tmin, t_hit_record *rec)
{
	const t_circle_conf	conf = *(t_circle_conf *)circ->conf;
	t_object			plane;

	plane = (t_object){
		.type = OBJ_PLANE,
		.conf = &(t_plane_conf){
		.point = conf.center,
		.normal = conf.normal,
		.color = conf.color},
		.material = circ->material
	};
	if (!hit_plane(&plane, ray, tmin, rec)
		|| !(vec3_distance(rec->point, conf.center) < conf.radius))
		return (false);
	rec->object_color = get_color_at(circ, rec->point);
	return (true);
}
