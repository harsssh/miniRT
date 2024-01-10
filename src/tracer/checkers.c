/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:53:16 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/31 21:47:55 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include <limits.h>

t_checkers	create_checkers(double width, double height, t_object *obj)
{
	t_rgb	color_a;

	if (obj->type == OBJ_CYLINDER)
		color_a = ((t_cylinder_conf *)obj->conf)->color;
	else if (obj->type == OBJ_CIRCLE)
		color_a = ((t_circle_conf *)obj->conf)->color;
	else if (obj->type == OBJ_CONE)
		color_a = ((t_cone_conf *)obj->conf)->color;
	else if (obj->type == OBJ_PLANE)
		color_a = ((t_plane_conf *)obj->conf)->color;
	else if (obj->type == OBJ_SPHERE)
		color_a = ((t_sphere_conf *)obj->conf)->color;
	else
		color_a = white();
	return ((t_checkers){
		.width = width,
		.height = height,
		.color_a = color_a,
		.color_b = obj->material.check_color,
	});
}

t_rgb	get_checker_color_at(t_checkers checkers, t_vec3 uv)
{
	const int	u2 = floor(uv.x * checkers.width);
	const int	v2 = floor(uv.y * checkers.height);

	if ((u2 + v2) % 2 == 0)
		return (checkers.color_a);
	return (checkers.color_b);
}

void	set_checker_ratio(double a, double b, int *pa, int *pb)
{
	while (a < INT_MAX / 10 && b < INT_MAX / 10 && (a < 2 || b < 2))
	{
		a *= 10;
		b *= 10;
	}
	if (pa != NULL)
		*pa = a;
	if (pb != NULL)
		*pb = b;
}
