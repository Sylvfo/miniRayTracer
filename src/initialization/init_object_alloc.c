/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:34:01 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 14:34:09 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	allocate_object_arrays(t_obj ***obj, t_num_obj *num_obj)
{
	obj[0] = malloc(2 * sizeof(t_obj *));
	obj[1] = malloc((num_obj->sphere + 1) * sizeof(t_obj *));
	obj[2] = malloc((num_obj->plan + 1) * sizeof(t_obj *));
	obj[3] = malloc((num_obj->cylinder + 1) * sizeof(t_obj *));
	obj[4] = NULL;
	if (!obj[0] || !obj[1] || !obj[2] || !obj[3])
	{
		free(obj[0]);
		free(obj[1]);
		free(obj[2]);
		free(obj[3]);
		return (false);
	}
	return (true);
}

bool	init_obj_struct(t_obj **o, bool has_v_axe)
{
	*o = malloc(sizeof(t_obj));
	if (!*o)
		return (false);
	
	// Initialize all pointers to NULL first
	(*o)->p_coord = NULL;
	(*o)->color = NULL;
	(*o)->v_axe = NULL;
	(*o)->m_transl = NULL;
	(*o)->m_rot = NULL;
	(*o)->m_scale = NULL;
	(*o)->m_transf = NULL;
	(*o)->m_inv = NULL;
	(*o)->v_axe_r = NULL;
	(*o)->from = NULL;
	(*o)->v_sph_camera = NULL;

	// Now allocate required components
	(*o)->p_coord = malloc(sizeof(t_coord));
	(*o)->color = malloc(sizeof(t_color));
	if (has_v_axe)
		(*o)->v_axe = malloc(sizeof(t_coord));

	if (!(*o)->p_coord || !(*o)->color || (has_v_axe && !(*o)->v_axe))
	{
		if ((*o)->p_coord)
			free((*o)->p_coord);
		if ((*o)->color)
			free((*o)->color);
		if ((*o)->v_axe)
			free((*o)->v_axe);
		free(*o);
		*o = NULL;
		return (false);
	}

	// Initialize additional values
	(*o)->difuse = 0;
	(*o)->specular = 0;
	(*o)->diam = 0;
	(*o)->height = 0;
	(*o)->type = 0;
	(*o)->closed_up = false;
	(*o)->closed_down = false;
	(*o)->radius = 0;

	return (true);
}
