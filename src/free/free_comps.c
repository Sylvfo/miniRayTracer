/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_comps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:39:56 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 16:40:20 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	free_comps5(t_comps *comps)
{
	if (comps->v_point_to_light)
	{
		free(comps->v_point_to_light);
		comps->v_point_to_light = NULL;
	}
	comps->obj = NULL;
	free(comps);
}

static void	free_comps4(t_comps *comps)
{
	if (comps->origin_zero)
	{
		free(comps->origin_zero);
		comps->origin_zero = NULL;
	}
	if (comps->object_normal)
	{
		free(comps->object_normal);
		comps->object_normal = NULL;
	}
	if (comps->transp_inv)
	{
		free(comps->transp_inv);
		comps->transp_inv = NULL;
	}
	if (comps->obj_inv)
	{
		free(comps->obj_inv);
		comps->obj_inv = NULL;
	}
	free_comps5(comps);
}

static void	free_comps3(t_comps *comps)
{
	if (comps->reflect_dir)
	{
		free(comps->reflect_dir);
		comps->reflect_dir = NULL;
	}
	if (comps->scalar)
	{
		free(comps->scalar);
		comps->scalar = NULL;
	}
	if (comps->view_dir)
	{
		free(comps->view_dir);
		comps->view_dir = NULL;
	}
	if (comps->p_space)
	{
		free(comps->p_space);
		comps->p_space = NULL;
	}
	free_comps4(comps);
}

static void	free_comps2(t_comps *comps)
{
	if (comps->v_norm_parral)
	{
		free(comps->v_norm_parral);
		comps->v_norm_parral = NULL;
	}
	if (comps->obj_color)
	{
		free(comps->obj_color);
		comps->obj_color = NULL;
	}
	if (comps->v_light_to_point)
	{
		free(comps->v_light_to_point);
		comps->v_light_to_point = NULL;
	}
	if (comps->v_sphere_to_point)
	{
		free(comps->v_sphere_to_point);
		comps->v_sphere_to_point = NULL;
	}
	free_comps3(comps);
}

void	free_comps(t_comps *comps)
{
	if (!comps)
		return ;
	if (comps->r_dir)
	{
		free(comps->r_dir);
		comps->r_dir = NULL;
	}
	if (comps->r_origin)
	{
		free(comps->r_origin);
		comps->r_origin = NULL;
	}
	if (comps->p_touch)
	{
		free(comps->p_touch);
		comps->p_touch = NULL;
	}
	if (comps->v_eye)
	{
		free(comps->v_eye);
		comps->v_eye = NULL;
	}
	free_comps2(comps);
}
