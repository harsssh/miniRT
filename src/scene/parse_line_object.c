/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:19:33 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 02:41:44 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

#define MATERIAL_DELIM '|'

// set object type and object.object
static void	init_object(t_object *object, t_object_type type, size_t size)
{
	object->type = type;
	object->object = ft_calloc(1, size);
}

static void	parse_object_conf(t_object *object, const char *line)
{
	if (ft_strncmp(line, "sp", 2) == 0)
	{
		init_object(object, OBJ_SPHERE, sizeof(t_sphere_conf));
		*(t_sphere_conf *)object->object = parse_sphere(line);
	}
	else if (ft_strncmp(line, "pl", 2) == 0)
	{
		init_object(object, OBJ_PLANE, sizeof(t_plane_conf));
		*(t_plane_conf *)object->object = parse_plane(line);
	}
	else if (ft_strncmp(line, "cy", 2) == 0)
	{
		init_object(object, OBJ_CYLINDER, sizeof(t_cylinder_conf));
		*(t_cylinder_conf *)object->object = parse_cylinder(line);
	}
	else if (ft_strncmp(line, "cy", 2) == 0)
	{
		init_object(object, OBJ_CONE, sizeof(t_cone_conf));
		*(t_cone_conf *)object->object = parse_cone(line);
	}
	else
		exit_with_error(EXIT_PARSE_ERROR, "invalid object type");
}

// key:value
static void	parse_material_key_value(t_material *material, const char *str)
{
	char	*delim_pos;
	size_t	key_len;

	delim_pos = ft_strchr(str, ':');
	if (delim_pos == NULL)
		exit_with_error(EXIT_PARSE_ERROR, "parse_material: invalid format");
	key_len = delim_pos - str;
	if (ft_strncmp(str, "diff", key_len) == 0)
		material->diffuse_reflectance = parse_double(delim_pos + 1);
	else if (ft_strncmp(str, "spec", key_len) == 0)
		material->specular_reflectance = parse_double(delim_pos + 1);
	else if (ft_strncmp(str, "amb", key_len) == 0)
		material->ambient_reflectance = parse_double(delim_pos + 1);
	else if (ft_strncmp(str, "shin", key_len) == 0)
		material->shininess = parse_double(delim_pos + 1);
	else if (ft_strncmp(str, "check", key_len) == 0)
	{
		material->checker = true;
		material->check_color = rgb_normalize(parse_rgb(delim_pos + 1));
	}
	else if (ft_strncmp(str, "bump", key_len) == 0)
		material->height_map = ft_strdup(delim_pos + 1);
	else
		exit_with_error(EXIT_PARSE_ERROR, "parse_material: invalid key");
}

// spec:0.5 diff:0.5 shin:10 check:0,0,0 bump:height_map.png
static void	parse_material(t_material *material, const char *line)
{
	char	**split;
	char	**ptr;

	split = split_space(line);
	ptr = split;
	while (*ptr)
	{
		parse_material_key_value(material, *ptr);
		++ptr;
	}
	if (!is_in_range(material->diffuse_reflectance, 0, 1))
		exit_with_error(EXIT_PARSE_ERROR, "parse_material: invalid diffuse");
	if (!is_in_range(material->specular_reflectance, 0, 1))
		exit_with_error(EXIT_PARSE_ERROR, "parse_material: invalid specular");
	if (!is_in_range(material->ambient_reflectance, 0, 1))
		exit_with_error(EXIT_PARSE_ERROR, "parse_material: invalid ambient");
	if (material->shininess < 0)
		exit_with_error(EXIT_PARSE_ERROR, "parse_material: invalid shininess");
	free_array(split);
}

t_object	*parse_object(const char *line)
{
	t_object	*object;
	char		*line_copy;
	char		*delim_pos;

	object = ft_calloc(1, sizeof(t_object));
	object->material.diffuse_reflectance = DEFAULT_DIFFUSE_REFLECTANCE;
	object->material.specular_reflectance = DEFAULT_SPECULAR_REFLECTANCE;
	object->material.ambient_reflectance = DEFAULT_AMBIENT_REFLECTANCE;
	object->material.shininess = DEFAULT_SHININESS;
	line_copy = ft_strdup(line);
	delim_pos = ft_strchr(line_copy, MATERIAL_DELIM);
	if (delim_pos != NULL)
	{
		*delim_pos = '\0';
		parse_material(&object->material, delim_pos + 1);
	}
	parse_object_conf(object, line_copy);
	free(line_copy);
	return (object);
}
