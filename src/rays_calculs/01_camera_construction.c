/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_camera_construction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:51:52 by syl               #+#    #+#             */
/*   Updated: 2025/04/28 16:23:25 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	constructing_camera(t_pix ***pix)
{
	pix[0][0]->cam->canva_height = WND_HEIGHT;
	pix[0][0]->cam->canva_width = WND_WIDTH;
	pix[0][0]->cam->fov *= 3.1415 / 180;
	view_camera(pix[0][0]->cam);
//	print_matrix(pix[0][0]->cam->m_transf);
//	inverse4x4(pix[0][0]->cam->m_transf);
//	pix[0][0]->cam->m_inverse = inverted_matrix_44(pix[0][0]->cam->m_transf);
//	copy_matrix_44(pix[0][0]->cam->m_inverse, pix[0][0]->cam->m_transf);
	pix[0][0]->cam->m_inverse = create_indentity_matrix_44();
	if (!pix[0][0]->cam->m_inverse)
	{
		printf("pix[0][0]->cam->m_inverse dans constr\n");
		exit (0);
	}
	matrix_point_multiplication_new(pix[0][0]->cam->p_cam_world, pix[0][0]->cam->m_inverse, pix[0][0]->cam->p_origin_zero);
	//matrix_multiplication_44_coord_NA(pix[0][0]->cam->p_cam_world, pix[0][0]->cam->m_inverse, pix[0][0]->cam->p_origin_zero);
	pixel_size(pix[0][0]);
}

void	pixel_size(t_pix *pix)
{
	float	half_view;
	float	aspect;

	half_view = tan(pix->cam->fov / 2);
	aspect = (float)pix->cam->canva_width / pix->cam->canva_height;

	if (aspect >= 1)
	{
		pix->cam->half_width = half_view;
		pix->cam->half_height = half_view / aspect;
	}
	else
	{
		pix->cam->half_height = half_view;
		pix->cam->half_width = half_view * aspect;
	}
	pix->cam->pixel_size = (pix->cam->half_width * 2) / pix->cam->canva_width;
}

// creer la matrice de transformation de la camera pour pouvoir la bouger
void	view_camera(t_camera *cam)
{
	// Vérifier que v_forward n'est pas colinéaire avec v_up
	if (fabs(cam->v_axe->x) < 1e-6 && fabs(cam->v_axe->z) < 1e-6)
		vector_fill(cam->vn_axe_y, 0, 0, 1);// Si la caméra regarde pile en haut/bas, chan
	cam->v_left = cross_product(cam->vn_axe_y, cam->v_axe);
	cam->v_true_up = cross_product(cam->v_axe, cam->v_left);
	matrix_fill(cam->m_orient, 0, 0, cam->v_left->x);
	matrix_fill(cam->m_orient, 1, 0, cam->v_true_up->x);
	matrix_fill(cam->m_orient, 2, 0, (-1 * cam->v_axe->x));
	matrix_fill(cam->m_orient, 3, 0, 0);
	matrix_fill(cam->m_orient, 0, 1, cam->v_left->y);
	matrix_fill(cam->m_orient, 1, 1, cam->v_true_up->y);
	matrix_fill(cam->m_orient, 2, 1, (-1 * cam->v_axe->y));
	matrix_fill(cam->m_orient, 3, 1, 0);
	matrix_fill(cam->m_orient, 0, 2, cam->v_left->z);
	matrix_fill(cam->m_orient, 1, 2, cam->v_true_up->z);
	matrix_fill(cam->m_orient, 2, 2, (-1 * cam->v_axe->z));
	matrix_fill(cam->m_orient, 3, 2, 0);
	matrix_fill(cam->m_orient, 0, 3, 0);
	matrix_fill(cam->m_orient, 1, 3, 0);
	matrix_fill(cam->m_orient, 2, 3, 0);
	matrix_fill(cam->m_orient, 3, 3, 1);
	fill_translation_matrix(cam->m_transl, -cam->p_coord->x,
		-cam->p_coord->y, -cam->p_coord->z);
	if (!cam->m_transl)
	{
		printf("pas trans cam\n");
		exit (0);
	}
	if (!cam->m_orient)
	{
		printf("pas cam->m_orient\n");
		exit (0);
	}
	if (!cam->m_transf)
	{
		printf("pas cam->m_transf\n");
		exit (0);
	}
	matrix_mult_3(cam->m_transf, cam->m_orient, cam->m_transl);
//	matrix_multiplication_44_NA2(cam->m_transf, cam->m_orient, cam->m_transl);
	//matrix_mult_44_new_NA2(cam->m_transf, cam->m_orient, cam->m_transl);
	if (!cam->m_transf)
	{
		printf("pas cam->m_transf 2\n");
		exit (0);
	}
}
