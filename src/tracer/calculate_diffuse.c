/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_diffuse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:56:56 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 06:56:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_rgb	calculate_diffuse(t_light_conf light, t_hit_record rec)
{
	(void)light;
	(void)rec;
	return (vec3_zero());
}
