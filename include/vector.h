/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:04:29 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 04:18:42 by kemizuki         ###   ########.fr       */
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

typedef t_vec3	t_rgb;
typedef double	t_radian;
typedef double	t_degree;

// constructors
t_vec3			vec3(double x, double y, double z);
t_vec3			vec3_zero(void);
t_vec3			vec3_one(void);
t_vec3			vec3_axis_x(void);
t_vec3			vec3_axis_y(void);
t_vec3			vec3_axis_z(void);

// getters
double			vec3_get_x(t_vec3 a);
double			vec3_get_y(t_vec3 a);
double			vec3_get_z(t_vec3 a);
double			rgb_get_r(t_rgb a);
double			rgb_get_g(t_rgb a);
double			rgb_get_b(t_rgb a);

// operations
t_vec3			vec3_add(t_vec3 a, t_vec3 b);
t_vec3			vec3_sub(t_vec3 a, t_vec3 b);
t_vec3			vec3_cross(t_vec3 a, t_vec3 b);
t_vec3			vec3_scale(t_vec3 a, double scale);
t_vec3			vec3_div(t_vec3 a, double divisor);

double			vec3_dot(t_vec3 a, t_vec3 b);
double			vec3_length(t_vec3 a);
double			vec3_length_squared(t_vec3 a);
double			vec3_distance(t_vec3 a, t_vec3 b);
t_radian		vec3_angle(t_vec3 a, t_vec3 b);

t_vec3			vec3_rotate(t_vec3 a, t_radian angle, t_vec3 axis);
t_vec3			vec3_rotate_x(t_vec3 a, t_radian angle);
t_vec3			vec3_rotate_y(t_vec3 a, t_radian angle);
t_vec3			vec3_rotate_z(t_vec3 a, t_radian angle);

// comparison
bool			vec3_equal(t_vec3 a, t_vec3 b);
bool			vec3_not_equal(t_vec3 a, t_vec3 b);

// utility
t_vec3			vec3_normalize(t_vec3 a);
t_vec3			vec3_negate(t_vec3 a);
t_vec3			vec3_project(t_vec3 v, t_vec3 onto);
t_vec3			vec3_add_3(t_vec3 a, t_vec3 b, t_vec3 c);
t_vec3			vec3_add_scaled(t_vec3 a, t_vec3 b, double t);

t_vec3			vec3_min(t_vec3 a, double lower);
t_vec3			vec3_max(t_vec3 a, double upper);
t_vec3			vec3_clamp(t_vec3 a, double lower, double upper);

t_vec3			vec3_lerp(t_vec3 a, t_vec3 b, double t);
t_vec3			vec3_slerp(t_vec3 a, t_vec3 b, double t);

t_vec3			vec3_reflect(t_vec3 v, t_vec3 normal);

// color
int				rgb_to_int(t_rgb c);
int				rgb_to_int_255(t_rgb c);
t_rgb			rgb_normalize(t_rgb c);

#endif
