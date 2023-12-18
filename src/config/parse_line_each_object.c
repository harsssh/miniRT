/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:39:09 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 21:39:11 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

// pl [point] [normal] [color]
t_plane_conf	parse_plane(const char *line)
{
	char			**split;
	t_vec3			normal;
	t_plane_conf	conf;

	if (line == NULL || ft_strncmp(line, "pl", 2) != 0)
		exit_with_error(EXIT_PARSE_ERROR, "invalid type");
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR, "plane: invalid format");
	normal = parse_vec3(split[2]);
	if (!is_normalized(normal))
		exit_with_error(EXIT_FAILURE, "plane: invalid value");
	conf = (t_plane_conf){
		.point = parse_vec3(split[1]),
		.normal = normal,
		.color = parse_rgb(split[3])};
	free_array(split);
	return (conf);
}

// sp [center] [diameter] [color]
t_sphere_conf	parse_sphere(const char *line)
{
	char			**split;
	t_sphere_conf	conf;

	if (line == NULL || ft_strncmp(line, "sp", 2) != 0)
		exit_with_error(EXIT_PARSE_ERROR, "invalid type");
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR, "sphere: invalid format");
	conf = (t_sphere_conf){
		.center = parse_vec3(split[1]),
		.diameter = parse_double(split[2]),
		.color = parse_rgb(split[3])};
	free_array(split);
	return (conf);
}

// cy [center] [axis] [diameter] [height] [color]
t_cylinder_conf	parse_cylinder(const char *line)
{
	char			**split;
	t_vec3			axis;
	t_cylinder_conf	conf;

	if (line == NULL || ft_strncmp(line, "cy", 2) != 0)
		exit_with_error(EXIT_PARSE_ERROR, "invalid type");
	split = split_space(line);
	if (array_size(split) != 6)
		exit_with_error(EXIT_PARSE_ERROR, "cylinder: invalid format");
	axis = parse_vec3(split[2]);
	if (!is_normalized(axis))
		exit_with_error(EXIT_FAILURE, "cylinder: invalid value");
	conf = (t_cylinder_conf){
		.center = parse_vec3(split[1]),
		.axis = axis,
		.diameter = parse_double(split[3]),
		.height = parse_double(split[4]),
		.color = parse_rgb(split[5])};
	free_array(split);
	return (conf);
}

// co [center] [axis] [diameter] [height] [color]
t_cone_conf	parse_cone(const char *line)
{
	char		**split;
	t_vec3		axis;
	t_cone_conf	conf;

	if (line == NULL || ft_strncmp(line, "co", 2) != 0)
		exit_with_error(EXIT_PARSE_ERROR, "invalid type");
	split = split_space(line);
	if (array_size(split) != 6)
		exit_with_error(EXIT_PARSE_ERROR, "cone: invalid format");
	axis = parse_vec3(split[2]);
	if (!is_normalized(axis))
		exit_with_error(EXIT_FAILURE, "cone: invalid value");
	conf = (t_cone_conf){
		.center = parse_vec3(split[1]),
		.axis = axis,
		.diameter = parse_double(split[3]),
		.height = parse_double(split[4]),
		.color = parse_rgb(split[5])};
	free_array(split);
	return (conf);
}
