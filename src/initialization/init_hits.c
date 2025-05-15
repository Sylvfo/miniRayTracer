/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:46:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/15 08:28:22 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_hits	***init_hits(t_num_obj *num_obj)
{
	t_hits	***hits;

	hits = NULL;
	hits = malloc(5 * sizeof(t_hits **));
	if (!hits)
		return (NULL);
	if (!allocate_hits_arrays(hits, num_obj))
		return (NULL); // La libération de 'hits' devrait être gérée dans allocate_hits_arrays ou ici
	initialize_hits_arrays(hits, num_obj);
	return (hits);
}

static int	allocate_and_initialize_comps(t_pix *pixel_ptr)
{
	pixel_ptr->comps = malloc(sizeof(t_comps));
	if (!pixel_ptr->comps)
		return (0);
	pixel_ptr->comps->r_dir = malloc(sizeof(t_coord));
	pixel_ptr->comps->r_origin = malloc(sizeof(t_coord));
	pixel_ptr->comps->obj_color = malloc(sizeof(t_color));
	if (!pixel_ptr->comps->r_dir || !pixel_ptr->comps->r_origin
		|| !pixel_ptr->comps->obj_color)
	{
		free_and_null((void **)&pixel_ptr->comps->r_dir);
		free_and_null((void **)&pixel_ptr->comps->r_origin);
		free_and_null((void **)&pixel_ptr->comps->obj_color);
		free_and_null((void **)&pixel_ptr->comps);
		return (0);
	}
	pixel_ptr->comps->closestt = INT_MAX;
	pixel_ptr->comps->t_count = 0;
	return (1);
}

void	assign_hits_to_pix(t_pix ***pix, t_hits ***hits,
			t_num_obj *num_obj)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_WIDTH)
	{
		j = 0;
		while (j < WND_HEIGHT)
		{
			pix[i][j]->hits = init_hits(num_obj);
			if (!pix[i][j]->hits)
			{
				// Gérer l'échec de init_hits, potentiellement libérer ce qui a déjà été alloué pour pix
				// et retourner ou sortir proprement. Pour l'instant, on retourne.
				return ;
			}
			if (!allocate_and_initialize_comps(pix[i][j]))
			{
				// Gérer l'échec, libérer pix[i][j]->hits et potentiellement le reste.
				return ;
			}
			j++;
		}
		i++;
	}
}
