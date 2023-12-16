/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:37:24 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/16 21:37:28 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "libft.h"
#include <errno.h>
#include <limits.h>

unsigned int	parse_uint(const char *str)
{
	long	tmp;

	if (str == NULL || *str == '\0' || !ft_strall(str, ft_isdigit))
		exit_with_error(EXIT_PARSE_ERROR, "parse_uint: invalid format");
	errno = 0;
	tmp = ft_atol(str);
	if (errno != 0 || tmp > UINT_MAX)
		exit_with_error(EXIT_PARSE_ERROR, "parse_uint: too large number");
	return ((unsigned int)tmp);
}
