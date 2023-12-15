/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:38:13 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 14:38:15 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// min
t_vec3	vec3_min(t_vec3 a, t_vec3 b)
{
	return (vec3(fmin(a.x, b.x), fmin(a.y, b.y), fmin(a.z, b.z)));
}

// max
t_vec3	vec3_max(t_vec3 a, t_vec3 b)
{
	return (vec3(fmax(a.x, b.x), fmax(a.y, b.y), fmax(a.z, b.z)));
}

// clamp
t_vec3	vec3_clamp(t_vec3 a, t_vec3 min, t_vec3 max)
{
	return (vec3_min(vec3_max(a, min), max));
}
