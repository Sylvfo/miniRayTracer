/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:43:10 by syl               #+#    #+#             */
/*   Updated: 2025/02/13 15:32:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float **create_matrix(unsigned int row, unsigned int col) 
{
	float	**m_matrix;
	int	i;

//	size max...
	i = 0;
	m_matrix = malloc((row) * sizeof(float *));
	if (!m_matrix)
	{
		error_alloc_matrix(0, m_matrix);
		return (NULL);
	}
	while (i < (row))
	{
		m_matrix[i] = malloc((col) *sizeof(float));
		if (!m_matrix[i])
		{
			error_alloc_matrix(i, m_matrix);
			return (NULL);
		}
		i++;
	}
	init_matrix_zero(m_matrix, row, col);
	return (m_matrix);
}

void error_alloc_matrix(int i, float **m_matrix)
{
	if (i == 0)
		printf("Error allocating matrix\n");
	else
	{
		printf("Error allocating matrix\n");
		while(i--)
			free(m_matrix[i]);
		free(m_matrix);
		return ;
	}
}

void	init_matrix_zero(float **m_matrix, unsigned int row, unsigned int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < row)
	{
		j = 0;
		while(j < col)
		{
			m_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

