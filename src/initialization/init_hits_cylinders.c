/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits_cylinders.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:11:07 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 08:13:54 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	allocate_single_hit(t_hits **hit)
{
	*hit = malloc(sizeof(t_hits));
	if (!*hit)
		return (0);
	(*hit)->r_dir = malloc(sizeof(t_coord));
	if (!(*hit)->r_dir)
	{
		free(*hit);
		*hit = NULL;
		return (0);
	}
	(*hit)->r_origin = malloc(sizeof(t_coord));
	if (!(*hit)->r_origin)
	{
		free((*hit)->r_dir);
		free(*hit);
		*hit = NULL;
		return (0);
	}
	return (1);
}

static void	initialize_hit_properties(t_hits *hit)
{
	hit->type = CYLINDER;
	hit->t1 = INT_MAX;
	hit->t2 = INT_MAX;
	hit->t_count = 0;
}

static void	cleanup_failed_allocation(t_hits ***hits, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		if (hits[3][j])
		{
			free(hits[3][j]->r_dir);
			free(hits[3][j]->r_origin);
			free(hits[3][j]);
		}
		j++;
	}
	free(hits[3]);
	hits[3] = NULL;
}

void	init_hits_cylinders(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	if (!hits || !hits[3])
		return ;
	i = 0;
	while (i < num_obj->cylinder)
	{
		if (!allocate_single_hit(&hits[3][i]))
		{
			cleanup_failed_allocation(hits, i);
			return ;
		}
		initialize_hit_properties(hits[3][i]);
		i++;
	}
	hits[3][num_obj->cylinder] = NULL;
}
