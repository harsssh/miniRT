/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:34:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/15 11:36:23 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

int	main(void)
{
	t_parse_option option;
	option.max_light = 1;
	t_config *config = parse_config("scenes/example.rt", option);
	print_config(*config);
}
