/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:15:24 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 15:16:00 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float *m_test = create_matrix(4,4);
float *m_inv = create_matrix(4,4);
print_matrix(m_test);

matrix_fill(m_test, 0, 0, -5);
matrix_fill(m_test, 0, 1, 2);
matrix_fill(m_test, 0, 2, 6);
matrix_fill(m_test, 0, 3, -8);

matrix_fill(m_test, 1, 0, 1);
matrix_fill(m_test, 1, 1, -5);
matrix_fill(m_test, 1, 2, 1);
matrix_fill(m_test, 1, 3, 8);

matrix_fill(m_test, 2, 0, 7);
matrix_fill(m_test, 2, 1, 7);
matrix_fill(m_test, 2, 2, -6);
matrix_fill(m_test, 2, 3, -7);

matrix_fill(m_test, 3, 0, 1);
matrix_fill(m_test, 3, 1, -3);
matrix_fill(m_test, 3, 2, 7);
matrix_fill(m_test, 3, 3, 4);

print_matrix(m_test);
new_inverse_matrix_44(m_inv, m_test);
//	print_matrix_44(m_inv);
print_matrix(m_inv);


////////////////////////////////////////	
/*	float *m_test = create_matrix(4,4);
float *m_inv = create_matrix(4,4);
print_matrix(m_test);

matrix_fill(m_test, 0, 0, 8);
matrix_fill(m_test, 0, 1, -5);
matrix_fill(m_test, 0, 2, 9);
matrix_fill(m_test, 0, 3, 2);

matrix_fill(m_test, 1, 0, 7);
matrix_fill(m_test, 1, 1, 5);
matrix_fill(m_test, 1, 2, 6);
matrix_fill(m_test, 1, 3, 1);

matrix_fill(m_test, 2, 0, -6);
matrix_fill(m_test, 2, 1, 0);
matrix_fill(m_test, 2, 2, 9);
matrix_fill(m_test, 2, 3, 6);

matrix_fill(m_test, 3, 0, -3);
matrix_fill(m_test, 3, 1, 0);
matrix_fill(m_test, 3, 2, -9);
matrix_fill(m_test, 3, 3, -4);

print_matrix(m_test);
new_inverse_matrix_44(m_inv, m_test);
//	print_matrix_44(m_inv);
print_matrix(m_inv);
exit(0);*/

/*	float *m_test = create_matrix(4,4);
	print_matrix(m_test);
	matrix_fill(m_test, 0, 1, 1);
	matrix_fill(m_test, 0, 2, 2);
	matrix_fill(m_test, 0, 3, 3);
	matrix_fill(m_test, 1, 0, 4);
	print_matrix_44(m_test);
	float *test_id = create_indentity_matrix_44();
	print_matrix_44(test_id);
	float *test_scale = create_matrix(4, 4);
	create_scaling_matrix_NA(test_scale, 22, 23, 24);
	print_matrix_44(test_scale);
	float *test_transl = create_matrix(4, 4);
	fill_translation_matrix(test_transl, 72,73,74);
	print_matrix_44(test_transl);
	float *test_rot = create_matrix(4, 4);
	fill_translation_matrix(test_rot, 20);
	print_matrix_44(test_rot);
	exit(0);*/
////////////////////////////////////////