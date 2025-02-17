/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:55:10 by sforster          #+#    #+#             */
/*   Updated: 2025/02/17 14:37:47 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Don’t worry about 2x2 or 3x3 matrices here; your ray tracer won’t
//need to multiply those at all
//Matrix multiplication computes the dot product of every row-column
//combination in the two matrices!

//		row = count / 4;// Détermine la ligne actuelle
//		col = count % 4;// Détermine la colonne actuelle

float	*matrix_multiplication_44(float *m_a, float *m_b)
{
	float	*m_new_matrix;
	int		count;
	float	sum;
	int		row;
	int		col;

	if (check_matrix_44_44(m_a, m_b) == false)
		return (NULL);
	m_new_matrix = create_matrix(4, 4);
	if (m_new_matrix == NULL)
		return (NULL);
	count = 0;
	while (count < 16)
	{
		row = count / 4;
		col = count % 4;
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

void	matrix_division(float *m_matrix, float div)
{
	int i;

	if (!m_matrix)
	{
		printf("no matrix\n");
		return ;
	}
	i = 2;
	div = (1 / div);
	while (i < (m_matrix[0] * m_matrix[1]) + 2)
	{
		m_matrix[i] *= div;
		i++;
	}
}
