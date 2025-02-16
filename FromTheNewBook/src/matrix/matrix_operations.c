/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:55:10 by sforster          #+#    #+#             */
/*   Updated: 2025/02/16 13:25:23 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Don’t worry about 2x2 or 3x3 matrices here; your ray tracer won’t
//need to multiply those at all
//Matrix multiplication computes the dot product of every row-column
//combination in the two matrices!

float	*matrix_multiplication_44(float *m_a, float *m_b)
{
	float	*m_new_matrix;
	int		count;
	float	sum;
	int		row;
	int		col;

	if (check_matrix_44_44(m_a, m_b) == false)
		return (NULL);
	m_new_matrix = create_matrix2(4, 4);
	if (m_new_matrix == NULL)
		return (NULL);
	count = 0;
	while (count < 16)
	{
		row = count / 4;// Détermine la ligne actuelle
		col = count % 4;// Détermine la colonne actuelle
		sum = 0;
		sum += m_a[2 + row * 4] * m_b[2 + col];
		sum += m_a[2 + row * 4 + 1] * m_b[2 + 4 + col];
		sum += m_a[2 + row * 4 + 2] * m_b[2 + 8 + col];
		sum += m_a[2 + row * 4 + 3] * m_b[2 + 12 + col];
		m_new_matrix[2 + count] = sum;
		count++;
	}
	return (m_new_matrix);
}

bool	check_matrix_44_44(float *m_a, float *m_b)
{
	if (!m_a || !m_b)
	{
		printf("Matrix is missing\n");
		return (false);		
	}
	if (m_a[0] != 4 || m_a[1] != 4 || m_b[0] != 4 || m_b[1] != 4)
	{
		printf("Matrix not 4x4 in multiplication\n");
		return (false);
	}
	return (true);
}
