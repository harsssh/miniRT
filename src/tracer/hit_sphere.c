/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:48:56 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/26 06:55:48 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static void	set_rec(t_object *sphere, t_ray ray, double t, t_hit_record *rec)
{
	const t_sphere_conf	conf = *(t_sphere_conf *)sphere->conf;

	rec->t = t;
	rec->point = ray_at(ray, t);
	rec->normal = vec3_div(vec3_sub(rec->point, conf.center), conf.radius);
	rec->material = sphere->material;
	rec->object_color = conf.color;
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
