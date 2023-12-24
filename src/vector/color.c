#include "vector.h"

int	rgb_to_int(t_rgb c)
{
	c = vec3_scale(c, 255);
	return (rgb_to_int_255(c));
}

int	rgb_to_int_255(t_rgb c)
{
	int		result;

	result = 0;
	result |= ((int)(c.x) & 0xff) << 16;
	result |= ((int)(c.y) & 0xff) << 8;
	result |= ((int)(c.z) & 0xff);
	return (result);
}