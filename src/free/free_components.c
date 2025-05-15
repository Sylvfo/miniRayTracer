/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:20:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 15:57:58 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	free_comps_vectors(t_comps *comps)
{
	free_coord(comps->r_dir);
	free_coord(comps->r_origin);
	free_coord(comps->p_touch);
	free_coord(comps->v_eye);
	free_coord(comps->v_norm_parral);
	free_coord(comps->v_light_to_point);
	free_coord(comps->v_sphere_to_point);
	free_coord(comps->v_point_to_light);
	free_coord(comps->reflect_dir);
	free_coord(comps->scalar);
	free_coord(comps->view_dir);
	free_coord(comps->p_space);
	free_coord(comps->origin_zero);
	free_coord(comps->object_normal);
}

void	free_comps(t_comps *comps)
{
	if (!comps)
		return ;

	// Libération des allocations de base (malloc)
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
	if (comps->v_point_to_light)
	{
		free(comps->v_point_to_light);
		comps->v_point_to_light = NULL;
	}
	comps->obj = NULL;

	// Finalement, libération de la structure elle-même
	free(comps);
}

void	free_obj(t_obj *obj)
{
	if (!obj)
		return ;
	free_coord(obj->p_coord);
	free_coord(obj->v_axe);
	free_color(obj->color);
	free(obj);
}

void	free_obj_array(t_obj **objs)
{
	int	i;

	if (!objs)
		return ;
	i = 0;
	while (objs[i])
	{
		free_obj(objs[i]);
		i++;
	}
	free(objs);
}