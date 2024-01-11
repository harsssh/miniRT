/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_illuminated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:57:08 by kemizuki          #+#    #+#             */
/*   Updated: 2024/01/11 06:08:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static bool	blocks_light(t_object *obj, t_ray shadow_ray, double light_dist)
{
	const t_hit_func	hit_func = get_hit_func(obj);
	t_hit_record		shadow_rec;

	if (hit_func != NULL && hit_func(obj, shadow_ray, 1e-3, &shadow_rec)
		&& shadow_rec.t < light_dist)
		return (true);
	return (false);
}

bool	is_illuminated(t_scene *scene, t_light_conf light, t_hit_record rec)
{
	const t_ray		shadow_ray = new_ray(rec.point,
			vec3_normalize(vec3_sub(light.position, rec.point)));
	const double	light_dist = vec3_distance(rec.point, light.position);
	t_node			*obj_node;

	if (vec3_dot(rec.normal, shadow_ray.direction) < 0)
		return (false);
	obj_node = scene->objects->head;
	while (obj_node)
	{
		if (blocks_light(obj_node->data, shadow_ray, light_dist))
			return (false);
		obj_node = obj_node->next;
	}
	return (true);
}
