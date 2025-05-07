/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_camera_construction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:51:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/06 10:26:35 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	constructing_camera(t_pix ***pix)
{
	//calcul de la matix de transformation
	view_camera(pix[0][0]->cam);

	//calcul cam_m inverse
	inverse4x4(pix[0][0]->cam->m_transf, pix[0][0]->cam->m_inverse);
	
	//calcul de la taille des pixels
	pixel_size(pix[0][0]);
}


// creer la matrice de transformation de la camera pour pouvoir la bouger
void	view_camera(t_camera *cam)
{
	if (cam->v_axe->x == 0 && fabs(cam->v_axe->y) == 1 &&  cam->v_axe->z == 0)
		vector_fill(cam->v_up, 0, 0, -1);

	cross_product_NA(cam->v_left, cam->v_up, cam->v_axe);
	cross_product_NA(cam->v_true_up, cam->v_axe, cam->v_left);
	normalize_vector_NA(cam->v_true_up);
	normalize_vector_NA(cam->v_left);

	matrix_fill(cam->m_orient, 0, 0, cam->v_left->x);
	matrix_fill(cam->m_orient, 0, 1, cam->v_left->y);
	matrix_fill(cam->m_orient, 0, 2, cam->v_left->z);
	matrix_fill(cam->m_orient, 0, 3, 0);

	matrix_fill(cam->m_orient, 1, 0, cam->v_true_up->x);
	matrix_fill(cam->m_orient, 1, 1, cam->v_true_up->y);
	matrix_fill(cam->m_orient, 1, 2, cam->v_true_up->z);
	matrix_fill(cam->m_orient, 1, 3, 0);

	matrix_fill(cam->m_orient, 2, 0, -1 * cam->v_axe->x);
	matrix_fill(cam->m_orient, 2, 1, -1 * cam->v_axe->y);
	matrix_fill(cam->m_orient, 2, 2, -1 * cam->v_axe->z);
	matrix_fill(cam->m_orient, 2, 3, 0);

	matrix_fill(cam->m_orient, 3, 0, 0);
	matrix_fill(cam->m_orient, 3, 1, 0);
	matrix_fill(cam->m_orient, 3, 2, 0);
	matrix_fill(cam->m_orient, 3, 3, 1);

	fill_translation_matrix(cam->m_transl, -1 * cam->p_coord->x,
		-1 * cam->p_coord->y, -1 * cam->p_coord->z);
	matrix_mult_3(cam->m_transf, cam->m_orient, cam->m_transl);
}


// I think ok =)
void	pixel_size(t_pix *pix)
{
	float	half_view;
	float	half_height;
	float	aspect;

	half_view = tan(pix->cam->fov/2);
	aspect = pix->cam->canva_width / pix->cam->canva_height;
	if (aspect >= 1)
	{
		pix->cam->half_width = half_view;
		pix->cam->half_height = half_view / aspect;
	}
	else
	{
		pix->cam->half_width = half_view * aspect;
		pix->cam->half_height = half_view;
	}
	pix->cam->pixel_size = (pix->cam->half_width * 2) / pix->cam->canva_width;
}
