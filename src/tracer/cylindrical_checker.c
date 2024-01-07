/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindrical_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:48:27 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/02 18:47:16 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static t_vec3	cylindrical_map(t_object *cyl, t_vec3 p)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	const t_vec3			fixed_p = fix_by_axis(conf.axis, conf.center, p);
	const double			theta = atan2(fixed_p.x, fixed_p.z);
	const double			raw_u = theta / (2 * M_PI);

	return ((t_vec3){
		.x = 1 - (raw_u + 0.5),
		.y = fmod(fixed_p.y / conf.height, 1),
	});
}

double	get_cylindrical_base_height(t_object *cyl)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;

	return (conf.height + conf.radius * 2);
}

t_checkers	create_cylindrical_checkers(t_object *cyl)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	int						width;
	int						height;

	set_checker_ratio(conf.radius * 2 * M_PI, get_cylindrical_base_height(cyl),
		&width, &height);
	width = ft_even(width);
	height = ft_even(width);
	return (create_checkers(width, height, cyl));
}

static t_checkers	get_side_checkers(t_object *cyl, t_checkers root)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	const double			height = root.height * conf.height
		/ (conf.height + conf.radius * 2);

	return (create_checkers(root.width, height, cyl));
}

t_rgb	get_cylindrical_color_at(t_object *cyl, t_vec3 point)
{
	const t_cylinder_conf	conf = *(t_cylinder_conf *)cyl->conf;
	const t_checkers		root = create_cylindrical_checkers(cyl);
	const t_checkers		checkers = get_side_checkers(cyl, root);
	const t_vec3			cylindrical_point = cylindrical_map(cyl, point);

	if (!cyl->material.checker)
		return (conf.color);
	return (get_checker_color_at(checkers, cylindrical_point));
}
