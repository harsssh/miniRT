/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:17:39 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 04:17:41 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec3_get_x(t_vec3 a)
{
	return (a.x);
}

double	vec3_get_y(t_vec3 a)
{
	return (a.y);
}

double	vec3_get_z(t_vec3 a)
{
	return (a.z);
}
