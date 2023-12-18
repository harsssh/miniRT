/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:17:30 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 04:17:31 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	rgb_get_r(t_rgb a)
{
	return (a.x);
}

double	rgb_get_g(t_rgb a)
{
	return (a.y);
}

double	rgb_get_b(t_rgb a)
{
	return (a.z);
}
