/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 04:36:05 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 04:36:07 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

# include "camera.h"
# include "mlx_utils.h"
# include "parser.h"
# include "ray.h"

void	render_scene(t_mlx *mlx, t_scene *scene);

// internal
t_rgb	ray_color(t_scene *scene, t_ray ray);

#endif
