#include "vector.h"

// scalar division
t_vec3	vec3_div(t_vec3 a, double divisor)
{
	return (vec3(a.x / divisor, a.y / divisor, a.z / divisor));
}

// element-wise multiplication
t_vec3	vec3_mul(t_vec3 a, t_vec3 b)
{
	return (vec3(a.x * b.x, a.y * b.y, a.z * b.z));
}
