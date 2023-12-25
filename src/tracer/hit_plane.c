/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 02:30:39 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/26 02:30:40 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static void	set_rec(t_object *plane, t_ray ray, double t, t_hit_record *rec)
{
	const t_plane_conf	conf = *(t_plane_conf *)plane->conf;

	rec->t = t;
	rec->point = ray_at(ray, t);
	if (vec3_dot(ray.direction, conf.normal) < 0)
		rec->normal = conf.normal;
	else
		rec->normal = vec3_negate(conf.normal);
	rec->material = plane->material;
	rec->object_color = conf.color;
}

bool	hit_plane(t_object *plane, t_ray ray, double tmin, t_hit_record *rec)
{
	const t_plane_conf	conf = *(t_plane_conf *)plane->conf;
	double				denom;
	double				t;

	denom = vec3_dot(conf.normal, ray.direction);
	if (fabs(denom) < 1e-3)
		return (false);
	t = vec3_dot(vec3_sub(conf.point, ray.origin), conf.normal) / denom;
	if (t < tmin)
		return (false);
	set_rec(plane, ray, t, rec);
	return (true);
}
