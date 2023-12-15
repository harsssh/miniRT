/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:19:25 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 12:19:27 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// unit vector
t_vec3	vec3_unit(t_vec3 a)
{
	return (vec3_scale(1 / vec3_length(a), a));
}

// negate
t_vec3	vec3_negate(t_vec3 a)
{
	return (vec3_scale(-1, a));
}

// projection
t_vec3	vec3_project(t_vec3 v, t_vec3 onto)
{
	return (vec3_scale(vec3_dot(v, onto) / vec3_dot(onto, onto), onto));
}

// addition of 3 vectors
t_vec3	vec3_add_3(t_vec3 a, t_vec3 b, t_vec3 c)
{
	return (vec3_add(vec3_add(a, b), c));
}
