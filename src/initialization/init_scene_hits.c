/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_hits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:20:39 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 14:43:36 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/initialization.h"

bool	init_hits_matrices(t_hits ***hits)
{
	int	a;
	int	b;

	a = 0;
	while (hits[a] != NULL)
	{
		b = 0;
		while (hits[a][b] != NULL)
		{
			if (hits[a][b]->r_origin)
			{
				hits[a][b]->r_origin->x = 0;
				hits[a][b]->r_origin->y = 0;
				hits[a][b]->r_origin->z = 0;
			}
			if (hits[a][b]->r_dir)
			{
				hits[a][b]->r_dir->x = 0;
				hits[a][b]->r_dir->y = 0;
				hits[a][b]->r_dir->z = 0;
			}
			b++;
		}
		a++;
	}
	return (true);
}
