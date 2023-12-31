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

t_checkers	create_checkers(double width, double height, t_rgb color_a,
						t_rgb color_b)
{
	return ((t_checkers){
		.width = width,
		.height = height,
		.color_a = color_a,
		.color_b = color_b,
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
