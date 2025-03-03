/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:24:40 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/02 19:39:23 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parsing.h"

void	free_all(t_pix ***pix)
{
	int	i;

	if (pix && *pix)
	{
		i = 0;
		while ((*pix)[i] != NULL)
		{
			if ((*pix)[i]->cam)
				free((*pix)[i]->cam);
			if ((*pix)[i]->obj)
				free_obj_memory((*pix)[i]->obj, 4);
			if ((*pix)[i]->lux)
				free_light_memory((*pix)[i]->lux, 2);
			free((*pix)[i]);
			i++;
		}
		free(*pix);
	}
}

void	init_pix(t_pix ***pix, int rows, int cols)
{
	int	i;
	int	j;

	// Allocate memory for the array of pointers to t_pix
	*pix = malloc(rows * sizeof(t_pix *));
	if (!*pix)
		return ;
	// Allocate memory for each row
	i = 0;
	while (i < rows)
	{
		(*pix)[i] = malloc(cols * sizeof(t_pix));
		if (!(*pix)[i])
		{
			// Free previously allocated rows in case of failure
			j = 0;
			while (j < i)
			{
				free((*pix)[j]);
				j++;
			}
			free(*pix);
			*pix = NULL;
			return ;
		}
		i++;
	}
}

bool	init_data(t_pix ***pix, t_num_obj *num_obj)
{
	int	i;
	int	j;

	init_pix(pix, WND_HEIGHT, WND_WIDTH);
	if (!*pix)
		return (false);
	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].cam = init_camera();
			if (!(*pix)[i][j].cam)
			{
				free_all(pix);
				return (false);
			}
			(*pix)[i][j].obj = init_obj(num_obj);
			if (!(*pix)[i][j].obj)
			{
				free_all(pix);
				return (false);
			}
			(*pix)[i][j].lux = init_light(num_obj);
			if (!(*pix)[i][j].lux)
			{
				free_all(pix);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
