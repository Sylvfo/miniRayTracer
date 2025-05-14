/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:09:29 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/14 22:10:41 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_light_array(t_light **array, int count)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_light_memory(t_light ***light, int count)
{
	int	i;

	i = 0;
	if (!light)
		return ;
	while (i < count)
	{
		if (light[i])
		{
			if (i == 0)
				free_light_array(light[i], 1);
			else
				free_light_array(light[i], count);
		}
		i++;
	}
	free(light);
}

t_light	***init_light(t_num_obj *num_obj)
{
	t_light	***light;

	light = allocate_light_arrays(num_obj);
	if (!light)
		return (NULL);
	if (!init_ambient_light(light))
	{
		free_light_memory(light, 2);
		return (NULL);
	}
	if (!init_spotlights(light, num_obj))
	{
		free_light_memory(light, 2);
		return (NULL);
	}
	return (light);
}
