#include "config.h"

// A [ratio] [color]
t_ambient_conf parse_ambient(const char *line) {
	char **split;

	if (line == NULL || ft_strncmp(line, "A", 1) != 0)
		exit_with_error(EXIT_PARSE_ERROR);
	split = split_space(line);
	if (array_size(split) != 3)
		exit_with_error(EXIT_PARSE_ERROR);
	return ((t_ambient_conf) {
		.ratio = parse_double(split[1]),
		.color = parse_rgb(split[2])
	});
}

// C [position] [orientation] [fov]
t_camera_conf parse_camera(const char *line) {
	char **split;
	unsigned int fov;
	t_vec3 orient;

	if (line == NULL || ft_strncmp(line, "C", 1) != 0)
		exit_with_error(EXIT_PARSE_ERROR);
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR);
	orient = parse_vec3(split[2]);
	fov = parse_uint(split[3]);
	if (!is_normalized(orient) || fov > 180)
		exit_with_error(EXIT_PARSE_ERROR);
	return ((t_camera_conf) {
		.position = parse_vec3(split[1]),
		.orientation = orient,
		.fov = (double)fov
	});
}

// L [position] [brightness] [color]
t_light_conf parse_light(const char *line) {
	char **split;

	if (line == NULL || ft_strncmp(line, "L", 1) != 0)
		exit_with_error(EXIT_PARSE_ERROR);
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR);
	return ((t_light_conf) {
		.position = parse_vec3(split[1]),
		.brightness = parse_double(split[2]),
		.color = parse_rgb(split[3])
	});
}

// pl [point] [normal] [color]
t_plane_conf parse_plane(const char *line) {
	char **split;
	t_vec3 normal;

	if (line == NULL || ft_strncmp(line, "pl", 2) != 0)
		exit_with_error(EXIT_PARSE_ERROR);
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR);
	normal = parse_vec3(split[2]);
	if (!is_normalized(normal))
		exit_with_error(EXIT_PARSE_ERROR);
	return ((t_plane_conf) {
		.point = parse_vec3(split[1]),
		.normal = normal,
		.color = parse_rgb(split[3])
	});
}

// sp [center] [diameter] [color]
t_sphere_conf parse_sphere(const char *line) {
	char **split;

	if (line == NULL || ft_strncmp(line, "sp", 2) != 0)
		exit_with_error(EXIT_PARSE_ERROR);
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR);
	return ((t_sphere_conf) {
		.center = parse_vec3(split[1]),
		.diameter = parse_double(split[2]),
		.color = parse_rgb(split[3])
	});
}

// cy [center] [axis] [diameter] [height] [color]
t_cylinder_conf parse_cylinder(const char *line) {
	char **split;
	t_vec3 axis;

	if (line == NULL || ft_strncmp(line, "cy", 2) != 0)
		exit_with_error(EXIT_PARSE_ERROR);
	split = split_space(line);
	if (array_size(split) != 6)
		exit_with_error(EXIT_PARSE_ERROR);
	axis = parse_vec3(split[2]);
	if (!is_normalized(axis))
		exit_with_error(EXIT_PARSE_ERROR);
	return ((t_cylinder_conf) {
		.center = parse_vec3(split[1]),
		.axis = axis,
		.diameter = parse_double(split[3]),
		.height = parse_double(split[4]),
		.color = parse_rgb(split[5])
	});
}
