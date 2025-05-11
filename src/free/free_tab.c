/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:35:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 15:27:58 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
** Libère un tableau d'objets t_obj (triple pointeur).
*/
void	free_obj_tab(t_obj ***obj, int nb_type, int *nb_obj)
{
	int	i;
	int	j;

	if (!obj)
		return ;
	i = 0;
	while (i < nb_type)
	{
		j = 0;
		while (nb_obj && j < nb_obj[i])
		{
			free_obj(obj[i][j]);
			j++;
		}
		free(obj[i]);
		i++;
	}
	free(obj);
}

/*
** Libère un tableau de lumières t_light (triple pointeur).
*/
void	free_light_tab(t_light ***lux, int nb_type, int *nb_lux)
{
	int	i;
	int	j;

	if (!lux)
		return ;
	i = 0;
	while (i < nb_type)
	{
		j = 0;
		while (nb_lux && j < nb_lux[i])
		{
			free_light(lux[i][j]);
			j++;
		}
		free(lux[i]);
		i++;
	}
	free(lux);
}

/*
** Libère un hit et ses sous-éléments.
*/
static void	free_one_hit(t_hits *hit)
{
	if (!hit)
		return ;
	if (hit->r_origin)
		free(hit->r_origin);
	if (hit->r_dir)
		free(hit->r_dir);
	free(hit);
}

/*
** Libère un tableau de hits t_hits (triple pointeur).
*/
void	free_hits_tab(t_hits ***hits, int nb_type, int *nb_hits)
{
	int	i;
	int	j;

	if (!hits)
		return ;
	i = 0;
	while (i < nb_type)
	{
		j = 0;
		while (nb_hits && j < nb_hits[i])
		{
			free_one_hit(hits[i][j]);
			j++;
		}
		free(hits[i]);
		i++;
	}
	free(hits);
}
