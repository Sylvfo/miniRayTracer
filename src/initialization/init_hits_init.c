/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:47:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 14:48:11 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	init_hits_background(t_hits ***hits)
{
	hits[0][0] = malloc(sizeof(t_hits));
	hits[0][0]->r_dir = malloc(sizeof(t_coord));
	hits[0][0]->r_origin = malloc(sizeof(t_coord));
	hits[0][0]->type = NONE;
	hits[0][1] = NULL;
}

static void	init_hits_spheres(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	i = 0;
	while (i < num_obj->sphere)
	{
		hits[1][i] = malloc(sizeof(t_hits));
		hits[1][i]->r_dir = malloc(sizeof(t_coord));
		hits[1][i]->r_origin = malloc(sizeof(t_coord));
		hits[1][i]->type = SPHERE;
		i++;
	}
	hits[1][num_obj->sphere] = NULL;
}

static void	init_hits_plans(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	i = 0;
	while (i < num_obj->plan)
	{
		hits[2][i] = malloc(sizeof(t_hits));
		hits[2][i]->r_dir = malloc(sizeof(t_coord));
		hits[2][i]->r_origin = malloc(sizeof(t_coord));
		hits[2][i]->type = PLAN;
		i++;
	}
	hits[2][num_obj->plan] = NULL;
}

static void	init_hits_cylinders(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	i = 0;
	while (i < num_obj->cylinder)
	{
		hits[3][i] = malloc(sizeof(t_hits));
		hits[3][i]->r_dir = malloc(sizeof(t_coord));
		hits[3][i]->r_origin = malloc(sizeof(t_coord));
		hits[3][i]->type = CYLINDER;
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
