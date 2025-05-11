/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:09:23 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 13:36:19 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_obj	***init_object(t_num_obj *num_obj)
{
	t_obj	***obj;

	obj = malloc(5 * sizeof(t_obj **));
	if (!obj)
		return (NULL);
	if (!allocate_object_arrays(obj, num_obj))
	{
		free(obj);
		return (NULL);
	}
	if (!initialize_object_arrays(obj, num_obj))
	{
		free_object(obj, num_obj);
		return (NULL);
	}
	return (obj);
}
