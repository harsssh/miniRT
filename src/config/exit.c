#include "config.h"
#include <stdlib.h>
#include <unistd.h>

void	exit_with_error(int status)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(status);
}
