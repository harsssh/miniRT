#include "tracer.h"
#include "config.h"

t_vec3	get_planar_normal(t_object *plane, t_vec3 uv)
{
	const t_plane_conf 	conf = *(t_plane_conf *)plane->conf;
	const t_height_map	map = plane->material.height_map;
	t_vec_pair			p;
	int 				ratio;

	if (map.img == NULL)
		return (conf.normal);
	set_checker_ratio(4, (double)WINDOW_WIDTH / WINDOW_HEIGHT, &ratio, NULL);
	uv = vec3_scale(uv, 1 / (double)ratio);
	p.first = vec3_cross(conf.normal, vec3_axis_x());
	if (vec3_equal(p.first, vec3_zero()))
		p.first = vec3_cross(conf.normal, vec3_axis_z());
	p.first = vec3_normalize(p.first);
	p.second = vec3_normalize(vec3_cross(conf.normal, p.first));
	return (get_normal_at(map, uv, p, conf.normal));
}
