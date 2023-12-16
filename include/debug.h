/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:12:17 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 16:12:25 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "config.h"
# include <stdio.h>

void	print_config(t_config config);
void	print_vec(t_vec3 vec, bool newline);
void	print_rgb(t_rgb rgb, bool newline);

#endif
