/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_alloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:29:57 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 14:34:01 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	init_ambient_light(t_light ***light)
{
	light[0][0]->p_coord = malloc(sizeof(t_coord));
	light[0][0]->color = malloc(sizeof(t_color));
	if (!light[0][0]->p_coord || !light[0][0]->color)
	{
		free(light[0][0]->p_coord);
		free(light[0][0]->color);
		free(light[0][0]);
		return (false);
	}
	return (true);
}

bool	init_one_spotlight(t_light *spot)
{
	spot->p_coord = malloc(sizeof(t_coord));
	spot->color = malloc(sizeof(t_color));
	if (!spot->p_coord || !spot->color)
	{
		free(spot->p_coord);
		free(spot->color);
		free(spot);
		return (false);
	}
	return (true);
}

bool	init_spotlights(t_light ***light, t_num_obj *num_obj)
{
	int	i;

	i = 0;
	while (i < num_obj->light)
	{
		if (!init_one_spotlight(light[1][i]))
			return (false);
		i++;
	}
	return (true);
}
