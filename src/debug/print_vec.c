/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:13:55 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 04:17:53 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_vec(t_vec3 vec, bool newline)
{
	printf("(%.1lf, %.1lf, %.1lf)", vec.x, vec.y, vec.z);
	if (newline)
		printf("\n");
}

// color is in range [0, 1]
void	print_rgb(t_rgb color, bool newline)
{
	color = vec3_scale(color, 255);
	printf("(%d, %d, %d)",
		(int)rgb_get_r(color),
		(int)rgb_get_g(color),
		(int)rgb_get_b(color));
	if (newline)
		printf("\n");
}
