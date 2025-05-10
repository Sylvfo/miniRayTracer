/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_prepare_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:25 by syl               #+#    #+#             */
/*   Updated: 2025/05/10 12:39:25 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// j'ai retiré pix[x][y]->comps->inside = true; 
//sous dot_product(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->v_eye) < 0
void	prepare_computation(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->comps->type != NONE)
				prepare_computation_pix(pix[x][y]);
			y++;
		}
		x++;
	}
}

void	prepare_computation_pix(t_pix *pix)
{
	position_NA(pix, pix->comps->r_dir, pix->comps->closestt);
	negat_NA(pix->comps->v_eye, pix->comps->r_dir);
	if (pix->comps->type == SPHERE || pix->comps->type == CYLINDER)
	{
		normal_at_NA(pix->comps);
		if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
			negat_NA(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
	}
	else if (pix->comps->type == PLAN)
		copy_coord(pix->comps->v_norm_parral, pix->comps->obj->v_axe);
}

void	normal_at_NA(t_comps *comps)
{
	matrix_point_multiplication_new(comps->p_space,
		comps->obj_inv, comps->p_touch);
	substraction_p_to_v_NA(comps->object_normal,
		comps->p_space, comps->origin_zero);
	normalize_vector_NA(comps->object_normal);
	transpose_matrix(comps->transp_inv, comps->obj_inv);
	matrix_point_multiplication_new(comps->v_norm_parral,
		comps->transp_inv, comps->object_normal);
	normalize_vector_NA(comps->v_norm_parral);
	if (comps->type == CYLINDER)
		normal_caps(comps);
}

void	normal_caps(t_comps *comps)
{
	float	dist;

	dist = (comps->p_space->x * comps->p_space->x) + (comps->p_space->z * comps->p_space->z);
	// Debug : affiche la valeur de y et height
	printf("[DEBUG CAPS] p_space->y=%.3f, height=%.3f\n", comps->p_space->y, comps->height);
	if (dist <= 1 && fabs(comps->p_space->y - comps->height) < EPSILON)
	{
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = 1;
		comps->v_norm_parral->z = 0;
		return ;
	}
	if (dist <= 1 && fabs(comps->p_space->y + comps->height) < EPSILON)
	{
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = -1;
		comps->v_norm_parral->z = 0;
		return ;
	}
	comps->v_norm_parral->x = comps->p_space->x;
	comps->v_norm_parral->y = 0;
	comps->v_norm_parral->z = comps->p_space->z;
}
