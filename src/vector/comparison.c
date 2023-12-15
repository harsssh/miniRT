/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:20:17 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 22:29:01 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#define EPSILON 0.000000001

// equality
bool	vec3_equal(t_vec3 a, t_vec3 b)
{
	return (fabs(a.x - b.x) < EPSILON && fabs(a.y - b.y) < EPSILON
		&& fabs(a.z - b.z) < EPSILON);
}

// inequality
bool	vec3_not_equal(t_vec3 a, t_vec3 b)
{
	return (!vec3_equal(a, b));
}
