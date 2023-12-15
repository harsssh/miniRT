/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:19:25 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 12:19:27 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// unit vector
t_vec3	vec3_unit(t_vec3 a)
{
	return (vec3_scale(a, 1 / vec3_length(a)));
}

// negate
t_vec3	vec3_negate(t_vec3 a)
{
	return (vec3_scale(a, -1));
}
