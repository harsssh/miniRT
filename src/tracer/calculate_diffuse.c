/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_diffuse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:56:56 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/26 10:59:33 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_rgb	calculate_diffuse(t_light_conf light, t_hit_record rec)
{
	t_vec3	light_dir;
	double	dot;

	light_dir = vec3_normalize(vec3_sub(light.position, rec.point));
	dot = vec3_dot(light_dir, rec.normal);
	if (dot < 0)
		dot = 0;
	return (vec3_scale(vec3_mul(rec.object_color, light.color),
			dot * light.brightness * rec.material.diffuse_reflectance));
}
