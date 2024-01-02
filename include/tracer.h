/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 04:36:05 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/30 14:33:46 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

# include "camera.h"
# include "mlx_utils.h"
# include "ray.h"
# include "scene.h"

void			render_scene(t_mlx *mlx, t_scene *scene);

// internal
typedef struct s_hit_record
{
	double		t;
	t_vec3		point;
	t_vec3		normal;
	t_material	material;
	t_rgb		object_color;
}				t_hit_record;

t_rgb			ray_color(t_scene *scene, t_ray ray);
bool			find_nearest_hit(t_scene *scene, t_ray ray, t_hit_record *rec);
bool			is_illuminated(t_scene *scene, t_light_conf light,
					t_hit_record rec);
t_rgb			calculate_diffuse(t_light_conf light, t_hit_record rec);
t_rgb			calculate_specular(t_light_conf light, t_ray ray,
					t_hit_record rec);

typedef bool	(*t_hit_func)(t_object *, t_ray, double, t_hit_record *);
t_hit_func		get_hit_func(t_object *obj);
bool			hit_sphere(t_object *sphere, t_ray ray, double tmin,
					t_hit_record *rec);
bool			hit_plane(t_object *plane, t_ray ray, double tmin,
					t_hit_record *rec);
bool			hit_cylinder(t_object *cyl, t_ray ray, double tmin,
					t_hit_record *rec);
bool			hit_circle(t_object *circ, t_ray ray, double tmin,
					t_hit_record *rec);
bool			hit_cone(t_object *cone, t_ray ray, double tmin,
					t_hit_record *rec);

typedef struct s_quadratic
{
	double		a;
	double		half_b;
	double		c;
	bool		solved;
	double		t1;
	double		t2;
}				t_quadratic;
void			solve_quadratic(t_quadratic *q);

typedef struct s_checkers
{
	double		width;
	double		height;
	t_rgb		color_a;
	t_rgb		color_b;
}				t_checkers;
t_checkers		create_checkers(double width, double height, t_object *obj);
t_checkers		create_cylindrical_checkers(t_object *cyl);
t_rgb			get_checker_color_at(t_checkers checkers, t_vec3 uv);
void			set_checker_ratio(double a, double b, int *pa, int *pb);
t_checkers		invert(t_checkers checkers);
t_rgb			get_cylindrical_color_at(t_object *cyl, t_vec3 point);

t_vec3			fix_by_axis(t_object *cyl, t_vec3 center, t_vec3 p);

#endif
