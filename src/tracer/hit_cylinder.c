/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:57:02 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/26 10:26:14 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static bool	set_rec_side(t_object *cyl, t_ray ray, double t, t_hit_record *rec)
{
	rec->t = t;
	rec->point = ray_at(ray, t);
	rec->normal = get_cylindrical_normal(cyl, rec, cylindrical_map(cyl, rec->point));
	rec->material = cyl->material;
	rec->object_color = get_cylindrical_color_at(cyl, rec->point);
	return (true);
}

static bool	is_hit_side(t_cylinder_conf conf, t_vec3 point)
{
	const t_vec3	top_center = vec3_add_scaled(conf.center,
			conf.axis, conf.height);
	const t_vec3	to_top = vec3_sub(top_center, point);
	const t_vec3	to_bottom = vec3_sub(conf.center, point);

	return (vec3_dot(to_top, conf.axis) > 0
		&& vec3_dot(to_bottom, conf.axis) < 0);
}

// Find the intersection with an infinite cylinder.
static void	calculate_side_intersection(t_cylinder_conf conf, t_ray ray,
										t_quadratic *q)
{
	const t_vec3	oc = vec3_sub(ray.origin, conf.center);
	const t_vec3	u = vec3_sub(ray.direction,
			vec3_project(ray.direction, conf.axis));
	const t_vec3	v = vec3_sub(oc, vec3_project(oc, conf.axis));

	q->a = vec3_length_squared(u);
	q->half_b = vec3_dot(u, v);
	q->c = vec3_length_squared(v) - conf.radius * conf.radius;
	solve_quadratic(q);
}

static bool	hit_cylinder_cap(t_object *cyl, t_ray ray, double tmin,
							t_hit_record *rec)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	t_object				circle;
	t_vec3					cap_normal;
	t_vec3					cap_center;

	if (vec3_dot(ray.direction, conf.axis) > 0)
	{
		cap_center = conf.center;
		cap_normal = vec3_negate(conf.axis);
	}
	else
	{
		cap_center = vec3_add_scaled(conf.center, conf.axis, conf.height);
		cap_normal = conf.axis;
	}
	circle = (t_object){
		.type = OBJ_CIRCLE,
		.conf = &(t_circle_conf){
		.center = cap_center,
		.normal = cap_normal,
		.radius = conf.radius,
		.color = conf.color,
		.parent = cyl},
		.material = cyl->material};
	return (hit_circle(&circle, ray, tmin, rec));
}

bool	hit_cylinder(t_object *cyl, t_ray ray, double tmin, t_hit_record *rec)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	t_quadratic				q;

	if (vec3_parallel(ray.direction, conf.axis))
		return (hit_cylinder_cap(cyl, ray, tmin, rec));
	calculate_side_intersection(conf, ray, &q);
	if (!q.solved)
		return (false);
	if (q.t1 > tmin && is_hit_side(conf, ray_at(ray, q.t1)))
		return (set_rec_side(cyl, ray, q.t1, rec));
	if (hit_cylinder_cap(cyl, ray, tmin, rec))
		return (true);
	if (q.t2 > tmin && is_hit_side(conf, ray_at(ray, q.t2)))
		return (set_rec_side(cyl, ray, q.t2, rec));
	return (false);
}
