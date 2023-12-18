/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:42:07 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 04:42:42 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double base, int exponent)
{
	double			result;
	unsigned int	positive_exponent;

	if (exponent == 0)
		return (1);
	if (exponent > 0)
		positive_exponent = exponent;
	else
		positive_exponent = -exponent;
	result = 1;
	while (positive_exponent > 0)
	{
		if (positive_exponent % 2 == 1)
		{
			result *= base;
		}
		base *= base;
		positive_exponent /= 2;
	}
	if (exponent < 0)
		result = 1 / result;
	return (result);
}
