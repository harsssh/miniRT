/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:20:17 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 22:48:37 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#define EPSILON 1e-3

// equality
bool	vec3_equal(t_vec3 a, t_vec3 b)
{
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

// inequality
bool	vec3_not_equal(t_vec3 a, t_vec3 b)
{
	return (!vec3_equal(a, b));
}

bool	vec3_parallel(t_vec3 a, t_vec3 b)
{
	return (vec3_length_squared(vec3_cross(a, b)) < EPSILON);
}
