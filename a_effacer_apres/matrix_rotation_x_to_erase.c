/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation_x_to_erase?.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:50:48 by syl               #+#    #+#             */
/*   Updated: 2025/02/26 15:09:56 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*t_coord *rotation_axe_x(t_coord *p_point, float radian)
{
	float *m_rotation;
	t_coord *p_new;

	m_rotation = create_rotation_x_matrix(radian);
	print_matrix(m_rotation);
	p_new = matrix_multiplication_44_coord(m_rotation, p_point);
	return (p_new);
}

float *create_rotation_x_matrix(float radian)
{
	float *m_rotation;
	float sinr;
	float cosr;

	sinr = sin(radian);
	cosr = cos(radian);

	m_rotation = create_matrix(4, 4);
	matrix_fill(m_rotation, 0, 0, 1);
	matrix_fill(m_rotation, 1, 1, cosr);
	matrix_fill(m_rotation, 1, 2, -sinr);
	matrix_fill(m_rotation, 2, 1, sinr);
	matrix_fill(m_rotation, 2, 2, cosr);	
	matrix_fill(m_rotation, 3, 3, 1);
	return (m_rotation);
}

// pour tourner dans l autre sense
t_coord *rotation_axe_x_inverse(t_coord *p_point, float radian)
{
	float *m_rotation;
	t_coord *p_new;

	m_rotation = create_rotation_x_matrix(radian);
	m_rotation = inverted_matrix_44(m_rotation);
	p_new = matrix_multiplication_44_coord(m_rotation, p_point);
	return (p_new);
}*/

