/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:51:07 by sforster          #+#    #+#             */
/*   Updated: 2025/02/13 15:32:23 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

//Docstring

int main(void)
{
/*	t_pix ***pix;
	
	pix = init_data_test();
	pix_drawings(pix);
	pix_to_window(pix);
	image_hooks(pix[0][0]->ima);*/

	float **m_test;
	m_test = create_matrix(4, 4);
	matrix_22_fill(m_test, 0, 0, -24);
	matrix_22_fill(m_test, 3, 2, 15);
//	matrix_22_fill(m_test, 0, 1, 4);
	print_matrix(m_test, 4, 4);
//	print_matrix_44(m_test);
	free_matrix_44(m_test);
//	terminate()
	return (0);
}