/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scaling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:48:08 by syl               #+#    #+#             */
/*   Updated: 2025/02/27 10:31:38 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// tout ca c est testé c est bon =).
t_coord	*scaling(t_coord *v_p_old, float x, float y, float z)
{
	float	*m_scale;
	t_coord	*v_p_new;

	m_scale = create_scaling_matrix(x, y, z);
	if (!m_scale)
		return (NULL);
	v_p_new = matrix_multiplication_44_coord(m_scale, v_p_old);
	return (v_p_new);
}

float	*create_scaling_matrix(float x, float y, float z)
{
	float	*m_scale;

	m_scale = create_matrix(4, 4);
	if (!m_scale)
		return (NULL);
	matrix_fill(m_scale, 0, 0, x);
	matrix_fill(m_scale, 1, 1, y);
	matrix_fill(m_scale, 2, 2, z);
	matrix_fill(m_scale, 3, 3, 1);
	return (m_scale);
}

t_coord	*scaling_inverse(t_coord *v_p_old, float x, float y, float z)
{
	float	*m_scale;
	t_coord	*v_p_new;

	m_scale = create_scaling_matrix(x, y, z);
	m_scale = inverted_matrix_44(m_scale);
	if (!m_scale)
		return (NULL);
	v_p_new = matrix_multiplication_44_coord(m_scale, v_p_old);
	return (v_p_new);
}
