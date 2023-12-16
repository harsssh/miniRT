#ifndef DEBUG_H
#define DEBUG_H

#include "config.h"
#include <stdio.h>

void print_config(t_config config);
void print_vec(t_vec3 vec, bool newline);
void print_rgb(t_rgb rgb, bool newline);

#endif
