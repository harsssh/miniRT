#ifndef RAY_H
#define RAY_H

#include "vector.h"

typedef struct s_ray
{
	t_vec3 origin;
	t_vec3 direction;
} t_ray;

t_ray	new_ray(t_vec3 origin, t_vec3 direction);
t_vec3	ray_at(t_ray ray, double t);

#endif
