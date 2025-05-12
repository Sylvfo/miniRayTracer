/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:54:40 by syl               #+#    #+#             */
/*   Updated: 2025/05/12 14:12:40 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	transposing_matrix_44(float *m_matrix)
{
	float	m_tmp[18];
	int		i;
	int		j;

	copy_matrix_44(m_matrix, m_tmp);
	m_tmp[0] = 4;
	m_tmp[1] = 4;
	i = 2;
	j = 2;
	while (i < 18)
	{
		m_matrix[i] = m_tmp[j];
		if (j > 13)
			j -= 11;
		else
			j += 4;
		i++;
	}
}

void	inverse_matrix_44(float *m_inverted, float *m_matrix)
{
	float	determinant;
	float	minor_matrix[18];
	float	m_transpose[18];
	int		i;

	init_stack_matrix_44(minor_matrix);
	init_stack_matrix_44(m_transpose);
	i = 2;
	determinant = 0;
	minor_44(minor_matrix, m_matrix);
	determinant = determinant_44(m_matrix, minor_matrix);
	if (determinant == 0)
	{
		printf("matrix not invertible \n");
		return ;
	}
	transpose_matrix(m_transpose, minor_matrix);
	while (i < 18)
	{
		m_inverted[i] = m_transpose[i] / determinant;
		i++;
	}
}

void	init_stack_matrix_44(float *m_matrix)
{
	int	i;

	i = 2;
	m_matrix[0] = 4;
	m_matrix[1] = 4;
	while (i < 18)
	{
		m_matrix[i] = 0;
		i++;
	}
}

void	init_stack_matrix_33(float *m_matrix)
{
	int	i;

	i = 2;
	m_matrix[0] = 3;
	m_matrix[1] = 3;
	while (i < 11)
	{
		m_matrix[i] = 0;
		i++;
	}
}

float	cofactors(int row, int col)
{
	float	cofactor;

	cofactor = 1;
	if ((row + col) % 2 != 0)
		cofactor = -1;
	return (cofactor);
}
