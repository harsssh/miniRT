/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:58:11 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 16:58:13 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// lerp
// linear interpolation
t_vec3	vec3_lerp(t_vec3 a, t_vec3 b, double t)
{
	return (vec3_add(vec3_scale(1 - t, a), vec3_scale(t, b)));
}

// slerp
// spherical linear interpolation
t_vec3	vec3_slerp(t_vec3 a, t_vec3 b, double t)
{
	t_radian	angle;
	t_vec3		axis;

	angle = vec3_angle(a, b);
	axis = vec3_cross(a, b);
	return (vec3_rotate(a, angle * t, axis));
}
