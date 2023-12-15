/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations_scalar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:20:10 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 12:20:12 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// dot product
double	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// length squared
double	vec3_length_squared(t_vec3 a)
{
	return (vec3_dot(a, a));
}

// length
double	vec3_length(t_vec3 a)
{
	return (sqrt(vec3_length_squared(a)));
}

// distance
double	vec3_distance(t_vec3 a, t_vec3 b)
{
	return (vec3_length(vec3_sub(a, b)));
}

// angle
t_radian	vec3_angle(t_vec3 a, t_vec3 b)
{
	return (acos(vec3_dot(a, b) / (vec3_length(a) * vec3_length(b))));
}
