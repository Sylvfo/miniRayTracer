/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_inverting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:18:41 by syl               #+#    #+#             */
/*   Updated: 2025/02/16 13:41:50 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void test_inverting(void)
{
	float *m_22;
	float a;

	m_22 = create_matrix2(2, 2);
	matrix_fill2(m_22, 0, 0, 1);
	matrix_fill2(m_22, 0, 1, 5);
	matrix_fill2(m_22, 1, 0, -3);
	matrix_fill2(m_22, 1, 1, 2);
	print_matrix2(m_22);
	a = determinant_22(m_22);
	printf("determinant is %.2f \n", a);

	free(m_22);
}