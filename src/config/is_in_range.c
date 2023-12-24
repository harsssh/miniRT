/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:19:14 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 00:19:16 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_in_range(double value, double min, double max)
{
	return (min <= value && value <= max);
}

bool	is_in_range_uint(unsigned int value, unsigned int min, unsigned int max)
{
	return (min <= value && value <= max);
}
