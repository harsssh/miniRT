/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:34:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 06:02:48 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	(void)argc;
	(void)argv;
	mlx = new_mlx(512, 512, "test");
	render_loop(mlx);
}
