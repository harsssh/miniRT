#include "tracer.h"

t_hit_func get_hit_func(t_object *obj)
{
	if (obj->type == OBJ_SPHERE)
		return (hit_sphere);
	return (NULL);
}