/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:46:38 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 14:47:06 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	allocate_hits_arrays(t_hits ***hits, t_num_obj *num_obj)
{
	hits[0] = malloc(2 * sizeof(t_hits *));
	hits[1] = malloc((num_obj->sphere + 1) * sizeof(t_hits *));
	hits[2] = malloc((num_obj->plan + 1) * sizeof(t_hits *));
	hits[3] = malloc((num_obj->cylinder + 1) * sizeof(t_hits *));
	hits[4] = NULL;
	if (!hits[1] || !hits[2] || !hits[3])
	{
		free(hits[1]);
		free(hits[2]);
		free(hits[3]);
		free(hits);
		return (false);
	}
	return (true);
}
