/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:28:54 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 14:29:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// rotate
// Rodrigues' rotation formula
t_vec3	vec3_rotate(t_vec3 a, t_radian angle, t_vec3 axis)
{
	t_vec3	unit_axis;
	t_vec3	comp1;
	t_vec3	comp2;

	unit_axis = vec3_unit(axis);
	comp1 = vec3_cross(unit_axis, a);
	comp2 = vec3_cross(unit_axis, comp1);
	return (vec3_add_3(
			a,
			vec3_scale(comp1, sin(angle)),
			vec3_scale(comp2, (1 - cos(angle)))
		));
}

// rotate around x-axis
t_vec3	vec3_rotate_x(t_vec3 a, t_radian angle)
{
	return (vec3_rotate(a, angle, vec3_axis_x()));
}

// rotate around y-axis
t_vec3	vec3_rotate_y(t_vec3 a, t_radian angle)
{
	return (vec3_rotate(a, angle, vec3_axis_y()));
}

// rotate around z-axis
t_vec3	vec3_rotate_z(t_vec3 a, t_radian angle)
{
	return (vec3_rotate(a, angle, vec3_axis_z()));
}
