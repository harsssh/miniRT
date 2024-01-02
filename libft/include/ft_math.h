/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:41:57 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 04:41:59 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <math.h>

int		ft_even(int n);
int		ft_odd(int n);
double	ft_pow(double base, int exponent);
double	ft_to_radian(double degree);
double	ft_to_degree(double radian);

#endif
