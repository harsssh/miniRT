/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:50:44 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 16:57:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// reflect
// normal must be normalized
t_vec3	vec3_reflect(t_vec3 incident, t_vec3 normal)
{
	return (vec3_sub(
			incident,
			vec3_scale(normal, 2 * vec3_dot(incident, normal))));
}

bool	vec3_is_total_reflection(t_vec3 incident, t_vec3 normal, double ref_idx)
{
	double	cos_incident;
	double	sin_refracted;

	cos_incident = fmin(vec3_dot(vec3_negate(incident), normal), 1.0);
	sin_refracted = ref_idx * sqrt(
			fmax(1.0 - cos_incident * cos_incident, 0.0));
	return (sin_refracted > 1.0);
}

// refract
// normal must be normalized
t_vec3	vec3_refract(t_vec3 incident, t_vec3 normal, double ref_idx)
{
	double	cos_incident;
	t_vec3	out_parallel;
	t_vec3	out_perp;

	if (vec3_is_total_reflection(incident, normal, ref_idx))
		return (vec3_zero());
	cos_incident = fmin(vec3_dot(vec3_negate(incident), normal), 1.0);
	out_parallel = vec3_scale(vec3_add(
				incident, vec3_scale(normal, cos_incident)), ref_idx);
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
