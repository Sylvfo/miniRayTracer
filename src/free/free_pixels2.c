/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pixels2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:43:22 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 16:44:53 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	free_pix_content_members(t_pix *pix)
{
	if (pix->p_viewport)
	{
		free(pix->p_viewport);
		pix->p_viewport = NULL;
	}
	if (pix->p_viewport_world)
	{
		free(pix->p_viewport_world);
		pix->p_viewport_world = NULL;
	}
	if (pix->r_origin)
	{
		free(pix->r_origin);
		pix->r_origin = NULL;
	}
	if (pix->r_dir)
	{
		free(pix->r_dir);
		pix->r_dir = NULL;
	}
}

void	free_pix_content(t_pix *pix)
{
	if (!pix)
		return ;
	free_pix_content_members(pix);
	if (pix->color)
	{
		free_color(pix->color);
		pix->color = NULL;
	}
	if (pix->comps)
	{
		free_comps(pix->comps);
		pix->comps = NULL;
	}
}

static void	free_pix_row(t_pix **row, int cols)
{
	int	j;

	j = 0;
	while (j < cols)
	{
		if (row && row[j])
		{
			free_pix_content(row[j]);
			free(row[j]);
		}
		j++;
	}
	free(row);
}

void	free_pix(t_pix ***pix, int rows, int cols)
{
	int	i;

	i = 0;
	if (!pix)
		return ;
	while (i < rows)
	{
		if (pix[i])
			free_pix_row(pix[i], cols);
		i++;
	}
	free(pix);
}
