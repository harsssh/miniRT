#include "config.h"
#include <stdlib.h>
#include <unistd.h>

char **split_space(const char *str)
{
	char *copy;
	char *ptr;
	char **result;

	copy = ft_strdup(str);
	ptr = copy;
	while (*ptr)
	{
		if (ft_isspace(*ptr))
			*ptr= ' ';
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

void	exit_with_error(int status)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(status);
}

bool	is_normalized(t_vec3 vec)
{
	double len2;

	len2 = vec3_length_squared(vec);
	return (fabs(len2 - 1.0) < 1e-6);
}
