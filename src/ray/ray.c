#include "ray.h"

t_ray	new_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_vec3	ray_at(t_ray ray, double t)
{
	return (vec3_add_scaled(ray.origin, ray.direction, t));
}