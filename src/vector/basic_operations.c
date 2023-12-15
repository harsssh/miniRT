/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:19:37 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 12:19:57 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// addition
t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	return (vec3(a.x + b.x, a.y + b.y, a.z + b.z));
}

// subtraction
t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	return (vec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

// cross product
t_vec3	vec3_cross(t_vec3 a, t_vec3 b)
{
	return (vec3(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}

// scalar multiplication
t_vec3	vec3_scale(t_vec3 a, double scale)
{
	return (vec3(a.x * scale, a.y * scale, a.z * scale));
}
