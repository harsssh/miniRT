/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:37:45 by kemizuki          #+#    #+#             */
/*   Updated: 2024/01/11 02:33:17 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <errno.h>
#include <fcntl.h>

static void	add_light(t_scene *config, t_light_conf light)
{
	t_light_conf	*light_ptr;

	light_ptr = ft_calloc(1, sizeof(t_light_conf));
	*light_ptr = light;
	ft_list_push_back(config->lights, light_ptr);
}

static void	parse_line(t_scene *config, const char *line, t_parse_state *state,
					t_parse_option opt)
{
	if (ft_strncmp(line, "A", 1) == 0)
	{
		config->ambient = parse_ambient(line);
		++(state->ambient_count);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		config->camera = parse_camera(line);
		++(state->camera_count);
	}
	else if (ft_strncmp(line, "L", 1) == 0)
	{
		add_light(config, parse_light(line));
		++(state->light_count);
	}
	else
		ft_list_push_back(config->objects, parse_object(line, opt));
}

static void	validate_state(t_parse_state state, t_parse_option opt)
{
	if (state.ambient_count != 1)
		exit_with_error(EXIT_PARSE_ERROR, "ambient: invalid count");
	if (state.camera_count != 1)
		exit_with_error(EXIT_PARSE_ERROR, "camera: invalid count");
	if (state.light_count == 0 || state.light_count > opt.max_light)
		exit_with_error(EXIT_PARSE_ERROR, "light: too many");
}

t_scene	*parse_scene(const char *path, t_parse_option opt)
{
	int				fd;
	char			*line;
	t_scene			*scene;
	t_parse_state	state;

	ft_bzero(&state, sizeof(t_parse_state));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error(EXIT_FAILURE, "failed to open file");
	scene = new_scene();
	while (true)
	{
		errno = 0;
		line = get_next_line(fd);
		if (errno != 0)
			exit_with_error(EXIT_FAILURE, "failed to read file");
		if (line == NULL)
			break ;
		if (*line != '\n' && *line != '#')
			parse_line(scene, line, &state, opt);
		free(line);
	}
	validate_state(state, opt);
	return (scene);
}
