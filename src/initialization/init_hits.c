/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:46:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/11 21:00:25 by cmegret          ###   ########.fr       */
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
		return (NULL);
	initialize_hits_arrays(hits, num_obj);
	return (hits);
}

void	assign_hits_to_pix(t_pix ***pix, t_hits ***hits, t_num_obj *num_obj)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_WIDTH)
	{
		j = 0;
		while (j < WND_HEIGHT)
		{
			pix[i][j]->hits = NULL;
			pix[i][j]->hits = init_hits(num_obj);
			pix[i][j]->comps = malloc(sizeof(t_comps));
			pix[i][j]->comps->r_dir = malloc(sizeof(t_coord));
			pix[i][j]->comps->r_origin = malloc(sizeof(t_coord));
			pix[i][j]->comps->obj_color = malloc(sizeof(t_color));
			j++;
		}
		i++;
	}
}
