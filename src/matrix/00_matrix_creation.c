/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_creation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:39:42 by sforster          #+#    #+#             */
/*   Updated: 2025/05/11 20:44:30 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	*create_matrix(unsigned int row, unsigned int col)
{
	float	*m_matrix;

	m_matrix = malloc((row * col + 2) * sizeof(float));
	if (!m_matrix)
	{
		printf("problem allocation memory matrix\n");
		return (NULL);
	}
	m_matrix[0] = (float)row;
	m_matrix[1] = (float)col;
	init_matrix_zero(m_matrix);
	return (m_matrix);
}

void	init_matrix_zero(float *m_matrix)
{
	int	i;

	i = ((int)(m_matrix[0] * m_matrix[1]) + 1);
	while (i > 1)
	{
		m_matrix[i] = 0.0;
		i--;
	}
}

void	matrix_fill(float *m_matrix, int row, int col, float number)
{
	int	i;

	if (!m_matrix)
	{
		printf("No matrix in fill");
		return ;
	}
	if (row < 0 || row > ((int)m_matrix[0] -1))
	{
		printf("Wrong number of row. \n");
		return ;
	}
	if (col < 0 || col > ((int)m_matrix[1] - 1))
	{
		printf("Wrong number of column\n");
		return ;
	}
	i = row * (int)m_matrix[1] + col + 2;
	m_matrix[i] = number;
}

float	*create_indentity_matrix_44(void)
{
	float	*m_identity;

	m_identity = create_matrix(4, 4);
	matrix_fill(m_identity, 0, 0, 1);
	matrix_fill(m_identity, 1, 1, 1);
	matrix_fill(m_identity, 2, 2, 1);
	matrix_fill(m_identity, 3, 3, 1);
	return (m_identity);
}
