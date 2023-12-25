/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_hit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:56:49 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 06:56:50 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

bool	find_nearest_hit(t_scene *scene, t_ray ray, t_hit_record *rec)
{
	t_node *obj_node;
	t_hit_func hit_func;
	t_hit_record tmp_rec;
	bool hit_anything;

	hit_anything = false;
	obj_node = scene->objects->head;
	while (obj_node != NULL)
	{
		hit_func = get_hit_func(obj_node->data);
		if (hit_func != NULL && hit_func(obj_node->data, ray, 0, &tmp_rec))
		{
			if (!hit_anything || tmp_rec.t < rec->t)
			{
				hit_anything = true;
				*rec = tmp_rec;
			}
		}
		obj_node = obj_node->next;
	}
	return (hit_anything);
}
