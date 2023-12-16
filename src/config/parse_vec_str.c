/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:22:29 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 10:22:31 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "libft.h"

static size_t	array_size(char **array)
{
	size_t	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

static size_t count_char(const char *str, char c)
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

	if (count_char(str, ',') != 2)
		exit_with_error(EXIT_PARSE_ERROR);
	split = ft_split(str, ',');
	if (split == NULL || array_size(split) != 3)
		exit_with_error(EXIT_PARSE_ERROR);
	return (vec3(
		parse_double(split[0]),
		parse_double(split[1]),
		parse_double(split[2])));
}

t_rgb	parse_rgb(const char *str)
{
	char	**split;
	t_rgb	v;

	if (count_char(str, ',') != 2)
		exit_with_error(EXIT_PARSE_ERROR);
	split = ft_split(str, ',');
	if (split == NULL || array_size(split) != 3)
		exit_with_error(EXIT_PARSE_ERROR);
	v = vec3(parse_uint(split[0]), parse_uint(split[1]), parse_uint(split[2]));
	if (v.x > 255 || v.y > 255 || v.z > 255)
		exit_with_error(EXIT_PARSE_ERROR);
	return (v);
}
