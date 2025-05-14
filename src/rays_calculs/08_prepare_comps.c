/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_prepare_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:25 by syl               #+#    #+#             */
/*   Updated: 2025/05/14 23:10:25 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	normal_at_cyl(t_comps *comps);

void	prepare_computation_pix(t_pix *pix)
{
	t_coord	term_for_p_local;
	t_coord	p_local_on_surface;

	// Calcul de P_local = O_local + t_local * D_local
	// pix->comps->r_origin est O_local (depuis save_in_comps)
	// pix->comps->r_dir est D_local (depuis save_in_comps)
	// pix->comps->closestt est t_local
	scalar_mult_na(&term_for_p_local, pix->comps->r_dir, pix->comps->closestt);
	addition_na(&p_local_on_surface, pix->comps->r_origin, &term_for_p_local);
	// p_local_on_surface.t est mis à 1 par addition_na, ce qui est correct pour un point.

	// Transformation de P_local vers P_world (sera pix->comps->p_touch)
	// pix->comps->obj->m_transf est la matrice objet-vers-monde
	matrix_point_multiplication_new(pix->comps->p_touch,
		pix->comps->obj->m_transf, &p_local_on_surface);

	// Calcul de v_eye en utilisant la direction du rayon MONDE originale pour le pixel
	// pix->r_dir est la direction du rayon monde (devrait être normalisée à la création du rayon)
	negat_na(pix->comps->v_eye, pix->r_dir);
	// Optionnel: si pix->r_dir n'est pas garanti d'être normalisé, décommentez :
	// normalize_vector_na(pix->comps->v_eye);

	if (pix->comps->type == SPHERE)
	{
		normal_at_na(pix->comps);
		if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
			negat_na(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
	}
	if (pix->comps->type == CYLINDER)
	{
		normal_at_cyl(pix->comps);
		// Add the v_eye check for cylinders
		if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
			negat_na(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
	}	
	else if (pix->comps->type == PLAN)
	{
		// La normale d'un plan est constante et est définie par obj->v_axe.
		// Elle est déjà en coordonnées monde.
		copy_coord(pix->comps->v_norm_parral, pix->comps->obj->v_axe);
		normalize_vector_na(pix->comps->v_norm_parral);

		// S'assurer que la normale pointe "vers l'extérieur" par rapport à la caméra/rayon.
		// Si le produit scalaire avec v_eye est négatif, la normale pointe dans la même direction générale que v_eye (vers l'intérieur de la surface du point de vue du rayon),
		// donc nous l'inversons pour qu'elle pointe vers l'extérieur.
		if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
			negat_na(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
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
	t_coord	local_normal_vec;

	// 1. Calculate p_space = obj_inv * p_touch (point of intersection in local object space)
	matrix_point_multiplication_new(comps->p_space, comps->obj_inv, comps->p_touch);

	// 2. Determine local normal based on intersection type
	if (comps->t_count == 8) // Bottom cap (local normal is (0, -1, 0) for a Y-aligned cylinder)
	{
		vector_fill(&local_normal_vec, 0, -1, 0);
	}
	else if (comps->t_count == 9) // Top cap (local normal is (0, 1, 0) for a Y-aligned cylinder)
	{
		vector_fill(&local_normal_vec, 0, 1, 0);
	}
	else // Cylinder body (t_count is typically 1 or 2)
	{
		// For a canonical cylinder aligned along Y-axis, centered at origin,
		// the normal at a point (px, py, pz) on its surface (ignoring caps) is (px, 0, pz).
		local_normal_vec.x = comps->p_space->x;
		local_normal_vec.y = 0; // Normal is perpendicular to Y-axis for the body
		local_normal_vec.z = comps->p_space->z;
	}
	local_normal_vec.t = 0; // Ensure it's treated as a vector

	// 3. Normalize local_normal_vec (primarily for body, caps are already unit length if vector_fill sets them so)
	normalize_vector_na(&local_normal_vec);

	// 4. Calculate transp_inv = transpose(obj_inv)
	transpose_matrix(comps->transp_inv, comps->obj_inv);

	// 5. Transform local_normal_vec to world space: v_norm_parral = transp_inv * local_normal_vec
	matrix_point_multiplication_new_2(comps->v_norm_parral, comps->transp_inv, &local_normal_vec);
	
	// 6. Normalize the final world-space normal
	normalize_vector_na(comps->v_norm_parral);
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
