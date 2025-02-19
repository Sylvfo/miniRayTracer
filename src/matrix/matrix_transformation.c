/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:51:07 by syl               #+#    #+#             */
/*   Updated: 2025/02/19 16:15:15 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float *create_translation_matrix(float x, float y, float z)
{
	float *m_transl;

	m_transl = create_indentity_matrix_44();
	if (!m_transl)
		return (NULL);
	matrix_fill(m_transl, 0, 3, x);
	matrix_fill(m_transl, 1, 3, y);
	matrix_fill(m_transl, 2, 3, z);
	matrix_fill(m_transl, 3, 3, 1);
	return (m_transl);
}

float *translation(t_coord *p_point, float x, float y, float z)
{
	float *m_transl;
	t_coord	*p_newpoint;

	//verifier si point??
	m_transl = create_translation_matrix(x, y, z);
	if (!m_transl)
		return (NULL);
	p_newpoint = matrix_multiplication_44_coord(m_transl, p_point);
	return (p_newpoint);
}

t_coord *scaling(t_coord *v_p_old, float x, float y, float z)
{
	float	*m_scale;
	t_coord *v_p_new;

	m_scale = create_scaling_matrix(x, y, z);
	if (!m_scale)
		return (NULL);
	v_p_new = matrix_multiplication_44_coord(m_scale, v_p_old);
	return (v_p_new);
}

float *create_scaling_matrix(float x, float y, float z)
{
	float *m_scale;

	m_scale = create_matrix(4, 4);
	if (!m_scale)
		return (NULL);
	matrix_fill(m_scale, 0, 0, x);
	matrix_fill(m_scale, 1, 1, y);
	matrix_fill(m_scale, 2, 2, z);
	matrix_fill(m_scale, 3, 3, 1);
	return (m_scale);
}