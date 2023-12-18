/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 06:02:32 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 06:02:33 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include <stdlib.h>

void	render_loop(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
	exit(EXIT_SUCCESS);
}
