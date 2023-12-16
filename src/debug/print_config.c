/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:13:40 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 16:14:15 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		printf(", ratio=%.1lf, color=", light->brightness);
		print_rgb(light->color, true);
		++i;
		node = node->next;
	}
}

static void	print_object(const t_object *obj)
{
	if (obj->type == OBJ_SPHERE)
	{
		printf("Sphere: center=");
		print_vec(((t_sphere_conf *)obj->object)->center, false);
		printf(", diameter=%.1lf, color=",
				(((t_sphere_conf *)obj->object))->diameter);
		print_rgb((((t_sphere_conf *)obj->object))->color, true);
	}
	else if (obj->type == OBJ_PLANE)
	{
		printf("Plane: point=");
		print_vec((((t_plane_conf *)obj->object))->point, false);
		printf(", normal=");
		print_vec((((t_plane_conf *)obj->object))->normal, false);
		printf(", color=");
		print_rgb((((t_plane_conf *)obj->object))->color, true);
	}
	else if (obj->type == OBJ_CYLINDER)
	{
		printf("Cylinder: center=");
		print_vec(((t_cylinder_conf *)(obj->object))->center, false);
		printf(", axis=");
		print_vec((((t_cylinder_conf *)obj->object))->axis, false);
		printf(", diameter=%.1lf, height=%.1lf, color=",
				(((t_cylinder_conf *)obj->object))->diameter,
				(((t_cylinder_conf *)obj->object))->height);
		print_rgb((((t_cylinder_conf *)obj->object))->color, true);
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
		print_object(obj);
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
