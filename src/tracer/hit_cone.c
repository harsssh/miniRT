/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:22:42 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/07 12:01:48 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static bool	set_rec(t_object *cone, t_ray ray, double t, t_hit_record *rec)
{
	const t_cone_conf	conf = *(t_cone_conf *)cone->conf;
	const t_vec3		pc = vec3_sub(ray_at(ray, t), conf.apex);

	rec->t = t;
	rec->point = ray_at(ray, t);
	rec->normal = vec3_normalize(vec3_sub(pc, vec3_scale(conf.axis,
					vec3_dot(pc, pc) / vec3_dot(conf.axis, pc))));
	rec->material = cone->material;
	rec->object_color = conf.color;
	return (true);
}

static bool	is_hit_side(t_cone_conf conf, t_ray ray, double t)
{
	const t_vec3	co = vec3_sub(ray_at(ray, t), conf.apex);

	return (vec3_dot(co, conf.axis) > 0
		&& vec3_length(vec3_project(co, conf.axis)) <= conf.height);
}

static bool	hit_cone_cap(t_object *cone, t_ray ray, double tmin,
								t_hit_record *rec)
{
	const t_cone_conf	conf = *(t_cone_conf *)cone->conf;
	t_object			circle;

	circle = (t_object){
		.type = OBJ_CIRCLE,
		.conf = &(t_circle_conf){
		.center = vec3_add_scaled(conf.apex, conf.axis, conf.height),
		.normal = conf.axis,
		.radius = conf.radius,
		.color = conf.color},
		.material = cone->material};
	return (hit_circle(&circle, ray, tmin, rec));
}

static bool	is_cap_closer(t_ray ray, double t,
				t_hit_record *rec)
{
	const double	p = vec3_dot(vec3_sub(ray_at(ray, t), ray.origin),
			ray.direction);
	const double	cap = vec3_dot(vec3_sub(rec->point, ray.origin),
			ray.direction);

	return (cap < p);
}

bool	hit_cone(t_object *cone, t_ray ray, double tmin, t_hit_record *rec)
{
	const t_cone_conf	conf = *(t_cone_conf *)cone->conf;
	t_quadratic			q;
	const double		cos_2 = pow(cos(atan2(conf.radius, conf.height)), 2);
	const t_vec3		oc = vec3_sub(ray.origin, conf.apex);

	q.a = pow(vec3_dot(ray.direction, conf.axis), 2)
		- vec3_length_squared(ray.direction) * cos_2;
	q.half_b = vec3_dot(ray.direction, conf.axis) * vec3_dot(oc, conf.axis)
		- vec3_dot(ray.direction, vec3_scale(oc, cos_2));
	q.c = pow(vec3_dot(oc, conf.axis), 2)
		- vec3_dot(oc, vec3_scale(oc, cos_2));
	solve_quadratic(&q);
	if (!q.solved)
		return (false);
	if (hit_cone_cap(cone, ray, tmin, rec) && is_cap_closer(ray, q.t1, rec))
		return (true);
	if (q.t1 > tmin && is_hit_side(conf, ray, q.t1))
		return (set_rec(cone, ray, q.t1, rec));
	if (hit_cone_cap(cone, ray, tmin, rec) && is_cap_closer(ray, q.t2, rec))
		return (true);
	if (q.t2 > tmin && is_hit_side(conf, ray, q.t2))
		return (set_rec(cone, ray, q.t2, rec));
	if (hit_cone_cap(cone, ray, tmin, rec))
		return (true);
	return (false);
}
