/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:39:30 by kemizuki          #+#    #+#             */
/*   Updated: 2024/02/03 19:49:39 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include <stdlib.h>

// NOTE: ESCAPE_KEY may be different depending on the environment.
#if defined(XK_Escape)
# define ESCAPE_KEY XK_Escape
#else
# define ESCAPE_KEY 0xff1b
#endif

int	destroy_handler(void)
{
	exit(EXIT_SUCCESS);
}

int	key_handler(int key, void *param)
{
	(void)param;
	if (key == ESCAPE_KEY)
		exit(EXIT_SUCCESS);
	return (0);
}

int	visible_handler(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}
