/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_prepare_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:25 by syl               #+#    #+#             */
/*   Updated: 2025/05/14 21:57:02 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	normal_at_cyl(t_comps *comps);

void	prepare_computation_pix(t_pix *pix)
{
	position_na(pix, pix->comps->r_dir, pix->comps->closestt);
	negat_na(pix->comps->v_eye, pix->comps->r_dir);
	if (pix->comps->type == SPHERE)
	{
		normal_at_na(pix->comps);
		if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
			negat_na(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
	}
	if (pix->comps->type == CYLINDER)
	{
	//	copy_coord(pix->comps->v_norm_parral, pix->comps->obj->v_axe);
		normal_at_cyl(pix->comps);
	//	if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
	//		negat_na(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
	}	
	else if (pix->comps->type == PLAN)
	{
	//	vector_fill(pix->comps->object_normal, 0, 1, 0);
		copy_coord(pix->comps->v_norm_parral, pix->comps->object_normal);


		
		transpose_matrix(pix->comps->transp_inv, pix->comps->obj_inv);
		matrix_point_multiplication_new_2(pix->comps->v_norm_parral,
		pix->comps->transp_inv, pix->comps->object_normal);
		normalize_vector_na(pix->comps->v_norm_parral);
	//	print_vector(pix->comps->v_norm_parral);

	}
	
}


/*
void	normal_caps(t_comps *comps)
{
	float	dist;


//	comps->v_norm_parral->x = comps->obj->v_axe->x; 
//	comps->v_norm_parral->y = comps->obj->v_axe->y;
//	comps->v_norm_parral->z = comps->obj->v_axe->z;
//	comps->v_norm_parral->t = 0;

	dist = (comps->p_space->x * comps->p_space->x)
		+ (comps->p_space->z * comps->p_space->z);
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
}*/


void	normal_caps(t_comps *comps)
{
	float	dist;

	dist = (comps->p_space->x * comps->p_space->x)
		+ (comps->p_space->z * comps->p_space->z);
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


void	normal_at_na(t_comps *comps)
{
	matrix_point_multiplication_new(comps->p_space,
		comps->obj_inv, comps->p_touch);
	substraction_p_to_v_na(comps->object_normal,
		comps->p_space, comps->origin_zero);
	normalize_vector_na(comps->object_normal);
	transpose_matrix(comps->transp_inv, comps->obj_inv);
	matrix_point_multiplication_new_2(comps->v_norm_parral,
		comps->transp_inv, comps->object_normal);
	normalize_vector_na(comps->v_norm_parral);
}

void	normal_at_cyl(t_comps *comps)
{
	matrix_point_multiplication_new(comps->p_space,
		comps->obj_inv, comps->p_touch);

	substraction_p_to_v_na(comps->object_normal,
		comps->p_space, comps->origin_zero);
	comps->object_normal->y = 0;
	if (comps->t_count > 4)
	{
		comps->v_norm_parral->x = comps->obj->v_axe->x;
		comps->v_norm_parral->y = comps->obj->v_axe->y;
		comps->v_norm_parral->z = comps->obj->v_axe->z;
	}
	normalize_vector_na(comps->object_normal);
	transpose_matrix(comps->transp_inv, comps->obj_inv);
	matrix_point_multiplication_new(comps->v_norm_parral,
		comps->transp_inv, comps->object_normal);
	normalize_vector_na(comps->v_norm_parral);
	substraction_p_to_v_na(comps->object_normal,
		comps->p_space, comps->origin_zero);
	comps->v_norm_parral->x = comps->p_space->x;
	comps->v_norm_parral->y = 0;
	comps->v_norm_parral->z = comps->p_space->z;
}

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
