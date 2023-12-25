/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:49:32 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 22:49:33 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_hit_func	get_hit_func(t_object *obj)
{
	if (obj->type == OBJ_SPHERE)
		return (hit_sphere);
	else if (obj->type == OBJ_PLANE)
		return (hit_plane);
	else if (obj->type == OBJ_CYLINDER)
		return (hit_cylinder);
	return (NULL);
}
