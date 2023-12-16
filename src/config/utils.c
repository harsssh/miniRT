/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:36:26 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 21:36:27 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	**split_space(const char *str)
{
	char	*copy;
	char	*ptr;
	char	**result;

	copy = ft_strdup(str);
	ptr = copy;
	while (*ptr)
	{
		if (ft_isspace(*ptr))
			*ptr = ' ';
		ptr++;
	}
	result = ft_split(copy, ' ');
	free(copy);
	return (result);
}

size_t	array_size(char **array)
{
	size_t	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

void	exit_with_error(int status, const char *message)
{
	if (message == NULL)
		write(STDERR_FILENO, "Error\n", 6);
	else
		ft_dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(status);
}

bool	is_normalized(t_vec3 vec)
{
	double	len2;

	len2 = vec3_length_squared(vec);
	return (fabs(len2 - 1.0) < 1e-6);
}
