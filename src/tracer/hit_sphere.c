/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:48:56 by kemizuki          #+#    #+#             */
/*   Updated: 2024/01/02 07:45:23 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static t_vec3	spherical_map(t_object *sphere, t_vec3 p)
{
	const t_sphere_conf	conf = *(t_sphere_conf *)sphere->conf;
	const t_vec3		fixed_p = vec3_sub(p, conf.center);
	const double		theta = atan2(fixed_p.x, fixed_p.z);
	const double		phi = acos(fixed_p.y / conf.radius);
	const double		raw_u = theta / M_PI;

	return ((t_vec3){
		.x = 1 - (raw_u + 0.5),
		.y = phi / M_PI,
	});
}

static t_rgb	get_color_at(t_object *sphere, t_vec3 point)
{
	const t_sphere_conf	conf = *(t_sphere_conf *)sphere->conf;
	const t_checkers	checkers = create_checkers(10, 10, sphere);
	const t_vec3		spherical_point = spherical_map(sphere, point);

	if (!sphere->material.checker)
		return (conf.color);
	return (get_checker_color_at(checkers, spherical_point));
}

static void	set_rec(t_object *sphere, t_ray ray, double t, t_hit_record *rec)
{
	const t_sphere_conf	conf = *(t_sphere_conf *)sphere->conf;

	rec->t = t;
	rec->point = ray_at(ray, t);
	rec->normal = get_spherical_normal(sphere, rec, spherical_map(sphere, rec->point));
	rec->material = sphere->material;
	rec->object_color = get_color_at(sphere, rec->point);
}

bool	hit_sphere(t_object *sphere, t_ray ray, double tmin, t_hit_record *rec)
{
	const t_sphere_conf	conf = *(t_sphere_conf *)sphere->conf;
	t_quadratic			q;

	q.a = vec3_length_squared(ray.direction);
	q.half_b = vec3_dot(vec3_sub(ray.origin, conf.center), ray.direction);
	q.c = vec3_length_squared(vec3_sub(ray.origin, conf.center))
		- conf.radius * conf.radius;
	solve_quadratic(&q);
	if (!q.solved)
		return (false);
	if (q.t1 > tmin)
	{
		set_rec(sphere, ray, q.t1, rec);
		return (true);
	}
	if (q.t2 > tmin)
	{
		set_rec(sphere, ray, q.t2, rec);
		return (true);
	}
	return (false);
}
