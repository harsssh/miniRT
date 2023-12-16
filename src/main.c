/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:34:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 21:37:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

int	main(void)
{
	t_parse_option	option;
	t_config		*config;

	option.max_light = 1;
	config = parse_config("scenes/example.rt", option);
	print_config(*config);
}
