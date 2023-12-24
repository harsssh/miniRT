/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:22:29 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 00:45:38 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"
#include "vector.h"

static size_t	count_char(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

t_vec3	parse_vec3(const char *str)
{
	char	**split;
	t_vec3	v;

	if (count_char(str, ',') != 2)
		exit_with_error(EXIT_PARSE_ERROR, "parse_vec3: invalid format");
	split = ft_split(str, ',');
	if (split == NULL || array_size(split) != 3)
		exit_with_error(EXIT_PARSE_ERROR, "parse_vec3: invalid format");
	v = vec3(parse_double(split[0]),
			parse_double(split[1]),
			parse_double(split[2]));
	free_array(split);
	return (v);
}

t_rgb	parse_rgb(const char *str)
{
	char	**split;
	t_rgb	v;

	if (count_char(str, ',') != 2)
		exit_with_error(EXIT_PARSE_ERROR, "parse_rgb: invalid format");
	split = ft_split(str, ',');
	if (split == NULL || array_size(split) != 3)
		exit_with_error(EXIT_PARSE_ERROR, "parse_rgb: invalid format");
	v = vec3(parse_uint(split[0]), parse_uint(split[1]), parse_uint(split[2]));
	if (rgb_get_r(v) > 255 || rgb_get_g(v) > 255 || rgb_get_b(v) > 255)
		exit_with_error(EXIT_PARSE_ERROR,
			"parse_rgb: value out of range (0-255)");
	free_array(split);
	return (v);
}
