/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 06:02:06 by kemizuki          #+#    #+#             */
/*   Updated: 2024/02/03 19:49:30 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	int		width;
	int		height;
	void	*img;
	void	*window;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_mlx;

t_mlx		*new_mlx(int width, int height, char *title);
void		free_mlx(t_mlx *mlx);
void		put_pixel_to_image(t_mlx *mlx, int x, int y, int color);
void		render_loop(t_mlx *mlx);

// internal
int			destroy_handler(void);
int			key_handler(int key, void *param);
int			visible_handler(t_mlx *mlx);

#endif
