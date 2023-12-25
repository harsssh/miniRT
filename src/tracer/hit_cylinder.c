#include "tracer.h"

static void	set_rec(t_object *cyl, t_ray ray, double t, t_hit_record *rec)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	t_vec3					diff;

	rec->t = t;
	rec->point = ray_at(ray, t);
	diff = vec3_sub(rec->point, conf.center);
	rec->normal = vec3_normalize(vec3_sub(diff, vec3_project(diff, conf.axis)));
	rec->material = cyl->material;
	rec->object_color = conf.color;
}

static bool	solve(t_cylinder_conf conf, t_ray ray, double *t1, double *t2)
{
	const t_vec3	oc = vec3_sub(ray.origin, conf.center);
	const t_vec3	u = vec3_sub(ray.direction, vec3_project(ray.direction, conf.axis));
	const t_vec3	v = vec3_sub(oc, vec3_project(oc, conf.axis));
	t_quadratic		q;

	q.a = vec3_length_squared(u);
	q.half_b = vec3_dot(u, v);
	q.c = vec3_length_squared(v) - conf.diameter * conf.diameter / 4;
	solve_quadratic(&q);
	if (!q.solved)
		return (false);
	*t1 = q.t1;
	*t2 = q.t2;
	return (true);
}

bool	hit_cylinder(t_object *cyl, t_ray ray, double tmin, t_hit_record *rec)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	double					t1;
	double					t2;

	if (!solve(conf, ray, &t1, &t2))
		return (false);
	if (t1 > tmin)
	{
		set_rec(cyl, ray, t1, rec);
		return (true);
	}
	if (t2 > tmin)
	{
		set_rec(cyl, ray, t2, rec);
		return (true);
	}
	return (false);
}
