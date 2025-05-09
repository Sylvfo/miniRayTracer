/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_transl_scale.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:51:07 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 17:04:48 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	translation_matrix_coord(t_obj *obj)
{
	matrix_fill(obj->m_transl, 0, 3, obj->p_coord->x);
	matrix_fill(obj->m_transl, 1, 3, obj->p_coord->y);
	matrix_fill(obj->m_transl, 2, 3, obj->p_coord->z);
	matrix_fill(obj->m_transl, 3, 3, 1);
}

void	fill_translation_matrix(float *m_transl, float x, float y, float z)
{
	if (!m_transl)
	{
		printf("no  m_transl in fill_translation_matrix \n");
	}
	matrix_fill(m_transl, 0, 3, x);
	matrix_fill(m_transl, 1, 3, y);
	matrix_fill(m_transl, 2, 3, z);
	matrix_fill(m_transl, 3, 3, 1);
}

void	scaling_matrix_coord(t_obj *obj)
{
	matrix_fill(obj->m_scale, 0, 0, obj->diam);
	matrix_fill(obj->m_scale, 1, 1, obj->diam);
	matrix_fill(obj->m_scale, 2, 2, obj->diam);
	matrix_fill(obj->m_scale, 3, 3, 1);
}
