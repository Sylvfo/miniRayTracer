/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:53:25 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/03 13:12:40 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parsing.h"

void	free_obj_memory(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(obj[i]);
		i++;
	}
	free(obj);
}

t_obj	**init_object_array(int count)
{
	t_obj	**obj_array;
	int		i;

	obj_array = malloc(count * sizeof(t_obj *));
	if (!obj_array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		obj_array[i] = malloc(sizeof(t_obj));
		if (!obj_array[i])
		{
			while (i-- > 0)
				free(obj_array[i]);
			free(obj_array);
			return (NULL);
		}
		obj_array[i]->p_coord = malloc(sizeof(t_coord));
		obj_array[i]->color = malloc(sizeof(t_color));
		obj_array[i]->v_axe = malloc(sizeof(t_coord));
		if (!obj_array[i]->p_coord || !obj_array[i]->color || !obj_array[i]->v_axe)
		{
			free(obj_array[i]->p_coord);
			free(obj_array[i]->color);
			free(obj_array[i]->v_axe);
			free(obj_array[i]);
			while (i-- > 0)
			{
				free(obj_array[i]->p_coord);
				free(obj_array[i]->color);
				free(obj_array[i]->v_axe);
				free(obj_array[i]);
			}
			free(obj_array);
			return (NULL);
		}
		i++;
	}
	return (obj_array);
}

t_obj	***allocate_obj_arrays(t_num_obj *num_obj)
{
	t_obj	***obj;

	obj = malloc(4 * sizeof(t_obj **));
	if (!obj)
		return (NULL);
	obj[0] = init_object_array(1);
	obj[1] = init_object_array(num_obj->sphere);
	obj[2] = init_object_array(num_obj->plan);
	obj[3] = init_object_array(num_obj->cylinder);
	if (!obj[0] || !obj[1] || !obj[2] || !obj[3])
	{
		free_obj_memory(obj, 4);
		return (NULL);
	}
	return (obj);
}

t_obj	***init_obj(t_num_obj *num_obj)
{
	t_obj	***obj;

	obj = allocate_obj_arrays(num_obj);
	if (!obj)
		return (NULL);
	obj[0][0]->color = malloc(sizeof(t_color));
	if (!obj[0][0]->color)
	{
		free(obj[0][0]);
		free_obj_memory(obj, 4);
		return (NULL);
	}
	obj[0][0]->color->r = 1.0f;
	obj[0][0]->color->g = 1.0f;
	obj[0][0]->color->b = 1.0f;
	obj[0][0]->color->rgb = 0xFFFFFF;
	return (obj);
}
