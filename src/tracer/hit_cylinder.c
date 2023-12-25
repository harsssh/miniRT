/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:57:02 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/26 07:00:00 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static bool	set_rec_side(t_object *cyl, t_ray ray, double t, t_hit_record *rec)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	t_vec3					diff;

	rec->t = t;
	rec->point = ray_at(ray, t);
	diff = vec3_sub(rec->point, conf.center);
	rec->normal = vec3_normalize(vec3_sub(diff, vec3_project(diff, conf.axis)));
	rec->material = cyl->material;
	rec->object_color = conf.color;
	return (true);
}

static bool	is_hit_side(t_cylinder_conf conf, t_vec3 point)
{
	const t_vec3	diff = vec3_sub(point, conf.center);
	const double	dist = vec3_length(vec3_project(diff, conf.axis));

	return (dist < conf.height / 2);
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
	q->c = vec3_length_squared(v) - conf.diameter * conf.diameter / 4;
	solve_quadratic(q);
}

bool	hit_cylinder_cap(t_object *cyl, t_ray ray, double tmin,
						t_hit_record *rec)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	t_object				circle;
	t_vec3					cap_normal;

	if (vec3_dot(ray.direction, conf.axis) < 0)
		cap_normal = conf.axis;
	else
		cap_normal = vec3_negate(conf.axis);
	circle = (t_object){
		.type = OBJ_CIRCLE,
		.conf = &(t_circle_conf){
		.center = vec3_add_scaled(conf.center, cap_normal, conf.height / 2),
		.normal = cap_normal,
		.diameter = conf.diameter,
		.color = conf.color},
		.material = cyl->material
	};
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
