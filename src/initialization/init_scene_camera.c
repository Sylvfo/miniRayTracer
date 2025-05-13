/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:20:32 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 16:28:26 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/initialization.h"

void	init_pix_camera(t_pix ***pix)
{
	//ici modifié par sylvie
/*	pix[0][0]->cam = malloc(sizeof(t_camera));
	if (!pix[0][0]->cam)
		return ;*/
	pix[0][0]->cam->p_coord = malloc(sizeof(t_coord));
	pix[0][0]->cam->v_axe = malloc(sizeof(t_coord));
	if (!pix[0][0]->cam->p_coord || !pix[0][0]->cam->v_axe)
	{
		free(pix[0][0]->cam->p_coord);
		free(pix[0][0]->cam->v_axe);
		free(pix[0][0]->cam);
		return ;
	}
	pix[0][0]->cam->p_coord->x = 0.0f;
	pix[0][0]->cam->p_coord->y = 0.0f;
	pix[0][0]->cam->p_coord->z = 0.0f;
	pix[0][0]->cam->p_coord->t = 1;
	pix[0][0]->cam->v_axe->x = 0.0f;
	pix[0][0]->cam->v_axe->y = 0.0f;
	pix[0][0]->cam->v_axe->z = 1.0f;
	pix[0][0]->cam->v_axe->t = 0;
	pix[0][0]->cam->fov = 90.0f;

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
	pix[0][0]->cam->fov *= 0.0174533;

	//ici modifié par sylvie


}
