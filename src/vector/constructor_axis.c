/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_axis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:30:17 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 14:30:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// x axis
t_vec3	vec3_axis_x(void)
{
	return (vec3(1, 0, 0));
}

// y axis
t_vec3	vec3_axis_y(void)
{
	return (vec3(0, 1, 0));
}

// z axis
t_vec3	vec3_axis_z(void)
{
	return (vec3(0, 0, 1));
}
