/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_construction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:51:52 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 15:27:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void constructing_camera(t_pix ***pix)
{
	// a deplacer dans init
	color_int_to_rgb(BAKGROUND_COLOR, pix[0][0]->obj[0][0]->color);
	pix[0][0]->obj[0][0]->color->r = int_to_float(pix[0][0]->obj[0][0]->color->r);
	pix[0][0]->obj[0][0]->color->g = int_to_float(pix[0][0]->obj[0][0]->color->g);
	pix[0][0]->obj[0][0]->color->b = int_to_float(pix[0][0]->obj[0][0]->color->b);
	pix[0][0]->cam->canva_height = WND_HEIGHT;
	pix[0][0]->cam->canva_width = WND_WIDTH;
	pix[0][0]->cam->fov *= 3.1415 / 180;
	pix[0][0]->cam->m_transf = view_camera(pix[0][0]->cam->p_coord, pix[0][0]->cam->v_axe);
	pix[0][0]->cam->m_inverse = inverted_matrix_44(pix[0][0]->cam->m_transf);
	pixel_size(pix);
}

// calcul la taille des "pixels" sur le viewport
void pixel_size(t_pix ***pix)
{
	float half_view;
	float aspect;

	half_view = tan(pix[0][0]->cam->fov / 2);
	aspect = pix[0][0]->cam->canva_width / pix[0][0]->cam->canva_height;
//	aspect = pix[0][0]->cam->canva_height / pix[0][0]->cam->canva_width;
	if (aspect >= 1)
	{
		pix[0][0]->cam->half_width = half_view;
		pix[0][0]->cam->half_height = half_view / aspect;
	}
	if (aspect < 1)
	{
		pix[0][0]->cam->half_height = half_view;
		pix[0][0]->cam->half_width = half_view * aspect;		
	}
	pix[0][0]->cam->pixel_size = (pix[0][0]->cam->half_width * 2) / pix[0][0]->cam->canva_height;
}

// creer la matrice de transformation de la camera pour pouvoir la bouger
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

//	avant d enlever -1
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