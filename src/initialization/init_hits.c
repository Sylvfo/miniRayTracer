/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:46:52 by syl               #+#    #+#             */
/*   Updated: 2025/03/10 15:47:06 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//free...A COPIER + MODIFIER DE INIT OBJECT

static bool	allocate_hits_arrays(t_hits ***hits, t_num_obj *num_obj)
{
	//sylv a rajouté 2 lignes
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

static void	initialize_hits_arrays(t_hits ***hits, t_num_obj *num_obj)
{
	int	i;

	i = 0;
	hits[0][0] = malloc(sizeof(t_hits));
	while (i < num_obj->sphere)
	{
		hits[1][i] = malloc(sizeof(t_hits));
		i++;
	}
	i = 0;
	while (i < num_obj->plan)
	{
		hits[2][i] = malloc(sizeof(t_hits));
		i++;
	}
	i = 0;
	while (i < num_obj->cylinder)
	{
		hits[3][i] = malloc(sizeof(t_hits));
		i++;
	}
	hits[0][1] = NULL;
	hits[1][num_obj->sphere] = NULL;
	hits[2][num_obj->plan] = NULL;
	hits[3][num_obj->cylinder] = NULL;
}

t_hits ***init_hits(t_num_obj *num_obj)
{
	t_hits ***hits;

	hits = 	 malloc(5 * sizeof(t_hits **));
	if (!hits)
		return (NULL);
	if (!allocate_hits_arrays(hits, num_obj))
		return (NULL);
	initialize_hits_arrays(hits, num_obj);
	return (hits);
}

// alors à voir si c est vraiment une bonne idée de faire comme ça....
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
			pix[i][j]->hits = init_hits(num_obj);
			j++;
		}
		i++;
	}
}