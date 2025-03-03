/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:24:40 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/03 13:14:14 by cmegret          ###   ########.fr       */
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

	*pix = malloc(rows * sizeof(t_pix *));
	if (!*pix)
		return ;
	i = 0;
	while (i < rows)
	{
		(*pix)[i] = malloc(cols * sizeof(t_pix));
		if (!(*pix)[i])
		{
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

static bool	init_camera_obj_light(t_camera **cam, t_obj ****obj,
	t_light ****lux, t_num_obj *num_obj)
{
	*cam = init_camera();
	if (!*cam)
		return (false);
	*obj = init_obj(num_obj);
	if (!*obj)
	{
		free(*cam);
		return (false);
	}
	*lux = init_light(num_obj);
	if (!*lux)
	{
		free(*cam);
		free_obj_memory(*obj, 4);
		return (false);
	}
	return (true);
}

static void	assign_camera_obj_light_to_pix(t_pix ***pix, t_camera *cam,
	t_obj ***obj, t_light ***lux)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].cam = cam;
			(*pix)[i][j].obj = obj;
			(*pix)[i][j].lux = lux;
			j++;
		}
		i++;
	}
}

bool	init_data(t_pix ***pix, t_num_obj *num_obj)
{
	t_camera	*cam;
	t_obj		***obj;
	t_light		***lux;

	init_pix(pix, WND_HEIGHT, WND_WIDTH);
	if (!*pix)
		return (false);
	if (!init_camera_obj_light(&cam, &obj, &lux, num_obj))
		return (false);
	assign_camera_obj_light_to_pix(pix, cam, obj, lux);
	return (true);
}
