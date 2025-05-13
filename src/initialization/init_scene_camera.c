/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:20:32 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/13 14:39:54 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/initialization.h"

void	init_pix_camera(t_pix ***pix)
{
	color_int_to_rgb(BAKGROUND_COLOR, pix[0][0]->obj[0][0]->color);
	pix[0][0]->obj[0][0]->color->r
		= int_to_float(pix[0][0]->obj[0][0]->color->r);
	pix[0][0]->obj[0][0]->color->g
		= int_to_float(pix[0][0]->obj[0][0]->color->g);
	pix[0][0]->obj[0][0]->color->b
		= int_to_float(pix[0][0]->obj[0][0]->color->b);
	pix[0][0]->cam->v_left = create_vector(0, 0, 0);
	pix[0][0]->cam->v_up = create_vector(0, 1, 0);
	pix[0][0]->cam->v_true_up = create_vector(0, 0, 0);
	pix[0][0]->cam->m_orient = create_indentity_matrix_44();
	pix[0][0]->cam->m_transl = create_indentity_matrix_44();
	pix[0][0]->cam->m_transf = create_indentity_matrix_44();
	pix[0][0]->cam->m_inverse = create_indentity_matrix_44();
	pix[0][0]->cam->p_zero = create_point(0, 0, 0);
	pix[0][0]->cam->view_height = WND_HEIGHT;
	pix[0][0]->cam->view_width = WND_WIDTH;
	pix[0][0]->cam->canva_height = WND_HEIGHT;
	pix[0][0]->cam->canva_width = WND_WIDTH;
}
