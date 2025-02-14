/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:39:42 by sforster          #+#    #+#             */
/*   Updated: 2025/02/14 14:54:08 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//	row = m_matrix[0];
//	col = m_matrix[1];

float *create_matrix2(unsigned int row, unsigned int col) 
{
	float	*m_matrix;
	int	i;

	m_matrix = NULL;
	m_matrix = malloc((row * col + 2) * sizeof(float));
	if (!m_matrix)
	{
		printf("problem allocation memory matrix\n");
		return (NULL);
	}
	m_matrix[0] = (float)row;
	m_matrix[1] = (float)col;
	init_matrix_zero2(m_matrix);
	return (m_matrix);
}

void	init_matrix_zero2(float *m_matrix)
{
	int i;

	i = ((int)(m_matrix[0] * m_matrix[1]) + 1);
	while(i > 1)
	{
		m_matrix[i] = 0.0;
		i--;
	}
}

void print_matrix2(float *m_matrix)
{
	int i;
	int k;

	i = 2;
	k = (int)m_matrix[0] + 2;

	printf(GREEN4 "Matrix %.0f - %.0f\n" RESET , m_matrix[0], m_matrix[1]);

	while(i < ((m_matrix[0] * m_matrix[1]) + 2))
	{
		printf(GREEN2 "||" RESET);
		while(i < k)
		{
			printf(GREEN1 " %.2f |" RESET, m_matrix[i]);
			i++;
		}
		printf(GREEN3 "|\n" RESET);
		k += (int)m_matrix[0];
	}
}

void matrix_fill2(float *m_matrix, int row, int col, float number)
{
	int i;

	if (!m_matrix)
	{
		printf("No matrix in fill");
		return ;
	}
	if (row < 0 || row > ((int)m_matrix[0] -1) || col < 0 || col > ((int)m_matrix[1] - 1))
	{
		printf("Wrong row / column\n");
		return ;
	}
	i = row * (int)m_matrix[1] + col + 2;

	m_matrix[i] = number;
}
