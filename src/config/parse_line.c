/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:39:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 21:39:29 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

// A [ratio] [color]
t_ambient_conf	parse_ambient(const char *line)
{
	char	**split;
	double	ratio;

	if (line == NULL || ft_strncmp(line, "A", 1) != 0)
		exit_with_error(EXIT_PARSE_ERROR, "invalid type");
	split = split_space(line);
	if (array_size(split) != 3)
		exit_with_error(EXIT_PARSE_ERROR, "ambient: invalid format");
	ratio = parse_double(split[1]);
	if (ratio < 0 || ratio > 1)
		exit_with_error(EXIT_FAILURE, "ambient: invalid lightning ratio");
	return ((t_ambient_conf){
		.ratio = ratio,
		.color = parse_rgb(split[2])});
}

// C [position] [orientation] [fov]
t_camera_conf	parse_camera(const char *line)
{
	char			**split;
	unsigned int	fov;
	t_vec3			orient;

	if (line == NULL || ft_strncmp(line, "C", 1) != 0)
		exit_with_error(EXIT_PARSE_ERROR, "invalid type");
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR, "camera: invalid format");
	orient = parse_vec3(split[2]);
	fov = parse_uint(split[3]);
	if (!is_normalized(orient) || fov > 180)
		exit_with_error(EXIT_FAILURE, "camera: invalid value");
	return ((t_camera_conf){
		.position = parse_vec3(split[1]),
		.orientation = orient,
		.fov = (double)fov});
}

// L [position] [brightness] [color]
t_light_conf	parse_light(const char *line)
{
	char	**split;
	double	brightness;

	if (line == NULL || ft_strncmp(line, "L", 1) != 0)
		exit_with_error(EXIT_PARSE_ERROR, "invalid type");
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR, "light: invalid format");
	brightness = parse_double(split[2]);
	if (brightness < 0 || brightness > 1)
		exit_with_error(EXIT_FAILURE, "light: invalid brightness");
	return ((t_light_conf){
		.position = parse_vec3(split[1]),
		.brightness = brightness,
		.color = parse_rgb(split[3])});
}
