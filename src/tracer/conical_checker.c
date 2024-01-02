/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conical_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:48:20 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/02 18:49:41 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static t_vec3	conical_map(t_object *cone, t_vec3 p)
{
	const t_cone_conf	conf = *(t_cone_conf *)cone->conf;
	const t_vec3		fixed_p = fix_by_axis(conf.axis,
			vec3_add_scaled(conf.apex, conf.axis, -conf.height), p);
	const double		theta = atan2(fixed_p.x, fixed_p.z);
	const double		raw_u = theta / (2 * M_PI);

	return ((t_vec3){
		.x = 1 - (raw_u + 0.5),
		.y = fixed_p.y / conf.height,
	});
}

double	get_conical_base_height(t_object *cone)
{
	const t_cone_conf	conf = *(t_cone_conf *)cone->conf;
	const double		generatrix = sqrt(pow(conf.height, 2)
			+ pow(conf.radius, 2));

	return (generatrix + conf.radius);
}

t_checkers	create_conical_checkers(t_object *cone)
{
	const t_cone_conf	conf = *(t_cone_conf *)cone->conf;
	int					width;
	int					height;

	set_checker_ratio(conf.radius * 2 * M_PI, get_conical_base_height(cone),
		&width, &height);
	width = ft_even(width);
	height = ft_even(height);
	return (create_checkers(width, height, cone));
}

static	t_checkers	get_side_checkers(t_object *cone, t_checkers root)
{
	const t_cone_conf	conf = *(t_cone_conf *)cone->conf;
	const int			height = root.height * get_conical_base_height(cone)
		/ (get_conical_base_height(cone) + conf.radius);

	return (create_checkers(root.width, (int)height, cone));
}

t_rgb	get_conical_color_at(t_object *cone, t_vec3 point)
{
	const t_cone_conf	conf = *(t_cone_conf *)cone->conf;
	const t_checkers	root = create_conical_checkers(cone);
	const t_checkers	checkers = get_side_checkers(cone, root);
	const t_vec3		conical_point = conical_map(cone, point);

	if (!cone->material.checker)
		return (conf.color);
	return (get_checker_color_at(checkers, conical_point));
}
