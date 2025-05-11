/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:30:05 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 14:32:58 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_light	***allocate_light_arrays(t_num_obj *num_obj)
{
	t_light	***light;

	light = malloc(2 * sizeof(t_light **));
	if (!light)
		return (NULL);
	light[0] = init_light_array(1);
	light[1] = init_light_array(num_obj->light);
	if (!light[0] || !light[1])
	{
		free_light_memory(light, 2);
		return (NULL);
	}
	return (light);
}

t_light	**init_light_array(int count)
{
	t_light	**light_array;
	int		i;

	i = 0;
	light_array = malloc((count + 1) * sizeof(t_light *));
	if (!light_array)
		return (NULL);
	while (i < count)
	{
		light_array[i] = malloc(sizeof(t_light));
		if (!light_array[i])
		{
			while (i-- > 0)
				free(light_array[i]);
			free(light_array);
			return (NULL);
		}
		i++;
	}
	light_array[count] = NULL;
	return (light_array);
}
