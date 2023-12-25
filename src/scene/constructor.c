/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:38:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 21:38:07 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene	*new_scene(void)
{
	t_scene	*config;

	config = ft_calloc(1, sizeof(t_scene));
	config->lights = ft_list_create();
	config->objects = ft_list_create();
	return (config);
}

t_object	*new_object(t_object_type type)
{
	t_object	*object;

	object = ft_calloc(1, sizeof(t_object));
	object->type = type;
	if (type == OBJ_SPHERE)
		object->conf = ft_calloc(1, sizeof(t_sphere_conf));
	else if (type == OBJ_PLANE)
		object->conf = ft_calloc(1, sizeof(t_plane_conf));
	else if (type == OBJ_CYLINDER)
		object->conf = ft_calloc(1, sizeof(t_cylinder_conf));
	else if (type == OBJ_CONE)
		object->conf = ft_calloc(1, sizeof(t_cone_conf));
	else if (type == OBJ_CIRCLE)
		object->conf = ft_calloc(1, sizeof(t_circle_conf));
	return (object);
}
