/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 02:25:03 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/11 02:27:12 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include "scene.h"

// Returns height between 0 .. 1
static double	get_height_at(t_height_map map, t_vec3 uv)
{
	const int	x = fmod(fmod(uv.x * map.width, map.width)
			+ map.width, map.width);
	const int	y = fmod(fmod(uv.y * map.height, map.height)
			+ map.height, map.height);
	const int	*dst = map.addr + (int)(y * map.line_length
			+ x * (map.bpp / 8));

	return ((double)(*dst & 0xFF) / 255);
}

static double	get_height_diff(t_height_map map, t_vec3 uv1, t_vec3 uv2)
{
	return (get_height_at(map, uv1) - get_height_at(map, uv2));
}

t_vec3	get_normal_at(t_height_map map, t_vec3 uv, t_vec_pair p, t_vec3 normal)
{
	t_vec3	diff;

	diff.x = get_height_diff(map, vec3(uv.x - map.pixel_w, uv.y, uv.z), vec3(
				uv.x + map.pixel_w, uv.y, uv.z)) / (2 * map.pixel_w);
	diff.y = get_height_diff(map, vec3(uv.x, uv.y - map.pixel_h, uv.z), vec3(
				uv.x, uv.y - map.pixel_h, uv.z)) / (2 * map.pixel_h);
	diff.z = HEIGHT_SCALE;
	diff = vec3_normalize(diff);
	return (vec3_add(normal, vec3_sub(
				vec3_scale(vec3_cross(p.first, normal), diff.x),
				vec3_scale(vec3_cross(p.second, normal), diff.y))));
}
