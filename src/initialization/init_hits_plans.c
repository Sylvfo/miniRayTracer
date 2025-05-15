/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits_plans.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:47:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 08:18:26 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	allocate_plan_hit_memory(t_hits **hit_ptr)
{
	*hit_ptr = malloc(sizeof(t_hits));
	if (!*hit_ptr)
		return (0);
	(*hit_ptr)->r_dir = malloc(sizeof(t_coord));
	if (!(*hit_ptr)->r_dir)
	{
		free(*hit_ptr);
		*hit_ptr = NULL;
		return (0);
	}
	(*hit_ptr)->r_origin = malloc(sizeof(t_coord));
	if (!(*hit_ptr)->r_origin)
	{
		free((*hit_ptr)->r_dir);
		free(*hit_ptr);
		*hit_ptr = NULL;
		return (0);
	}
	return (1);
}

static void	set_plan_hit_properties(t_hits *hit)
{
	hit->type = PLAN;
	hit->t1 = INT_MAX;
	hit->t2 = INT_MAX;
	hit->t_count = 0;
}

static void	cleanup_plan_hits_on_failure(t_hits ***hits, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		if (hits[2][j])
		{
			free(hits[2][j]->r_dir);
			free(hits[2][j]->r_origin);
			free(hits[2][j]);
		}
		j++;
	}
	free(hits[2]);
	hits[2] = NULL;
}

void	init_hits_plans(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	if (!hits || !hits[2])
		return ;
	i = 0;
	while (i < num_obj->plan)
	{
		if (!allocate_plan_hit_memory(&hits[2][i]))
		{
			cleanup_plan_hits_on_failure(hits, i);
			return ;
		}
		set_plan_hit_properties(hits[2][i]);
		i++;
	}
	hits[2][num_obj->plan] = NULL;
}
