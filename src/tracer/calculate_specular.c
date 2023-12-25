/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_specular.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:57:03 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 06:57:04 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_rgb	calculate_specular(t_light_conf light, t_ray ray, t_hit_record rec)
{
	t_vec3	light_dir;
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	specular_factor;

	light_dir = vec3_normalize(vec3_sub(light.position, rec.point));
	view_dir = vec3_normalize(vec3_negate(ray.direction));
	reflect_dir = vec3_reflect(vec3_negate(light_dir), rec.normal);
	specular_factor = pow(fmax(vec3_dot(view_dir, reflect_dir), 0.0),
			rec.material.shininess);
	return (vec3_scale(light.color, specular_factor * rec.material.specular_reflectance));
}
