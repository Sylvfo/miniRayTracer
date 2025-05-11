/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_hits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:20:39 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 17:25:43 by cmegret          ###   ########.fr       */
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
			hits[a][b]->r_origin = create_point(0, 0, 0);
			hits[a][b]->r_dir = create_vector(0, 0, 0);
			hits[a][b]->t_count = 0;
			hits[a][b]->t1 = INT_MAX;
			hits[a][b]->t2 = INT_MAX;
			b++;
		}
		a++;
	}
	return (true);
}
