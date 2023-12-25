/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_illuminated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:57:08 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 06:57:10 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

bool	is_illuminated(t_scene *scene, t_light_conf light, t_hit_record rec)
{
	const t_ray shadow_ray = new_ray(rec.point,
		vec3_normalize(vec3_sub(light.position, rec.point)));
	t_hit_func hit_func;
	t_hit_record shadow_rec;
	t_node	*obj_node;

	obj_node = scene->objects->head;
	while (obj_node)
	{
		hit_func = get_hit_func(obj_node->data);
		if (hit_func != NULL
			&& hit_func(obj_node->data, shadow_ray, 1e-3, &shadow_rec))
			return (false);
		obj_node = obj_node->next;
	}
	return (true);
}
