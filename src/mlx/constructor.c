/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 06:02:17 by kemizuki          #+#    #+#             */
/*   Updated: 2024/02/03 19:50:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_utils.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

static void	init_mlx(t_mlx *mlx, int width, int height, char *title)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit(EXIT_FAILURE);
	mlx->window = mlx_new_window(mlx->mlx, width, height, title);
	if (mlx->window == NULL)
		exit(EXIT_FAILURE);
	mlx->img = mlx_new_image(mlx->mlx, width, height);
	if (mlx->img == NULL)
		exit(EXIT_FAILURE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length,
			&mlx->endian);
	if (mlx->addr == NULL)
		exit(EXIT_FAILURE);
	mlx->width = width;
	mlx->height = height;
}

static void	init_event_handler(t_mlx *mlx)
{
	mlx_hook(mlx->window, DestroyNotify, StructureNotifyMask,
		destroy_handler, NULL);
	mlx_hook(mlx->window, VisibilityNotify, VisibilityChangeMask,
		visible_handler, mlx);
	mlx_key_hook(mlx->window, key_handler, NULL);
}

t_mlx	*new_mlx(int width, int height, char *title)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	init_mlx(mlx, width, height, title);
	init_event_handler(mlx);
	return (mlx);
}
