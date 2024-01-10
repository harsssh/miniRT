/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:55:59 by kemizuki          #+#    #+#             */
/*   Updated: 2024/01/02 18:48:03 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static t_vec3	circular_map(t_object *circ, t_vec3 p)
{
	const t_circle_conf	conf = *(t_circle_conf *)circ->conf;
	const t_vec3		planar_uv = fix_by_axis(conf.normal, conf.center, p);
	const double		theta = atan2(planar_uv.x, planar_uv.z);
	const double		raw_u = theta / (2 * M_PI);
	const double		r = vec3_length(planar_uv);

	return ((t_vec3){
		.x = 1 - (raw_u + 0.5),
		.y = r / conf.radius,
	});
}

static t_checkers	get_cap_checkers(t_object *circ)
{
	const t_circle_conf	conf = *(t_circle_conf *)circ->conf;
	t_checkers			root;
	double				height;

	height = 0;
	if (conf.parent->type == OBJ_CYLINDER)
	{
		root = create_cylindrical_checkers(conf.parent);
		height = root.height * conf.radius
			/ (get_cylindrical_base_height(conf.parent));
	}
	else if (conf.parent->type == OBJ_CONE)
	{
		root = create_conical_checkers(conf.parent);
		height = root.height * conf.radius
			/ get_conical_base_height(conf.parent);
	}
	else
		exit_with_error(EXIT_FAILURE, "unexpected object type");
	height = ft_odd(ceil(height));
	return (create_checkers(root.width, height, circ));
}

static t_rgb	get_color_at(t_object *circ, t_vec3 point)
{
	const t_circle_conf	conf = *(t_circle_conf *)circ->conf;
	const t_checkers	checkers = get_cap_checkers(circ);
	const t_vec3		circular_point = circular_map(circ, point);

	if (!circ->material.checker)
		return (conf.color);
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
