#include "tracer.h"

bool	hit_circle(t_object *circ, t_ray ray, double tmin, t_hit_record *rec)
{
	const t_circle_conf	conf = *(t_circle_conf *)circ->conf;
	t_object			plane;

	plane = (t_object){
		.type = OBJ_PLANE,
		.conf = &(t_plane_conf){
			.point = conf.center,
			.normal = conf.normal,
			.color = conf.color
		},
		.material = circ->material
	};
	if (!hit_plane(&plane, ray, tmin, rec))
		return (false);
	return (vec3_distance(rec->point, conf.center) < conf.diameter / 2);
}
