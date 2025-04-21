/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:35:26 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/19 16:39:48 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	init_free_counts(t_num_obj *num_obj, int *obj_count,
	int *light_count, int *hits_count)
{
	obj_count[0] = num_obj->sphere;
	obj_count[1] = num_obj->plan;
	obj_count[2] = num_obj->cylinder;
	obj_count[3] = 1;
	light_count[0] = 1;
	light_count[1] = num_obj->light;
	light_count[2] = 0;
	hits_count[0] = num_obj->sphere;
	hits_count[1] = num_obj->plan;
	hits_count[2] = num_obj->cylinder;
	hits_count[3] = 1;
}

static void	free_pix_ray(t_pix *pix)
{
	if (pix->r_original)
	{
		free(pix->r_original->p_origin);
		free(pix->r_original->v_dir);
		free(pix->r_original);
	}
}

static void	free_pix_content(t_pix *pix, t_num_obj *num_obj)
{
	int	obj_count[4];
	int	light_count[3];
	int	hits_count[4];

	if (!pix)
		return ;
	init_free_counts(num_obj, obj_count, light_count, hits_count);
	free_camera(pix->cam);
	free_image(pix->ima);
	free_obj_tab(pix->obj, 4, obj_count);
	free_light_tab(pix->lux, 3, light_count);
	free(pix->p_viewport);
	free_pix_ray(pix);
	free(pix->color);
	free_hits_tab(pix->hits, 4, hits_count);
	free_comps(pix->comps);
}

static void	free_pix_loop(t_pix ***pix, int x, int y, t_num_obj *num_obj)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			free_pix_content(pix[i][j], num_obj);
			free(pix[i][j]);
			j++;
		}
		free(pix[i]);
		i++;
	}
}

void	free_pix(t_pix ***pix, int x, int y, t_num_obj *num_obj)
{
	if (!pix)
		return ;
	free_pix_loop(pix, x, y, num_obj);
	free(pix);
}
