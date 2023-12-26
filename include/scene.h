/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 06:43:04 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 02:57:11 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"
# include "vector.h"
# include <stdbool.h>
# include <stdlib.h>

# define EXIT_PARSE_ERROR 2

# define DEFAULT_AMBIENT_REFLECTANCE 1.0
# define DEFAULT_DIFFUSE_REFLECTANCE 0.5
# define DEFAULT_SPECULAR_REFLECTANCE 0.25
# define DEFAULT_SHININESS 8

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
	double			radius;
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
	double			radius;
	double			height;
	t_rgb			color;
}					t_cylinder_conf;

typedef struct s_cone_conf
{
	t_vec3			center;
	t_vec3			axis;
	double			radius;
	double			height;
	t_rgb			color;
}					t_cone_conf;

typedef struct s_circle_conf
{
	t_vec3			center;
	t_vec3			normal;
	double			radius;
	t_rgb			color;
}					t_circle_conf;

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_CONE,
	OBJ_CIRCLE
}					t_object_type;

typedef struct s_material
{
	double			diffuse_reflectance;
	double			specular_reflectance;
	double			ambient_reflectance;
	double			shininess;
	bool			checker;
	t_rgb			check_color;
	const char		*height_map;
}					t_material;

typedef struct s_object
{
	t_object_type	type;
	void			*conf;
	t_material		material;
}					t_object;

// lights: list<t_light_config>
// objects: list<t_object>
typedef struct s_scene
{
	t_ambient_conf	ambient;
	t_camera_conf	camera;
	t_list			*lights;
	t_list			*objects;
}					t_scene;

typedef struct s_parse_option
{
	unsigned int	max_light;
}					t_parse_option;

// exit with error if failed
t_scene				*parse_scene(const char *path, t_parse_option opt);
void				free_config(t_scene *config);

// internal
t_ambient_conf		parse_ambient(const char *line);
t_camera_conf		parse_camera(const char *line);
t_light_conf		parse_light(const char *line);
t_plane_conf		parse_plane(const char *line);
t_sphere_conf		parse_sphere(const char *line);
t_cylinder_conf		parse_cylinder(const char *line);
t_cone_conf			parse_cone(const char *line);
t_object			*parse_object(const char *line);

// internal utils
unsigned int		parse_uint(const char *str);
double				parse_double(const char *str);
// "-20,0,5.5" -> t_vec3(-20, 0, 5.5)
t_vec3				parse_vec3(const char *str);
// "10,0,255" -> t_rgb(10, 0, 255)
t_rgb				parse_rgb(const char *str);

char				**split_space(const char *str);
void				exit_with_error(int status, const char *message);
size_t				array_size(char **array);
bool				is_bounded(t_vec3 vec);
void				free_array(char **array);

bool				is_in_range(double value, double min, double max);
bool				is_in_range_uint(unsigned int value,
						unsigned int min, unsigned int max);

t_scene				*new_scene(void);
t_object			*new_object(t_object_type type);

typedef struct s_parse_state
{
	unsigned int	ambient_count;
	unsigned int	camera_count;
	unsigned int	light_count;
}					t_parse_state;

#endif
