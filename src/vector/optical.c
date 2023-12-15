/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:50:44 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 22:17:26 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// reflect
// calculate the direction of the reflected ray
t_vec3	vec3_reflect(t_vec3 v, t_vec3 normal)
{
	v = vec3_unit(v);
	normal = vec3_unit(normal);
	return (vec3_sub(v, vec3_scale(normal, 2 * vec3_dot(v, normal))));
}

bool	vec3_is_total_reflection(t_vec3 v, t_vec3 normal, double ref_idx)
{
	double	cos_incident;
	double	sin_refracted;

	v = vec3_unit(v);
	normal = vec3_unit(normal);
	cos_incident = fmin(vec3_dot(vec3_negate(v), normal), 1.0);
	sin_refracted = 1 / ref_idx
		* sqrt(fmax(1.0 - cos_incident * cos_incident, 0.0));
	return (sin_refracted > 1.0);
}

// refract
// calculate the direction of the refracted ray
t_vec3	vec3_refract(t_vec3 v, t_vec3 normal, double ref_idx)
{
	double	cos_incident;
	t_vec3	out_parallel;
	t_vec3	out_perp;

	v = vec3_unit(v);
	normal = vec3_unit(normal);
	if (vec3_is_total_reflection(v, normal, ref_idx))
		return (vec3_zero());
	cos_incident = fmin(vec3_dot(vec3_negate(v), normal), 1.0);
	out_parallel = vec3_scale(
			vec3_add(v, vec3_scale(normal, cos_incident)), 1 / ref_idx);
	out_perp = vec3_scale(normal,
			-sqrt(fmax(1.0 - vec3_length_squared(out_parallel), 0.0)));
	return (vec3_add(out_parallel, out_perp));
}

// schlick approximation
double	vec3_schlick(double cosine, double ref_idx)
{
	double	r0;

	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 *= r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}
