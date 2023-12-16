#include "debug.h"

void print_vec(t_vec3 vec, bool newline)
{
	printf("(%.2lf, %.2lf, %.2lf)", vec.x, vec.y, vec.z);
	if (newline)
		printf("\n");
}

void print_rgb(t_rgb rgb, bool newline)
{
	printf("(%d, %d, %d)", (int)rgb.x, (int)rgb.y, (int)rgb.z);
	if (newline)
		printf("\n");
}
