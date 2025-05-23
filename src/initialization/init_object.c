/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:09:23 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/16 15:39:42 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_object(t_obj ***obj, t_num_obj *num_obj)
{
	int	i;

	i = 0;
	//rajouter free obj zero zero
	while (i < num_obj->sphere)
	{
		free(obj[1][i]->p_coord);
		free(obj[1][i]->color);
		free(obj[1][i]);
		i++;
	}
	free(obj[1]);
	i = 0;
	while (i < num_obj->plan)
	{
		free(obj[2][i]->p_coord);
		free(obj[2][i]->color);
		free(obj[2][i]->v_axe); // Libérer l'axe des plans
		free(obj[2][i]);
		i++;
	}
	free(obj[2]);
	i = 0;
	while (i < num_obj->cylinder)
	{
		free(obj[3][i]->p_coord);
		free(obj[3][i]->color);
		free(obj[3][i]->v_axe); // Libérer l'axe des cylindres
		free(obj[3][i]);
		i++;
	}
	free(obj[3]);
	free(obj);
}

static bool	allocate_object_arrays(t_obj ***obj, t_num_obj *num_obj)
{
	//sylv a rajouté 2 lignes
	obj[0] = malloc(2 * sizeof(t_obj *));
	obj[1] = malloc((num_obj->sphere + 1) * sizeof(t_obj *));
	obj[2] = malloc((num_obj->plan + 1) * sizeof(t_obj *));
	obj[3] = malloc((num_obj->cylinder + 1) * sizeof(t_obj *));
	obj[4] = NULL;

	if (!obj[1] || !obj[2] || !obj[3])
	{
		free(obj[1]);
		free(obj[2]);
		free(obj[3]);
		free(obj);
		return (false);
	}
	return (true);
}

static void	initialize_object_arrays(t_obj ***obj, t_num_obj *num_obj)
{
	int	i;

	i = 0;
	//sylv a rajouté 2 lignes

	obj[0][0] = malloc(sizeof(t_obj));
	obj[0][0]->p_coord = malloc(sizeof(t_coord));//NULL??
	obj[0][0]->color = malloc(sizeof(t_color));
	obj[0][0]->v_axe = NULL; // Les sphères n'ont pas d'axe
	while (i < num_obj->sphere)
	{
		obj[1][i] = malloc(sizeof(t_obj));
		obj[1][i]->p_coord = malloc(sizeof(t_coord));
		obj[1][i]->color = malloc(sizeof(t_color));
		obj[1][i]->v_axe = NULL; // Les sphères n'ont pas d'axe
		i++;
	}
	i = 0;
	while (i < num_obj->plan)
	{
		obj[2][i] = malloc(sizeof(t_obj));
		obj[2][i]->p_coord = malloc(sizeof(t_coord));
		obj[2][i]->color = malloc(sizeof(t_color));
		obj[2][i]->v_axe = malloc(sizeof(t_coord));
		i++;
	}
	i = 0;
	while (i < num_obj->cylinder)
	{
		obj[3][i] = malloc(sizeof(t_obj));
		obj[3][i]->p_coord = malloc(sizeof(t_coord));
		obj[3][i]->color = malloc(sizeof(t_color));
		obj[3][i]->v_axe = malloc(sizeof(t_coord));
		i++;
	}
	obj[0][1] = NULL;
	obj[1][num_obj->sphere] = NULL;
	obj[2][num_obj->plan] = NULL;
	obj[3][num_obj->cylinder] = NULL;
	obj[4] = NULL;
}

t_obj	***init_object(t_num_obj *num_obj)
{
	t_obj	***obj;

	obj = malloc(5 * sizeof(t_obj **));
	if (!obj)
		return (NULL);
	if (!allocate_object_arrays(obj, num_obj))
		return (NULL);
	initialize_object_arrays(obj, num_obj);
	return (obj);
}
