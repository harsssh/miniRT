/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:00:10 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/26 07:00:11 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

// If `a` is close to 0, there are no solutions as the quadratic equation.
void	solve_quadratic(t_quadratic *q)
{
	const double	discriminant = q->half_b * q->half_b - q->a * q->c;

	q->solved = false;
	if (q->a == 0 || discriminant < 0 || discriminant == INFINITY
		|| discriminant == -INFINITY)
		return ;
	if (q->a < 0)
	{
		q->t1 = (-q->half_b + sqrt(discriminant)) / q->a;
		q->t2 = (-q->half_b - sqrt(discriminant)) / q->a;
	}
	else
	{
		q->t1 = (-q->half_b - sqrt(discriminant)) / q->a;
		q->t2 = (-q->half_b + sqrt(discriminant)) / q->a;
	}
	if ((q->t1 == INFINITY || q->t1 == -INFINITY)
		&& (q->t2 == INFINITY || q->t2 == -INFINITY))
		return ;
	q->solved = true;
}
