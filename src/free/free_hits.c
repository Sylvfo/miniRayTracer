/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:15:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 16:29:26 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	free_hit_content(t_hits *hit)
{
	if (!hit)
		return ;
	if (hit->r_dir)
	{
		free(hit->r_dir);
		hit->r_dir = NULL;
	}
	if (hit->r_origin)
	{
		free(hit->r_origin);
		hit->r_origin = NULL;
	}
}

static void	free_hit_array(t_hits **hits, int num)
{
	int	i;

	if (!hits)
		return ;
	i = 0;
	while (i < num)
	{
		if (hits[i])
		{
			free_hit_content(hits[i]);
			free(hits[i]);
			hits[i] = NULL;
		}
		i++;
	}
}

static void	free_hits_type(t_hits ***hits, int type_index, int num_obj)
{
	if (!hits || !hits[type_index])
		return ;
	free_hit_array(hits[type_index], num_obj);
	free(hits[type_index]);
	hits[type_index] = NULL;
}

static void	free_pix_hits(t_hits ***hits, t_program_context *context)
{
	if (!hits)
		return ;
	free_hits_type(hits, 0, 2);
	if (context->num_obj)
	{
		free_hits_type(hits, 1, context->num_obj->sphere + 1);
		free_hits_type(hits, 2, context->num_obj->plan + 1);
		free_hits_type(hits, 3, context->num_obj->cylinder + 1);
	}
	free(hits);
}

void	free_hits(t_program_context *context)
{
	int	x;
	int	y;

	if (!context || !context->pix)
		return ;
	x = 0;
	while (x < context->width)
	{
		y = 0;
		while (y < context->height)
		{
			if (context->pix[x] && context->pix[x][y])
			{
				if (context->pix[x][y]->hits)
				{
					free_pix_hits(context->pix[x][y]->hits, context);
					context->pix[x][y]->hits = NULL;
				}
			}
			y++;
		}
		x++;
	}
}
