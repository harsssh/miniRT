/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:47:09 by kemizuki          #+#    #+#             */
/*   Updated: 2023/12/19 00:53:05 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_object(void *data)
{
	t_object	*obj;

	obj = data;
	free(obj->object);
	free(obj);
}

void	free_config(t_scene *config)
{
	ft_list_destroy(config->lights, free);
	ft_list_destroy(config->objects, free_object);
	free(config);
}
