/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:50:44 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 22:19:55 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// reflect
// calculate the direction of the reflected ray
t_vec3	vec3_reflect(t_vec3 v, t_vec3 normal)
{
	v = vec3_unit(v);
	normal = vec3_unit(normal);
	return (vec3_sub(v, vec3_scale(2 * vec3_dot(v, normal), normal)));
}
