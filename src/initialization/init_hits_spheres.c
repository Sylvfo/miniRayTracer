/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits_spheres.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:47:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 08:17:07 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	allocate_sphere_hit_memory(t_hits **hit_ptr)
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

static void	set_sphere_hit_properties(t_hits *hit)
{
	hit->type = SPHERE;
	hit->t1 = INT_MAX;
	hit->t2 = INT_MAX;
	hit->t_count = 0;
}

static void	cleanup_sphere_hits_on_failure(t_hits ***hits, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		if (hits[1][j])
		{
			free(hits[1][j]->r_dir);
			free(hits[1][j]->r_origin);
			free(hits[1][j]);
		}
		j++;
	}
	free(hits[1]);
	hits[1] = NULL;
}

void	init_hits_spheres(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	if (!hits || !hits[1])
		return ;
	i = 0;
	while (i < num_obj->sphere)
	{
		if (!allocate_sphere_hit_memory(&hits[1][i]))
		{
			cleanup_sphere_hits_on_failure(hits, i);
			return ;
		}
		set_sphere_hit_properties(hits[1][i]);
		i++;
	}
	hits[1][num_obj->sphere] = NULL;
}
