/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:13:55 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 16:13:56 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_vec(t_vec3 vec, bool newline)
{
	printf("(%.1lf, %.1lf, %.1lf)", vec.x, vec.y, vec.z);
	if (newline)
		printf("\n");
}

void	print_rgb(t_rgb rgb, bool newline)
{
	printf("(%d, %d, %d)", (int)rgb.x, (int)rgb.y, (int)rgb.z);
	if (newline)
		printf("\n");
}
