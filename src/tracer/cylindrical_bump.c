#include "tracer.h"

static t_vec3	uv_to_cylindrical(t_object *cyl, t_vec3 uv)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	const double 			theta = (1 - (uv.x + 0.5)) * M_PI;
	const double 			height = uv.y * conf.height;

	return ((t_vec3){
		.x = conf.radius * sin(theta),
		.y = height,
		.z = conf.radius * cos(theta),
	});
}

t_vec3	get_cylindrical_normal(t_object* cyl, t_hit_record *rec, t_vec3 uv)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	const t_vec3			diff = vec3_sub(rec->point, conf.center);
	const t_vec3			normal = vec3_normalize(vec3_sub(diff, vec3_project(diff, conf.axis)));
	const t_height_map		map = cyl->material.height_map;
	t_vec_pair 				p;

	if (map.img == NULL)
		return (normal);
	p.first = vec3_normalize(vec3_sub(uv_to_cylindrical(cyl, vec3(uv.x + map.pixel_w, uv.y, uv.z)), uv_to_cylindrical(cyl, vec3(uv.x - map.pixel_w, uv.y, uv.z))));
	p.second = vec3_normalize(vec3_sub(uv_to_cylindrical(cyl, vec3(uv.x, uv.y + map.pixel_h, uv.z)), uv_to_cylindrical(cyl, vec3(uv.x, uv.y - map.pixel_h, uv.z))));
	return (get_normal_at(map, uv, p, normal));
}
