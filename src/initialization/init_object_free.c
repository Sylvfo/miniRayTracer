/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:34:22 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 13:36:23 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	free_obj_background(t_obj ***obj)
{
	if (obj[0] && obj[0][0])
	{
		free(obj[0][0]->p_coord);
		free(obj[0][0]->color);
		free(obj[0][0]);
		obj[0][0] = NULL;
	}
	free(obj[0]);
	obj[0] = NULL;
}

static void	free_obj_spheres(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	if (obj[1])
	{
		while (i < count && obj[1][i])
		{
			free(obj[1][i]->p_coord);
			free(obj[1][i]->color);
			free(obj[1][i]);
			i++;
		}
		free(obj[1]);
		obj[1] = NULL;
	}
}

static void	free_obj_plans(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	if (obj[2])
	{
		while (i < count && obj[2][i])
		{
			free(obj[2][i]->p_coord);
			free(obj[2][i]->color);
			free(obj[2][i]->v_axe);
			free(obj[2][i]);
			i++;
		}
		free(obj[2]);
		obj[2] = NULL;
	}
}

static void	free_obj_cylinders(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	if (obj[3])
	{
		while (i < count && obj[3][i])
		{
			free(obj[3][i]->p_coord);
			free(obj[3][i]->color);
			free(obj[3][i]->v_axe);
			free(obj[3][i]);
			i++;
		}
		free(obj[3]);
		obj[3] = NULL;
	}
}

void	free_object(t_obj ***obj, t_num_obj *num_obj)
{
	if (!obj)
		return ;
	free_obj_background(obj);
	free_obj_spheres(obj, num_obj->sphere);
	free_obj_plans(obj, num_obj->plan);
	free_obj_cylinders(obj, num_obj->cylinder);
	free(obj);
}
