/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 02:30:39 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/30 16:18:15 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_vec3	planar_map(t_object *plane, t_vec3 p)
{
	const t_plane_conf	conf = *(t_plane_conf *)plane->conf;
	t_vec3				e1;
	t_vec3				e2;
	double				u;
	double				v;

	e1 = vec3_cross(conf.normal, vec3_axis_x());
	if (vec3_equal(e1, vec3_zero()))
		e1 = vec3_cross(conf.normal, vec3_axis_z());
	e1 = vec3_normalize(e1);
	e2 = vec3_normalize(vec3_cross(conf.normal, e1));
	u = vec3_dot(e1, p);
	v = vec3_dot(e2, p);
	return ((t_vec3){
		.x = u,
		.y = v,
		.z = 0,
	});
}

static t_rgb	get_color_at(t_object *plane, t_vec3 point)
{
	const t_plane_conf	conf = *(t_plane_conf *)plane->conf;
	const t_checkers	checkers = create_checkers(2, 2, conf.color, color_b());
	const t_vec3		planar_point = planar_map(plane, point);

	return (get_checker_color_at(checkers, planar_point));
}

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
	rec->object_color = get_color_at(plane, rec->point);
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
