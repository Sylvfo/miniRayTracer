/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAmatrix_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:55:10 by sforster          #+#    #+#             */
/*   Updated: 2025/04/23 18:59:42 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Don’t worry about 2x2 or 3x3 matrices here; your ray tracer won’t
//need to multiply those at all
//Matrix multiplication computes the dot product of every row-column
//combination in the two matrices!

//celui ci pour une nouvelle matrice
void	matrix_multiplication_44_NA2(float *m_result, float *m_a, float *m_b)
{
	int		count;
	float	sum;
	int		row;
	int		col;
	

	if (check_matrix_44(m_result) == false)
	{
		printf("miss in 44 NA\n");
		return;
	}
	if (check_matrix_44_44(m_a, m_b) == false)
	{
		printf("miss in 44 NA 2\n");
		return;
	}
	count = 0;
	while (count < 16)
	{
		row = count / 4;
		col = count % 4;
		sum = 0;
		sum += m_a[2 + row * 4 + 0] * m_b[2 + 0 * 4 + col];
		sum += m_a[2 + row * 4 + 1] * m_b[2 + 1 * 4 + col];
		sum += m_a[2 + row * 4 + 2] * m_b[2 + 2 * 4 + col];
		sum += m_a[2 + row * 4 + 3] * m_b[2 + 3 * 4 + col];
		m_result[2 + count] = sum;
		count++;
	}
	m_result[0] = 4;
	m_result[1] = 4;
}

//celui ci pour une matric ma qui devient m result
void	matrix_multiplication_44_NA(float *m_a, float *m_b, float *m_tmp)
{
	int		count;
	float	sum;
	int		row;
	int		col;
	
	if (check_matrix_44_44(m_a, m_b) == false)
	{
		printf("miss in 44 NA 2\n");
		return;
	}
	if (check_matrix_44(m_tmp) == false)
	{
		printf("miss in 44 NA 3\n");
		return;
	}
	count = 0;
	copy_matrix_44_stack(m_a, m_tmp);
	while (count < 16)
	{
		row = count / 4;
		col = count % 4;
		sum = 0;
		sum += m_a[2 + row * 4 + 0] * m_b[2 + 0 * 4 + col];
		sum += m_a[2 + row * 4 + 1] * m_b[2 + 1 * 4 + col];
		sum += m_a[2 + row * 4 + 2] * m_b[2 + 2 * 4 + col];
		sum += m_a[2 + row * 4 + 3] * m_b[2 + 3 * 4 + col];
		m_tmp[2 + count] = sum;
		count++;
	}
	copy_matrix_44_stack(m_tmp, m_a);
}

void	matrix_division(float *m_matrix, float div)
{
	int	i;

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
