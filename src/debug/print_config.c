/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:13:40 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 21:34:05 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "debug.h"

static void	print_lights(t_list *lights, int indent)
{
	t_node			*node;
	t_light_conf	*light;
	int				i;

	i = 0;
	node = lights->head;
	while (node)
	{
		light = node->data;
		printf("%*s%d: position=", indent, "", i);
		print_vec(light->position, false);
		printf(", brightness=%.1lf, color=", light->brightness);
		print_rgb(light->color, true);
		++i;
		node = node->next;
	}
}

static void	print_objects(t_list *objects, int indent)
{
	t_node		*node;
	t_object	*obj;

	node = objects->head;
	while (node)
	{
		obj = node->data;
		printf("%*s", indent, "");
		if (obj->type == OBJ_PLANE)
			print_plane_conf(*(t_plane_conf *)obj->object);
		else if (obj->type == OBJ_SPHERE)
			print_sphere_conf(*(t_sphere_conf *)obj->object);
		else if (obj->type == OBJ_CYLINDER)
			print_cylinder_conf(*(t_cylinder_conf *)obj->object);
		node = node->next;
	}
}

void	print_config(t_config config)
{
	printf("Ambient: ratio=%.1lf, color=", config.ambient.ratio);
	print_rgb(config.ambient.color, true);
	printf("Camera: position=");
	print_vec(config.camera.position, false);
	printf(", orientation=");
	print_vec(config.camera.orientation, false);
	printf(", fov=%.1lf\n", config.camera.fov);
	printf("Lights:\n");
	print_lights(config.lights, 2);
	printf("Objects:\n");
	print_objects(config.objects, 2);
}
