/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:30:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 16:44:49 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_pix_viewport(t_pix *pix)
{
	if (!pix)
		return ;
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

static void	free_pix_comps_members3(t_pix *pix)
{
	if (pix->comps->scalar)
		free(pix->comps->scalar);
	if (pix->comps->view_dir)
		free(pix->comps->view_dir);
	if (pix->comps->obj_color)
		free(pix->comps->obj_color);
}

static void	free_pix_comps_members2(t_pix *pix)
{
	if (pix->comps->v_light_to_point)
		free(pix->comps->v_light_to_point);
	if (pix->comps->v_sphere_to_point)
		free(pix->comps->v_sphere_to_point);
	if (pix->comps->v_point_to_light)
		free(pix->comps->v_point_to_light);
	if (pix->comps->reflect_dir)
		free(pix->comps->reflect_dir);
	free_pix_comps_members3(pix);
}

static void	free_pix_comps_members(t_pix *pix)
{
	if (pix->comps->r_dir)
		free(pix->comps->r_dir);
	if (pix->comps->r_origin)
		free(pix->comps->r_origin);
	if (pix->comps->p_touch)
		free(pix->comps->p_touch);
	if (pix->comps->p_space)
		free(pix->comps->p_space);
	if (pix->comps->v_eye)
		free(pix->comps->v_eye);
	if (pix->comps->v_norm_parral)
		free(pix->comps->v_norm_parral);
	free_pix_comps_members2(pix);
}

void	free_pix_components(t_pix *pix)
{
	if (!pix || !pix->comps)
		return ;
	free_pix_comps_members(pix);
	free(pix->comps);
	pix->comps = NULL;
}
