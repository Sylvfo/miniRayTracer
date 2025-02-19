/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transf_testing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:57:22 by syl               #+#    #+#             */
/*   Updated: 2025/02/19 16:16:27 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void test_transformation(void)
{
	t_coord *p_point;
	float	*m_transl;
	t_coord	*p_result;
	float	*m_inverted;
	t_coord	*v_vector;
	t_coord	*new_v;

/*	p_point = create_point(-3, 4, 5);
	m_transl = create_translation_matrix(5, -3, 2);
	m_inverted = inverted_matrix_44(m_transl);
	p_result = matrix_multiplication_44_coord(m_inverted, p_point);
	print_matrix(m_transl);
	print_point(p_result);
	*/

	v_vector = create_vector(-3, 4, 5);
	m_transl = create_translation_matrix(5, -3, 2);
	new_v = matrix_multiplication_44_coord(m_transl, v_vector);
	print_vector(new_v);

	free(p_point);
	free(m_transl);
	free(p_result);
}

void test_scaling(void)
{
	t_coord	*v_vector;
	t_coord	*new_v;
	float *m_scale;

	v_vector = create_vector(-3, 4, 5);
	scaling(t_coord *v_vector, float x, float y, float z)



}