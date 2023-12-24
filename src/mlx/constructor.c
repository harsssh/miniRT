/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 06:02:17 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/25 04:36:53 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_utils.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

// NOTE: ESCAPE_KEY may be different depending on the environment.
#if defined(XK_Escape)
# define ESCAPE_KEY XK_Escape
#else
# define ESCAPE_KEY 0xff1b
#endif

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

static int	terminate(void)
{
	exit(EXIT_SUCCESS);
}

static int	key_handler(int key, void *param)
{
	(void)param;
	if (key == ESCAPE_KEY)
		terminate();
	return (0);
}

static void	init_event_handler(t_mlx *mlx)
{
	mlx_hook(mlx->window, DestroyNotify, StructureNotifyMask, terminate, NULL);
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
