/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:38:13 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 06:56:44 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// min
t_vec3	vec3_min(t_vec3 a, double lower)
{
	return (vec3(fmin(a.x, lower), fmin(a.y, lower), fmin(a.z, lower)));
}

// max
t_vec3	vec3_max(t_vec3 a, double upper)
{
	return (vec3(fmax(a.x, upper), fmax(a.y, upper), fmax(a.z, upper)));
}

// clamp
t_vec3	vec3_clamp(t_vec3 a, double lower, double upper)
{
	return (vec3_min(vec3_max(a, lower), upper));
}
