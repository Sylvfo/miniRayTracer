/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:51:07 by sforster          #+#    #+#             */
/*   Updated: 2025/02/17 16:49:50 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

//Docstring

//	row = m_matrix[0];
//	col = m_matrix[1];
int	main(void)
{
	t_pix ***pix;
	
	pix = init_data_test();
	pix_drawings(pix);
	pix_to_window(pix);
	image_hooks(pix[0][0]->ima);
/*	float *m_identity;
d
	m_identity = create_indentity_matrix_44();
	print_matrix(m_identity);
	test_multiplication3();
	transposing_matrix_44(m_identity);
	print_matrix(m_identity);
	free(m_identity);
*/
/*	test_inverting();
	test_submatrix();
	test_minor_33();
	test_determinant_33();
	test_determinant_44();
	test_invert_44();*/
//	test_mult_product_inverse();
	return (0);
}
