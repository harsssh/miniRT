#include "config.h"
#include "libft.h"
#include <errno.h>
#include <limits.h>

unsigned int parse_uint(const char *str) {
	long tmp;

	if (str == NULL || *str == '\0' || !ft_strall(str, ft_isdigit))
		exit_with_error(EXIT_PARSE_ERROR, "parse_uint: invalid format");
	errno = 0;
	tmp = ft_atol(str);
	if (errno != 0 || tmp > UINT_MAX)
		exit_with_error(EXIT_PARSE_ERROR, "parse_uint: too large number");
	return ((unsigned int) tmp);
}