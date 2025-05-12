/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:47:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 11:33:27 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	init_hits_background(t_hits ***hits)
{
	if (!hits || !hits[0])
		return ;
	hits[0][0] = malloc(sizeof(t_hits));
	if (!hits[0][0])
		return ;
	hits[0][0]->r_dir = malloc(sizeof(t_coord));
	if (!hits[0][0]->r_dir)
	{
		free(hits[0][0]);
		hits[0][0] = NULL;
		return ;
	}
	hits[0][0]->r_origin = malloc(sizeof(t_coord));
	if (!hits[0][0]->r_origin)
	{
		free(hits[0][0]->r_dir);
		free(hits[0][0]);
		hits[0][0] = NULL;
		return ;
	}
	hits[0][0]->type = NONE;
	hits[0][0]->t1 = INT_MAX;
	hits[0][0]->t2 = INT_MAX;
	hits[0][0]->t_count = 0;
	hits[0][1] = NULL;
}

static void	init_hits_spheres(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	if (!hits || !hits[1])
		return ;
	i = 0;
	while (i < num_obj->sphere)
	{
		hits[1][i] = malloc(sizeof(t_hits));
		if (!hits[1][i])
			return ;
		hits[1][i]->r_dir = malloc(sizeof(t_coord));
		if (!hits[1][i]->r_dir)
		{
			free(hits[1][i]);
			hits[1][i] = NULL;
			return ;
		}
		hits[1][i]->r_origin = malloc(sizeof(t_coord));
		if (!hits[1][i]->r_origin)
		{
			free(hits[1][i]->r_dir);
			free(hits[1][i]);
			hits[1][i] = NULL;
			return ;
		}
		hits[1][i]->type = SPHERE;
		hits[1][i]->t1 = INT_MAX;
		hits[1][i]->t2 = INT_MAX;
		hits[1][i]->t_count = 0;
		i++;
	}
	hits[1][num_obj->sphere] = NULL;
}

static void	init_hits_plans(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	if (!hits || !hits[2])
		return ;
	i = 0;
	while (i < num_obj->plan)
	{
		hits[2][i] = malloc(sizeof(t_hits));
		if (!hits[2][i])
			return ;
		hits[2][i]->r_dir = malloc(sizeof(t_coord));
		if (!hits[2][i]->r_dir)
		{
			free(hits[2][i]);
			hits[2][i] = NULL;
			return ;
		}
		hits[2][i]->r_origin = malloc(sizeof(t_coord));
		if (!hits[2][i]->r_origin)
		{
			free(hits[2][i]->r_dir);
			free(hits[2][i]);
			hits[2][i] = NULL;
			return ;
		}
		hits[2][i]->type = PLAN;
		hits[2][i]->t1 = INT_MAX;
		hits[2][i]->t2 = INT_MAX;
		hits[2][i]->t_count = 0;
		i++;
	}
	hits[2][num_obj->plan] = NULL;
}

static void	init_hits_cylinders(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	if (!hits || !hits[3])
		return ;
	i = 0;
	while (i < num_obj->cylinder)
	{
		hits[3][i] = malloc(sizeof(t_hits));
		if (!hits[3][i])
			return ;
		hits[3][i]->r_dir = malloc(sizeof(t_coord));
		if (!hits[3][i]->r_dir)
		{
			free(hits[3][i]);
			hits[3][i] = NULL;
			return ;
		}
		hits[3][i]->r_origin = malloc(sizeof(t_coord));
		if (!hits[3][i]->r_origin)
		{
			free(hits[3][i]->r_dir);
			free(hits[3][i]);
			hits[3][i] = NULL;
			return ;
		}
		hits[3][i]->type = CYLINDER;
		hits[3][i]->t1 = INT_MAX;
		hits[3][i]->t2 = INT_MAX;
		hits[3][i]->t_count = 0;
		i++;
	}
	hits[3][num_obj->cylinder] = NULL;
}

void	initialize_hits_arrays(t_hits ***hits, t_num_obj *num_obj)
{
	init_hits_background(hits);
	init_hits_spheres(hits, num_obj);
	init_hits_plans(hits, num_obj);
	init_hits_cylinders(hits, num_obj);
}
