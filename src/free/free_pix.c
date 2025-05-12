/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:35:26 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 11:19:31 by cmegret          ###   ########.fr       */
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

static void	free_camera_and_image(t_pix *pix)
{
	free_camera(pix->cam);
	pix->cam = NULL;
	free_image(pix->ima);
	pix->ima = NULL;
}

static void	free_obj_and_light_tabs(t_pix *pix, int *obj_count, int *light_count)
{
	free_obj_tab(pix->obj, 4, obj_count);
	pix->obj = NULL;
	free_light_tab(pix->lux, 3, light_count);
	pix->lux = NULL;
}

static void	free_viewport_and_ray_data(t_pix *pix)
{
	free(pix->p_viewport);
	pix->p_viewport = NULL;
	free(pix->p_viewport_world);
	pix->p_viewport_world = NULL;
	free(pix->r_origin);
	pix->r_origin = NULL;
	free(pix->r_dir);
	pix->r_dir = NULL;
	free(pix->color);
	pix->color = NULL;
}

static void	free_hits_and_comps(t_pix *pix, int *hits_count)
{
	if (pix->hits)
	{
		free_hits_tab(pix->hits, 4, hits_count);
		pix->hits = NULL;
	}
	free_comps(pix->comps);
	pix->comps = NULL;
}

static void	free_pix_content(t_pix *pix, t_num_obj *num_obj, int i, int j)
{
	int	obj_count[4];
	int	light_count[3];
	int	hits_count[4];

	if (!pix)
		return ;
	init_free_counts(num_obj, obj_count, light_count, hits_count);
	if (i == 0 && j == 0)
	{
		free_camera_and_image(pix);
		free_obj_and_light_tabs(pix, obj_count, light_count);
	}
	free_viewport_and_ray_data(pix);
	free_hits_and_comps(pix, hits_count);
}

static void	free_pix_inner_loop(t_pix ***pix, int i, int y, t_num_obj *num_obj)
{
	int	j;

	j = 0;
	while (j < y)
	{
		if (pix[i][j])
		{
			free_pix_content(pix[i][j], num_obj, i, j);
			free(pix[i][j]);
			pix[i][j] = NULL;
		}
		j++;
	}
}

static void	free_pix_loop(t_pix ***pix, int x, int y, t_num_obj *num_obj)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (pix[i])
		{
			free_pix_inner_loop(pix, i, y, num_obj);
			free(pix[i]);
			pix[i] = NULL;
		}
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
