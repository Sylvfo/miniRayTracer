/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_fill_44_33_22.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:12:54 by syl               #+#    #+#             */
/*   Updated: 2025/02/13 15:32:26 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


void matrix_44_fill(float **m_matrix, int row, int column, float number)
{
	if (!m_matrix)
	{
		printf("No matrix in fill");
		return ;
	}
	if (row < 0 || row > 3 || column < 0 || column > 3)
	{
		printf("Wrong row / column\n");
		return ;
	}
	m_matrix[row][column] = number;
}

void matrix_33_fill(float **m_matrix, int row, int column, float number)
{
	if (!m_matrix)
	{
		printf("No matrix in fill");
		return ;
	}
	if (row < 0 || row > 2 || column < 0 || column > 2)
	{
		printf("Wrong row / column\n");
		return ;
	}
	m_matrix[row][column] = number;
}

void matrix_22_fill(float **m_matrix, int row, int column, float number)
{
	if (!m_matrix)
	{
		printf("No matrix in fill");
		return ;
	}
	if (row < 0 || row > 1 || column < 0 || column > 1)
	{
		printf("Wrong row / column\n");
		return ;
	}
	m_matrix[row][column] = number;
}
