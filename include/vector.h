/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:04:29 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 12:04:45 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <math.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

t_vec3		vec3(double x, double y, double z);

// basic operations
t_vec3		vec3_add(t_vec3 a, t_vec3 b);
t_vec3		vec3_sub(t_vec3 a, t_vec3 b);
t_vec3		vec3_cross(t_vec3 a, t_vec3 b);
t_vec3		vec3_scale(t_vec3 a, double scale);

double		vec3_dot(t_vec3 a, t_vec3 b);
double		vec3_length(t_vec3 a);
double		vec3_length_squared(t_vec3 a);

// comparison
bool		vec3_equal(t_vec3 a, t_vec3 b);
bool		vec3_not_equal(t_vec3 a, t_vec3 b);

// utility
t_vec3		vec3_unit(t_vec3 a);
t_vec3		vec3_negate(t_vec3 a);

#endif
