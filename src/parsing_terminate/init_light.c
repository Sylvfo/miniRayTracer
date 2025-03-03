/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:54:16 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/03 16:38:49 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_parsing.h"

void	free_light_memory(t_light ***light, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(light[i]);
		i++;
	}
	free(light);
}

t_light	**init_light_array(int count)
{
	t_light	**light_array;
	int		i;

	light_array = malloc(count * sizeof(t_light *));
	if (!light_array)
		return (NULL);
	i = 0;
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
	return (light_array);
}

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

t_light	***init_light(t_num_obj *num_obj)
{
	t_light	***light;
	int		i;

	light = allocate_light_arrays(num_obj);
	if (!light)
		return (NULL);
	light[0][0]->p_coord = malloc(sizeof(t_coord));
	light[0][0]->color = malloc(sizeof(t_color));
	if (!light[0][0]->p_coord || !light[0][0]->color)
	{
		free(light[0][0]->p_coord);
		free(light[0][0]->color);
		free(light[0][0]);
		free_light_memory(light, 2);
		return (NULL);
	}
	i = 0;
	while (i < num_obj->light)
	{
		light[1][i]->p_coord = malloc(sizeof(t_coord));
		light[1][i]->color = malloc(sizeof(t_color));
		if (!light[1][i]->p_coord || !light[1][i]->color)
		{
			free(light[1][i]->p_coord);
			free(light[1][i]->color);
			free(light[1][i]);
			free_light_memory(light, 2);
			return (NULL);
		}
		i++;
	}
	return (light);
}
