/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 06:43:04 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 10:10:26 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "libft.h"
# include "vector.h"
# include <stdlib.h>

# define EXIT_PARSE_ERROR 2

// color: [0, 255]

// ration: [0, 1]
typedef struct s_ambient_conf
{
	t_rgb			color;
	double			ratio;
}					t_ambient_conf;

// fov: [0, 180]
typedef struct s_camera_conf
{
	t_vec3			position;
	t_vec3			orientation;
	t_degree		fov;
}					t_camera_conf;

typedef struct s_light_conf
{
	t_vec3			position;
	t_rgb			color;
	double			brightness;
}					t_light_conf;

typedef struct s_sphere_conf
{
	t_vec3			center;
	double			diameter;
	t_rgb			color;
}					t_sphere_conf;

typedef struct s_plane_conf
{
	t_vec3			point;
	t_vec3			normal;
	t_rgb			color;
}					t_plane_conf;

typedef struct s_cylinder_conf
{
	t_vec3			center;
	t_vec3			axis;
	double			diameter;
	double			height;
	t_rgb			color;
}					t_cylinder_conf;

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER
}					t_object_type;

typedef struct s_object
{
	t_object_type	type;
	void			*object;
}					t_object;

// lights: list<t_light_config>
// objects: list<t_object_config>
typedef struct s_config
{
	t_ambient_conf	ambient;
	t_camera_conf	camera;
	t_list			*lights;
	t_list			*objects;
}					t_config;

typedef struct s_parse_option
{
	int				max_light;
}					t_parse_option;

// exit with error if failed
t_config			*parse_config(const char *path, t_parse_option option);

// internal
t_ambient_conf		parse_ambient(const char *line);
t_camera_conf		parse_camera(const char *line);
t_light_conf		parse_light(const char *line);
t_plane_conf		parse_plane(const char *line);
t_sphere_conf		parse_sphere(const char *line);
t_cylinder_conf		parse_cylinder(const char *line);

// internal utils
unsigned int		parse_uint(const char *str);
double				parse_double(const char *str);
// "-20,0,5.5" -> t_vec3(-20, 0, 5.5)
t_vec3				parse_vec3(const char *str);
// "10,0,255" -> t_rgb(10, 0, 255)
t_rgb				parse_rgb(const char *str);

char 				**split_space(const char *str);
void				exit_with_error(int status);
size_t 				array_size(char **array);
bool 				is_normalized(t_vec3 vec);

#endif
