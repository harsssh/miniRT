/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_by_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:45:35 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/02 18:46:01 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_vec3	fix_by_axis(t_vec3 axis, t_vec3 center, t_vec3 p)
{
	const t_vec3			translated_p = vec3_sub(p, center);
	t_vec3					e1;
	t_vec3					e2;

	if (vec3_parallel(axis, vec3_axis_y()))
		return (translated_p);
	e1 = vec3_cross(axis, vec3_axis_x());
	if (vec3_parallel(e1, vec3_zero()))
		e1 = vec3_cross(axis, vec3_axis_z());
	e1 = vec3_normalize(e1);
	e2 = vec3_normalize(vec3_cross(axis, e1));
	return ((t_vec3){
		.x = vec3_dot(e1, translated_p),
		.y = vec3_dot(axis, translated_p),
		.z = vec3_dot(e2, translated_p),
	});
}
