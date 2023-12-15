#include "config.h"

t_ambient_conf parse_ambient(const char *line) {
	(void) line;
	return ((t_ambient_conf) {vec3(0, 0, 0), 0});
}

t_camera_conf parse_camera(const char *line) {
	(void) line;
	return ((t_camera_conf) {vec3(0, 0, 0), vec3(0, 0, 0), 0});
}

t_light_conf parse_light(const char *line) {
	(void) line;
	return ((t_light_conf) {vec3(0, 0, 0), 0});
}

t_plane_conf parse_plane(const char *line) {
	(void) line;
	return ((t_plane_conf) {vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0)});
}

t_sphere_conf parse_sphere(const char *line) {
	(void) line;
	return ((t_sphere_conf) {vec3(0, 0, 0), 0, vec3(0, 0, 0)});
}

t_cylinder_conf parse_cylinder(const char *line) {
	(void) line;
	return ((t_cylinder_conf) {vec3(0, 0, 0), vec3(0, 0, 0), 0, 0, vec3(0, 0, 0)});
}
