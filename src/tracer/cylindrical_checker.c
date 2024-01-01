/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindrical_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:48:27 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/02 07:41:52 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include "debug.h"

static t_vec3	fix_by_axis(t_object *cyl, t_vec3 p)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	const t_vec3			translated_p = vec3_sub(p, conf.center);
	t_vec3					e1;
	t_vec3					e2;

	if (vec3_equal(conf.axis, vec3_axis_y()))
		return (translated_p);
	e1 = vec3_cross(conf.axis, vec3_axis_x());
	if (vec3_equal(e1, vec3_zero()))
		e1 = vec3_cross(conf.axis, vec3_axis_z());
	e1 = vec3_normalize(e1);
	e2 = vec3_normalize(vec3_cross(conf.axis, e1));
	return ((t_vec3){
		.x = vec3_dot(e1, translated_p),
		.y = vec3_dot(conf.axis, translated_p),
		.z = vec3_dot(e2, translated_p),
	});
}

static t_vec3	cylindrical_map(t_object *cyl, t_vec3 p)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	const t_vec3			fixed_p = fix_by_axis(cyl, p);
	const double			theta = atan2(fixed_p.x, fixed_p.z);
	const double			raw_u = theta / (2 * M_PI);

	return ((t_vec3){
		.x = 1 - (raw_u + 0.5),
		.y = fmod(fixed_p.y / conf.height, 1),
	});
}

t_checkers	create_cylindrical_checkers(t_object *cyl)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	int						width;
	int						height;

	set_checker_ratio(conf.radius * 2 * M_PI, conf.height + conf.radius * 2,
		&width, &height);
	if (height % 2)
		height++;
	if (width % 2)
		width++;
	return (create_checkers(width, height, conf.color, color_b()));
}

static t_checkers	get_side_checkers(t_object *cyl, t_checkers root)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	const double			height = root.height * conf.height
		/ (conf.height + conf.radius * 2);

	return (create_checkers(root.width, height, root.color_a, root.color_b));
}

t_rgb	get_cylindrical_color_at(t_object *cyl, t_vec3 point)
{
	const t_checkers	root = create_cylindrical_checkers(cyl);
	const t_checkers	checkers = get_side_checkers(cyl, root);
	const t_vec3		cylindrical_point = cylindrical_map(cyl, point);

	print_vec(cylindrical_point,true);
	return (get_checker_color_at(checkers, cylindrical_point));
}
