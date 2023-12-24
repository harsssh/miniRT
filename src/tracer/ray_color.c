/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 04:52:36 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 06:51:42 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_rgb	ray_color(t_scene *scene, t_ray ray)
{
	t_hit_record	rec;
	t_rgb			color;
	t_node			*light_node;
	t_light_conf	light;

	if (!find_nearest_hit(scene, ray, &rec))
		return (vec3_zero());
	color = vec3_scale(rgb_normalize(scene->ambient.color),
			scene->ambient.ratio);
	light_node = scene->lights->head;
	while (light_node != NULL)
	{
		light = *(t_light_conf *)light_node->data;
		if (is_illuminated(scene, light, rec))
			color = vec3_add_3(color, calculate_diffuse(light, rec),
					calculate_specular(light, ray, rec));
		light_node = light_node->next;
	}
	return (vec3_clamp(color, 0, 1));
}
