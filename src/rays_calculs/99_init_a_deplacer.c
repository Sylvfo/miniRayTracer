/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_init_a_deplacer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:35:09 by sforster          #+#    #+#             */
/*   Updated: 2025/04/22 11:33:52 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minirt.h"

bool init_a_deplacer(t_pix ***pix)
{
	color_int_to_rgb(BAKGROUND_COLOR, pix[0][0]->obj[0][0]->color);
	pix[0][0]->obj[0][0]->color->r = int_to_float(pix[0][0]->obj[0][0]->color->r);
	pix[0][0]->obj[0][0]->color->g = int_to_float(pix[0][0]->obj[0][0]->color->g);
	pix[0][0]->obj[0][0]->color->b = int_to_float(pix[0][0]->obj[0][0]->color->b);

	// camera
	pix[0][0]->cam->vn_axe_y = create_vector(0, 1, 0);// Axe Y global par défaut
	pix[0][0]->cam->v_left = create_vector(0, 1, 0);//or init?
	pix[0][0]->cam->v_true_up = create_vector(0, 0, 0);
	pix[0][0]->cam->m_orient = create_matrix(4, 4);
	pix[0][0]->cam->m_transl = create_matrix(4, 4);
	pix[0][0]->cam->m_transf = create_matrix(4, 4);
	
//	pix[0][0]->cam->m_inverse = create_matrix(4, 4);
	if (!pix[0][0]->cam->m_transf || !pix[0][0]->cam->v_left || !pix[0][0]->cam->v_true_up
		|| !pix[0][0]->cam->m_orient || !pix[0][0]->cam->m_transl || !pix[0][0]->cam->m_transf)
	{
		printf("error malloc cam\n");
		return (false);
	}
	return true;
}