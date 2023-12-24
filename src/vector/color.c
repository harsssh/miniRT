/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 04:37:16 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 04:37:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	rgb_to_int(t_rgb c)
{
	c = vec3_clamp(vec3_scale(c, 255), 0, 255);
	return (rgb_to_int_255(c));
}

int	rgb_to_int_255(t_rgb c)
{
	int r;
	int g;
	int b;

	c = vec3_clamp(c, 0, 255);
	r = (int)rgb_get_r(c);
	g = (int)rgb_get_g(c);
	b = (int)rgb_get_b(c);
	return (r << 16 | g << 8 | b);
}

t_rgb	rgb_normalize(t_rgb c)
{
	return (vec3_scale(vec3_clamp(c, 0, 255), 1.0 / 255));
}