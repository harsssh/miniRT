/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:37:45 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 21:37:47 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include <fcntl.h>

static void	add_light(t_config *config, t_light_conf light)
{
	t_light_conf	*light_ptr;

	light_ptr = ft_calloc(1, sizeof(t_light_conf));
	*light_ptr = light;
	ft_list_push_back(config->lights, light_ptr);
}

static t_object	*parse_object(const char *line)
{
	t_object	*object;

	object = ft_calloc(1, sizeof(t_object));
	if (ft_strncmp(line, "sp", 2) == 0)
	{
		object->type = OBJ_SPHERE;
		object->object = ft_calloc(1, sizeof(t_sphere_conf));
		*(t_sphere_conf *)object->object = parse_sphere(line);
	}
	else if (ft_strncmp(line, "pl", 2) == 0)
	{
		object->type = OBJ_PLANE;
		object->object = ft_calloc(1, sizeof(t_plane_conf));
		*(t_plane_conf *)object->object = parse_plane(line);
	}
	else if (ft_strncmp(line, "cy", 2) == 0)
	{
		object->type = OBJ_CYLINDER;
		object->object = ft_calloc(1, sizeof(t_cylinder_conf));
		*(t_cylinder_conf *)object->object = parse_cylinder(line);
	}
	else
		exit_with_error(EXIT_PARSE_ERROR, "invalid object type");
	return (object);
}

static void	parse_line(t_config *config, const char *line, t_parse_option opt)
{
	static unsigned int	light_count;

	light_count = 0;
	if (ft_strncmp(line, "A", 1) == 0)
		config->ambient = parse_ambient(line);
	else if (ft_strncmp(line, "C", 1) == 0)
		config->camera = parse_camera(line);
	else if (ft_strncmp(line, "L", 1) == 0)
	{
		if (light_count >= opt.max_light)
			exit_with_error(EXIT_FAILURE, "too many lights");
		add_light(config, parse_light(line));
		++light_count;
	}
	else
		ft_list_push_back(config->objects, parse_object(line));
}

t_config	*parse_config(const char *path, t_parse_option opt)
{
	int			fd;
	char		*line;
	t_config	*config;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error(EXIT_FAILURE, "failed to open file");
	config = new_config();
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		parse_line(config, line, opt);
		free(line);
	}
	return (config);
}
