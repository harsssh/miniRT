#ifndef TRACER_H
#define TRACER_H

#include "parser.h"
#include "mlx_utils.h"
#include "ray.h"
#include "camera.h"

void	render_scene(t_mlx *mlx, t_scene *scene);

// internal
t_rgb	ray_color(t_scene *scene, t_ray ray);

#endif
