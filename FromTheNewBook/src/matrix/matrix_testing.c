/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_testing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:09:13 by sforster          #+#    #+#             */
/*   Updated: 2025/02/14 15:24:05 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool test_multiplication(void)
{
	float *m_test;
	float *m_test2;
	float *m_test3;
	m_test2 = create_matrix2(4, 4);
	matrix_fill2(m_test2, 0, 0, 1);
	matrix_fill2(m_test2, 0, 1, 2);
	matrix_fill2(m_test2, 0, 2, 3);
	matrix_fill2(m_test2, 0, 3, 4);

	matrix_fill2(m_test2, 1, 0, 5);
	matrix_fill2(m_test2, 1, 1, 6);
	matrix_fill2(m_test2, 1, 2, 7);
	matrix_fill2(m_test2, 1, 3, 8);	

	matrix_fill2(m_test2, 2, 0, 9);
	matrix_fill2(m_test2, 2, 1, 8);
	matrix_fill2(m_test2, 2, 2, 7);
	matrix_fill2(m_test2, 2, 3, 6);

	matrix_fill2(m_test2, 3, 0, 5);
	matrix_fill2(m_test2, 3, 1, 4);
	matrix_fill2(m_test2, 3, 2, 3);
	matrix_fill2(m_test2, 3, 3, 2);	

	print_matrix2(m_test2);
	m_test = create_matrix2(4, 4);
	matrix_fill2(m_test, 0, 0, -2);
	matrix_fill2(m_test, 0, 1, 1);
	matrix_fill2(m_test, 0, 2, 2);
	matrix_fill2(m_test, 0, 3, 3);

	matrix_fill2(m_test, 1, 0, 3);
	matrix_fill2(m_test, 1, 1, 2);
	matrix_fill2(m_test, 1, 2, 1);
	matrix_fill2(m_test, 1, 3, -1);	

	matrix_fill2(m_test, 2, 0, 4);
	matrix_fill2(m_test, 2, 1, 3);
	matrix_fill2(m_test, 2, 2, 6);
	matrix_fill2(m_test, 2, 3, 5);

	matrix_fill2(m_test, 3, 0, 1);
	matrix_fill2(m_test, 3, 1, 2);
	matrix_fill2(m_test, 3, 2, 7);
	matrix_fill2(m_test, 3, 3, 8);	

	print_matrix2(m_test);

	m_test3 = matrix_multiplication_44(m_test2, m_test);

	print_matrix2(m_test3);
	free(m_test);
	free(m_test2);	
}

void test_multiplication2(void)
{
	float *m_test;
	t_coord *p_point;
	t_coord *p_point2;

	m_test = create_matrix2(4, 4);
	matrix_fill2(m_test, 0, 0, 1);
	matrix_fill2(m_test, 0, 1, 2);
	matrix_fill2(m_test, 0, 2, 3);
	matrix_fill2(m_test, 0, 3, 4);

	matrix_fill2(m_test, 1, 0, 2);
	matrix_fill2(m_test, 1, 1, 4);
	matrix_fill2(m_test, 1, 2, 4);
	matrix_fill2(m_test, 1, 3, 2);	

	matrix_fill2(m_test, 2, 0, 8);
	matrix_fill2(m_test, 2, 1, 6);
	matrix_fill2(m_test, 2, 2, 4);
	matrix_fill2(m_test, 2, 3, 1);

	matrix_fill2(m_test, 3, 0, 0);
	matrix_fill2(m_test, 3, 1, 0);
	matrix_fill2(m_test, 3, 2, 0);
	matrix_fill2(m_test, 3, 3, 1);	

	print_matrix2(m_test);
	
	p_point = create_point(1, 2, 3);

	p_point2 = matrix_multiplication_44_coord(m_test, p_point);


	print_point(p_point2);
	free(p_point);
	free(m_test);

}