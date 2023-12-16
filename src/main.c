/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:34:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/17 08:07:30 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "debug.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_parse_option	opt;
	t_config		*config;

	if (argc == 1)
		return (1);
	printf("[%s]\n", argv[1]);
	opt = (t_parse_option){.max_light = 1};
	config = parse_config(argv[1], opt);
	print_config(*config);
}
