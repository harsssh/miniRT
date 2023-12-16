/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:27:24 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 21:35:25 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_sphere_conf(t_sphere_conf conf)
{
	printf("Sphere: center=");
	print_vec(conf.center, false);
	printf(", diameter=%.1lf, color=", conf.diameter);
	print_rgb(conf.color, true);
}

void	print_plane_conf(t_plane_conf conf)
{
	printf("Plane: point=");
	print_vec(conf.point, false);
	printf(", normal=");
	print_vec(conf.normal, false);
	printf(", color=");
	print_rgb(conf.color, true);
}

void	print_cylinder_conf(t_cylinder_conf conf)
{
	printf("Cylinder: center=");
	print_vec(conf.center, false);
	printf(", axis=");
	print_vec(conf.axis, false);
	printf(", diameter=%.1lf, height=%.1lf, color=",
		conf.diameter, conf.height);
	print_rgb(conf.color, true);
}
