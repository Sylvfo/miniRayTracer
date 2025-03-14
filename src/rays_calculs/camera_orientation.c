/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:46:23 by syl               #+#    #+#             */
/*   Updated: 2025/03/14 22:47:36 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//You specify where you want the eye to be in the scene (the from parameter)
//the point in the scene at which you want to look (the to parameter)
//a vector indicating which direction is up

//The function then returns to you the corresponding transformation matrix.
// p_from = camera coord??
// p_to???
//v_up c est le vecteur normé de la caméra??

float *view_camera(t_coord *p_coordcam, t_coord *v_dircam)
{
	float *m_view;

	t_coord *v_left;
	t_coord *vn_up;
	t_coord *v_true_up;
	float	*m_orientation;
	float *m_translation;

	vn_up = create_vector(0, 1, 0);// Axe Y global par défaut
	
	//verifier si pas pareil....
	// Vérifier que v_forward n'est pas colinéaire avec v_up
	if (fabs(v_dircam->x) < 1e-6 && fabs(v_dircam->z) < 1e-6)
		vn_up = create_vector(0, 0, 1); // Si la caméra regarde pile en haut/bas, chan

	v_left = cross_product(vn_up, v_dircam);
	v_true_up = cross_product(v_dircam, v_left);
	m_orientation = create_matrix(4, 4);

	matrix_fill(m_orientation, 0, 0, v_left->x);
	matrix_fill(m_orientation, 1, 0, v_true_up->x);
	matrix_fill(m_orientation, 2, 0, (-1 * v_dircam->x));
	matrix_fill(m_orientation, 3, 0, 0);

	matrix_fill(m_orientation, 0, 1, v_left->y);
	matrix_fill(m_orientation, 1, 1, v_true_up->y);
	matrix_fill(m_orientation, 2, 1, (-1 * v_dircam->y));
	matrix_fill(m_orientation, 3, 1, 0);

	matrix_fill(m_orientation, 0, 2, v_left->z);
	matrix_fill(m_orientation, 1, 2, v_true_up->z);
	matrix_fill(m_orientation, 2, 2, (-1 * v_dircam->z));
	matrix_fill(m_orientation, 3, 2, 0);

	matrix_fill(m_orientation, 0, 3, 0);
	matrix_fill(m_orientation, 1, 3, 0);
	matrix_fill(m_orientation, 2, 3, 0);
	matrix_fill(m_orientation, 3, 3, 1);
	
	m_translation = create_translation_matrix(-p_coordcam->x, -p_coordcam->y, -p_coordcam->z);
	m_view = matrix_multiplication_44(m_orientation, m_translation);
	return (m_view);
}


/*
float *view_camera(t_coord *p_from, t_coord *p_to, t_coord *v_up)
{
	float *m_view;
	t_coord *v_forward;
	t_coord *v_left;
	t_coord *vn_up;
	t_coord *v_true_up;
	float	*m_orientation;
	float *m_translation;

	v_forward = substraction(p_to, p_from);// defint axe z de la caméra
	v_forward = normalize_vector(v_forward);
	vn_up = normalize_vector(v_up);
	v_left = cross_product(v_forward, vn_up); //definit l axe X de la caméra
//	v_left = cross_product(vn_up, v_forward); peut etre il faut changer comme ça
	v_true_up = cross_product(v_left, v_forward); //definit l axe Y de la camera . 
	m_orientation = create_matrix(4, 4);

	matrix_fill(m_orientation, 0, 0, v_left->x);
	matrix_fill(m_orientation, 1, 0, v_true_up->x);
	matrix_fill(m_orientation, 2, 0, (-1 * v_forward->x));
	matrix_fill(m_orientation, 3, 0, 0);

	matrix_fill(m_orientation, 0, 1, v_left->y);
	matrix_fill(m_orientation, 1, 1, v_true_up->y);
	matrix_fill(m_orientation, 2, 1, (-1 * v_forward->y));
	matrix_fill(m_orientation, 3, 1, 0);

	matrix_fill(m_orientation, 0, 2, v_left->z);
	matrix_fill(m_orientation, 1, 2, v_true_up->z);
	matrix_fill(m_orientation, 2, 2, (-1 * v_forward->z));
	matrix_fill(m_orientation, 3, 2, 0);

	matrix_fill(m_orientation, 0, 3, 0);
	matrix_fill(m_orientation, 1, 3, 0);
	matrix_fill(m_orientation, 2, 3, 0);
	matrix_fill(m_orientation, 3, 3, 1);
	
	m_translation = create_translation_matrix(-p_from->x, -p_from->y, -p_from->z);
	m_view = matrix_multiplication_44(m_orientation, m_translation);
	return (m_view);
}

*/