/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:04:29 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 16:58:26 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdbool.h>

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef double	t_radian;

t_vec3		vec3(double x, double y, double z);
t_vec3		vec3_zero(void);
t_vec3		vec3_one(void);
t_vec3		vec3_axis_x(void);
t_vec3		vec3_axis_y(void);
t_vec3		vec3_axis_z(void);

// operations
t_vec3		vec3_add(t_vec3 a, t_vec3 b);
t_vec3		vec3_sub(t_vec3 a, t_vec3 b);
t_vec3		vec3_cross(t_vec3 a, t_vec3 b);
t_vec3		vec3_scale(t_vec3 a, double scale);

double		vec3_dot(t_vec3 a, t_vec3 b);
double		vec3_length(t_vec3 a);
double		vec3_length_squared(t_vec3 a);
double		vec3_distance(t_vec3 a, t_vec3 b);
t_radian	vec3_angle(t_vec3 a, t_vec3 b);

t_vec3		vec3_rotate(t_vec3 a, t_radian angle, t_vec3 axis);
t_vec3		vec3_rotate_x(t_vec3 a, t_radian angle);
t_vec3		vec3_rotate_y(t_vec3 a, t_radian angle);
t_vec3		vec3_rotate_z(t_vec3 a, t_radian angle);

// comparison
bool		vec3_equal(t_vec3 a, t_vec3 b);
bool		vec3_not_equal(t_vec3 a, t_vec3 b);

// utility
t_vec3		vec3_unit(t_vec3 a);
t_vec3		vec3_negate(t_vec3 a);
t_vec3		vec3_project(t_vec3 v, t_vec3 onto);
t_vec3		vec3_add_3(t_vec3 a, t_vec3 b, t_vec3 c);

t_vec3		vec3_min(t_vec3 a, t_vec3 b);
t_vec3		vec3_max(t_vec3 a, t_vec3 b);
t_vec3		vec3_clamp(t_vec3 a, t_vec3 min, t_vec3 max);

t_vec3		vec3_lerp(t_vec3 a, t_vec3 b, double t);
t_vec3		vec3_slerp(t_vec3 a, t_vec3 b, double t);

t_vec3		vec3_reflect(t_vec3 v, t_vec3 normal);
bool		vec3_is_total_reflection(t_vec3 v, t_vec3 normal, double ref_idx);
t_vec3		vec3_refract(t_vec3 v, t_vec3 normal, double ref_idx);
double		vec3_schlick(double cosine, double ref_idx);

#endif
