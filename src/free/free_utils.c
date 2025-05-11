/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:34:56 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 17:59:08 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_image(t_image *ima)
{
	if (!ima)
		return ;
	free(ima);
}

void	free_comps(t_comps *comps)
{
	if (!comps)
		return ;
	free(comps->r_origin);
	free(comps->r_dir);
	free(comps->obj_color);
	free(comps->origin_zero);
	free(comps->object_normal);
	free(comps->transp_inv);
	free(comps->p_space);
	free(comps->obj_inv);
	free(comps->p_touch);
	free(comps->v_eye);
	free(comps->v_norm_parral);
	free(comps->v_light_to_point);
	free(comps->v_sphere_to_point);
	free(comps->v_point_to_light);
	free(comps->reflect_dir);
	free(comps->scalar);
	free(comps->view_dir);
	free(comps);
}

void	free_all(t_pix ***pix, int x, int y, t_num_obj *num_obj)
{
	/* free_pix(pix, x, y, num_obj);
	free(num_obj); */
}
