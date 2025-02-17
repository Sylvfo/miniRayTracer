/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_testing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:09:13 by sforster          #+#    #+#             */
/*   Updated: 2025/02/17 17:02:57 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
avant dans main
	float *m_identity;

	m_identity = create_indentity_matrix_44();
	print_matrix(m_identity);
	test_multiplication3();
	transposing_matrix_44(m_identity);
	print_matrix(m_identity);
	free(m_identity);

	test_inverting();
	test_submatrix();
	test_minor_33();
	test_determinant_33();
	test_determinant_44();
	test_invert_44();
//	test_mult_product_inverse();
*/

/*
bool test_multiplication(void)
{
	float *m_test;
	float *m_test2;
	float *m_test3;
	m_test2 = create_matrix(4, 4);
	matrix_fill(m_test2, 0, 0, 1);
	matrix_fill(m_test2, 0, 1, 2);
	matrix_fill(m_test2, 0, 2, 3);
	matrix_fill(m_test2, 0, 3, 4);

	matrix_fill(m_test2, 1, 0, 5);
	matrix_fill(m_test2, 1, 1, 6);
	matrix_fill(m_test2, 1, 2, 7);
	matrix_fill(m_test2, 1, 3, 8);	

	matrix_fill(m_test2, 2, 0, 9);
	matrix_fill(m_test2, 2, 1, 8);
	matrix_fill(m_test2, 2, 2, 7);
	matrix_fill(m_test2, 2, 3, 6);

	matrix_fill(m_test2, 3, 0, 5);
	matrix_fill(m_test2, 3, 1, 4);
	matrix_fill(m_test2, 3, 2, 3);
	matrix_fill(m_test2, 3, 3, 2);	

	print_matrix(m_test2);
	m_test = create_matrix(4, 4);
	matrix_fill(m_test, 0, 0, -2);
	matrix_fill(m_test, 0, 1, 1);
	matrix_fill(m_test, 0, 2, 2);
	matrix_fill(m_test, 0, 3, 3);

	matrix_fill(m_test, 1, 0, 3);
	matrix_fill(m_test, 1, 1, 2);
	matrix_fill(m_test, 1, 2, 1);
	matrix_fill(m_test, 1, 3, -1);	

	matrix_fill(m_test, 2, 0, 4);
	matrix_fill(m_test, 2, 1, 3);
	matrix_fill(m_test, 2, 2, 6);
	matrix_fill(m_test, 2, 3, 5);

	matrix_fill(m_test, 3, 0, 1);
	matrix_fill(m_test, 3, 1, 2);
	matrix_fill(m_test, 3, 2, 7);
	matrix_fill(m_test, 3, 3, 8);	

	print_matrix(m_test);

	m_test3 = matrix_multiplication_44(m_test2, m_test);

	print_matrix(m_test3);
	free(m_test);
	free(m_test2);	
}

void test_multiplication2(void)
{
	float *m_test;
	t_coord *p_point;
	t_coord *p_point2;

	m_test = create_matrix(4, 4);
	matrix_fill(m_test, 0, 0, 1);
	matrix_fill(m_test, 0, 1, 2);
	matrix_fill(m_test, 0, 2, 3);
	matrix_fill(m_test, 0, 3, 4);

	matrix_fill(m_test, 1, 0, 2);
	matrix_fill(m_test, 1, 1, 4);
	matrix_fill(m_test, 1, 2, 4);
	matrix_fill(m_test, 1, 3, 2);	

	matrix_fill(m_test, 2, 0, 8);
	matrix_fill(m_test, 2, 1, 6);
	matrix_fill(m_test, 2, 2, 4);
	matrix_fill(m_test, 2, 3, 1);

	matrix_fill(m_test, 3, 0, 0);
	matrix_fill(m_test, 3, 1, 0);
	matrix_fill(m_test, 3, 2, 0);
	matrix_fill(m_test, 3, 3, 1);	

	print_matrix(m_test);
	
	p_point = create_point(1, 2, 3);

	p_point2 = matrix_multiplication_44_coord(m_test, p_point);


	print_point(p_point2);
	free(p_point);
	free(m_test);

}

void test_multiplication3(void)
{
	float *m_test;
	t_coord *p_point;
	t_coord *p_point2;

	m_test = create_matrix(4, 4);
	matrix_fill(m_test, 0, 0, -6);
	matrix_fill(m_test, 0, 1, 1);
	matrix_fill(m_test, 0, 2, 1);
	matrix_fill(m_test, 0, 3, 6);

	matrix_fill(m_test, 1, 0, -8);
	matrix_fill(m_test, 1, 1, 5);
	matrix_fill(m_test, 1, 2, 8);
	matrix_fill(m_test, 1, 3, 6);	

	matrix_fill(m_test, 2, 0, -1);
	matrix_fill(m_test, 2, 1, 0);
	matrix_fill(m_test, 2, 2, 8);
	matrix_fill(m_test, 2, 3, 2);

	matrix_fill(m_test, 3, 0, -7);
	matrix_fill(m_test, 3, 1, 1);
	matrix_fill(m_test, 3, 2, -1);
	matrix_fill(m_test, 3, 3, 1);	

	print_matrix(m_test);
	printf("after=== \n");

	transposing_matrix_44(m_test);
	print_matrix(m_test);
	free(m_test);

}

void test_submatrix(void)
{
	float *m_test;
	float *m_test2;

	m_test = create_matrix(4, 4);
	matrix_fill(m_test, 0, 0, -6);
	matrix_fill(m_test, 0, 1, 1);
	matrix_fill(m_test, 0, 2, 1);
	matrix_fill(m_test, 0, 3, 6);

	matrix_fill(m_test, 1, 0, -8);
	matrix_fill(m_test, 1, 1, 5);
	matrix_fill(m_test, 1, 2, 8);
	matrix_fill(m_test, 1, 3, 6);	

	matrix_fill(m_test, 2, 0, -1);
	matrix_fill(m_test, 2, 1, 0);
	matrix_fill(m_test, 2, 2, 8);
	matrix_fill(m_test, 2, 3, 2);

	matrix_fill(m_test, 3, 0, -7);
	matrix_fill(m_test, 3, 1, 1);
	matrix_fill(m_test, 3, 2, -1);
	matrix_fill(m_test, 3, 3, 1);	

	print_matrix(m_test);	
	m_test2 = submatrix(m_test, 2, 1);
	print_matrix(m_test2);
	free(m_test);
	free(m_test2);
}

void test_minor_33(void)
{
	float *m_test;

	m_test = create_matrix(3, 3);
	matrix_fill(m_test, 0, 0, 3);
	matrix_fill(m_test, 0, 1, 5);
	matrix_fill(m_test, 0, 2, 0);

	matrix_fill(m_test, 1, 0, 2);
	matrix_fill(m_test, 1, 1, -1);
	matrix_fill(m_test, 1, 2, -7);	

	matrix_fill(m_test, 2, 0, 6);
	matrix_fill(m_test, 2, 1, -1);
	matrix_fill(m_test, 2, 2, 5);

	print_matrix(m_test);
	printf("minor 33 is %.2f\n", minor_33(m_test, 1, 0));
	free(m_test);
}

void test_determinant_33(void)
{
	float *m_test;

	m_test = create_matrix(3, 3);
	matrix_fill(m_test, 0, 0, 1);
	matrix_fill(m_test, 0, 1, 2);
	matrix_fill(m_test, 0, 2, 6);

	matrix_fill(m_test, 1, 0, -5);
	matrix_fill(m_test, 1, 1, 8);
	matrix_fill(m_test, 1, 2, -4);	

	matrix_fill(m_test, 2, 0, 2);
	matrix_fill(m_test, 2, 1, 6);
	matrix_fill(m_test, 2, 2, 4);

	print_matrix(m_test);
	printf("minor 33 is %.2f\n", minor_33(m_test, 0, 0));
	printf("minor 33 is %.2f\n", minor_33(m_test, 0, 1));
	printf("minor 33 is %.2f\n", minor_33(m_test, 0, 2));
	printf("determinant is %.2f\n", determinant_33(m_test));
	free(m_test);
}

void test_determinant_44(void)
{
	float *m_test;

	m_test = create_matrix(4, 4);
	matrix_fill(m_test, 0, 0, -2);
	matrix_fill(m_test, 0, 1, -8);
	matrix_fill(m_test, 0, 2, 3);
	matrix_fill(m_test, 0, 3, 5);

	matrix_fill(m_test, 1, 0, -3);
	matrix_fill(m_test, 1, 1, 1);
	matrix_fill(m_test, 1, 2, 7);
	matrix_fill(m_test, 1, 3, 3);	

	matrix_fill(m_test, 2, 0, 1);
	matrix_fill(m_test, 2, 1, 2);
	matrix_fill(m_test, 2, 2, -9);
	matrix_fill(m_test, 2, 3, 6);

	matrix_fill(m_test, 3, 0, -6);
	matrix_fill(m_test, 3, 1, 7);
	matrix_fill(m_test, 3, 2, 7);
	matrix_fill(m_test, 3, 3, -9);	

	print_matrix(m_test);
	printf("minor 44 is %.2f\n", minor_44(m_test, 0, 0));
	printf("minor 44 is %.2f\n", minor_44(m_test, 0, 1));
	printf("minor 44 is %.2f\n", minor_44(m_test, 0, 2));
	printf("minor 44 is %.2f\n", minor_44(m_test, 0, 3));
	printf("determinant is %.2f\n", determinant_44(m_test));
	free(m_test);
}

void test_invert_44(void)
{
	float *m_test;
	float *m_inverted;
	float *m_3;

	m_test = create_matrix(4, 4);
	matrix_fill(m_test, 0, 0, 9);
	matrix_fill(m_test, 0, 1, 3);
	matrix_fill(m_test, 0, 2, 0);
	matrix_fill(m_test, 0, 3, 9);

	matrix_fill(m_test, 1, 0, -5);
	matrix_fill(m_test, 1, 1, -2);
	matrix_fill(m_test, 1, 2, -6);
	matrix_fill(m_test, 1, 3, -3);	

	matrix_fill(m_test, 2, 0, -4);
	matrix_fill(m_test, 2, 1, 9);
	matrix_fill(m_test, 2, 2, 6);
	matrix_fill(m_test, 2, 3, 4);

	matrix_fill(m_test, 3, 0, -7);
	matrix_fill(m_test, 3, 1, 6);
	matrix_fill(m_test, 3, 2, 6);
	matrix_fill(m_test, 3, 3, 2);	

	print_matrix(m_test);
	m_inverted = inverted_matrix_44(m_test);
	print_matrix(m_inverted);
	m_3 = inverted_matrix_44(m_inverted);
	print_matrix(m_3);
//	printf("minor 44 is %.2f\n", minor_44(m_test, 0, 0));
//	printf("minor 44 is %.2f\n", minor_44(m_test, 0, 1));
//	printf("minor 44 is %.2f\n", minor_44(m_test, 0, 2));
//	printf("minor 44 is %.2f\n", minor_44(m_test, 0, 3));
//	printf("determinant is %.2f\n", determinant_44(m_test));
	free(m_test);
	free(m_inverted);
	free(m_3);
}*/

/*
void test_mult_product_inverse(void)
{
	float *m_testA;
	float *m_testB;
	float *m_testC;
	float *m_inverseB;
	float *m_final;

	m_testA = create_matrix(4, 4);
	matrix_fill(m_testA, 0, 0, 3);
	matrix_fill(m_testA, 0, 1, -9);
	matrix_fill(m_testA, 0, 2, 7);
	matrix_fill(m_testA, 0, 3, 3);

	matrix_fill(m_testA, 1, 0, 3);
	matrix_fill(m_testA, 1, 1, -8);
	matrix_fill(m_testA, 1, 2, 2);
	matrix_fill(m_testA, 1, 3, -9);	

	matrix_fill(m_testA, 2, 0, -4);
	matrix_fill(m_testA, 2, 1, 4);
	matrix_fill(m_testA, 2, 2, 4);
	matrix_fill(m_testA, 2, 3, 1);

	matrix_fill(m_testA, 3, 0, -6);
	matrix_fill(m_testA, 3, 1, 5);
	matrix_fill(m_testA, 3, 2, -1);
	matrix_fill(m_testA, 3, 3, 1);	

	print_matrix(m_testA);

	m_testB = create_matrix(4, 4);
	matrix_fill(m_testB, 0, 0, 8);
	matrix_fill(m_testB, 0, 1, 2);
	matrix_fill(m_testB, 0, 2, 2);
	matrix_fill(m_testB, 0, 3, 2);

	matrix_fill(m_testB, 1, 0, 3);
	matrix_fill(m_testB, 1, 1, -1);
	matrix_fill(m_testB, 1, 2, 7);
	matrix_fill(m_testB, 1, 3, 0);	

	matrix_fill(m_testB, 2, 0, 7);
	matrix_fill(m_testB, 2, 1, 0);
	matrix_fill(m_testB, 2, 2, 5);
	matrix_fill(m_testB, 2, 3, 4);

	matrix_fill(m_testB, 3, 0, 6);
	matrix_fill(m_testB, 3, 1, -2);
	matrix_fill(m_testB, 3, 2, 0);
	matrix_fill(m_testB, 3, 3, 5);	

	print_matrix(m_testB);
	m_testC = matrix_multiplication_44(m_testA , m_testB);
	m_inverseB = inverted_matrix_44(m_testB);
	m_final = matrix_multiplication_44(m_testC, m_inverseB);
	print_matrix(m_final);

	m_testA = create_indentity_matrix_44();
	m_testB = inverted_matrix_44(m_testA);
	print_matrix(m_testB);
}*/
