/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_prepare_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:25 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 11:31:34 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// prepare p_touch, normal_at and v_eye
void prepare_computation(t_pix ***pix)
{
	int x;
	int y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->comps->type != NONE)
				position_NA(pix[x][y], pix[x][y]->comps->r_dir, pix[x][y]->comps->closestt);
			negat_NA(pix[x][y]->comps->v_eye, pix[x][y]->comps->r_dir);
			if (pix[x][y]->comps->type == SPHERE  || pix[x][y]->comps->type == CYLINDER)
			{
				normal_at_NA(pix[x][y]->comps);
				if (dot_product(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->v_eye) < 0)
				{
					pix[x][y]->comps->inside = true;
					negat_NA(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->v_norm_parral);
				}
			}
			else if (pix[x][y]->comps->type == PLAN)
				copy_coord(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->obj->v_axe);		
			y++;
		}
		x++;
	}
}

//normal = normalize(p_object_space - origin)
void	normal_at_NA(t_comps *comps)
{
	matrix_point_multiplication_new(comps->p_space, comps->obj_inv, comps->p_touch);
	substraction_p_to_v_NA(comps->object_normal, comps->p_space, comps->origin_zero);
	normalize_vector_NA(comps->object_normal);///A RETIRER??
	transpose_matrix_NA(comps->transp_inv, comps->obj_inv);
	matrix_point_multiplication_new(comps->v_norm_parral, comps->transp_inv, comps->object_normal);
	normalize_vector_NA(comps->v_norm_parral);
	if (comps->type == CYLINDER)
		normal_caps(comps);	

}

void	normal_caps(t_comps *comps)
{
	float dist;

	dist = (comps->p_space->x * comps->p_space->x) + (comps->p_space->z * comps->p_space->z);
	if (dist <= 1 && comps->p_space->y >= comps->height - EPSILON)
	{
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = 1;
		comps->v_norm_parral->z = 0;
		return;
	}
	if (dist <= 1 && comps->p_space->y <= -comps->height + EPSILON)
	{
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = -1;
		comps->v_norm_parral->z = 0;
		return;
	}
	comps->v_norm_parral->x = comps->p_space->x;
	comps->v_norm_parral->y = 0;
	comps->v_norm_parral->z = comps->p_space->z;
}

