#include "tracer.h"

static void set_rec(t_object *sphere, t_ray ray, double t, t_hit_record *rec)
{
	const t_sphere_conf conf = *(t_sphere_conf *)sphere->conf;

	rec->t = t;
	rec->point = ray_at(ray, t);
	rec->normal = vec3_div(vec3_sub(rec->point, conf.center), conf.diameter);
	rec->material = sphere->material;
	rec->object_color = conf.color;
}

static double calculate_discriminant(t_sphere_conf conf, t_ray ray, double a, double half_b)
{
	t_vec3 oc;
	double c;
	double discriminant;

	oc = vec3_sub(ray.origin, conf.center);
	c = vec3_length_squared(oc) - conf.diameter * conf.diameter;
	discriminant = half_b * half_b - a * c;
	return (discriminant);
}

bool	hit_sphere(t_object *sphere, t_ray ray, t_hit_record *rec)
{
	const t_sphere_conf conf = *(t_sphere_conf *)sphere->conf;
	double	a;
	double	half_b;
	double	discriminant;

	a = vec3_length_squared(ray.direction);
	half_b = vec3_dot(vec3_sub(ray.origin, conf.center), ray.direction);
	discriminant = calculate_discriminant(conf, ray, a, half_b);
	if (discriminant < 0)
		return (false);
	rec->t = (-half_b - sqrt(discriminant)) / a;
	if (rec->t > 0)
	{
		set_rec(sphere, ray, rec->t, rec);
		return (true);
	}
	rec->t = (-half_b + sqrt(discriminant)) / a;
	if (rec->t > 0)
	{
		set_rec(sphere, ray, rec->t, rec);
		return (true);
	}
	return (false);
}
