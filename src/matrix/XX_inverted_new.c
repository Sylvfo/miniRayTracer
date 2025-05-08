/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABinverted_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:59:02 by syl               #+#    #+#             */
/*   Updated: 2025/04/27 16:11:17 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
//NA no allocation. a garder a la fin
void inverted_matrix_44_NA(float *m_inverted, float *m_matrix, float *m_submatrix33)
{
//	float	*m_inverted;
	float	determinant;

	if (!m_inverted || !m_matrix)
	{
		printf("no matrix in inverted_matrix_44_NA\n");
		return ;
	}
	determinant = determinant_44(m_matrix);
	if (determinant == 0)
	{
		printf("Not invertible in inverted_matrix_44_NA \n");
		return;
	}
	matrix_cofactors_44(m_matrix, m_inverted);
	transposing_matrix_44(m_inverted);
	determinant = determinant_44(m_matrix);
	matrix_division(m_inverted, determinant);
//	return (m_inverted);
}


void	matrix_cofactors_44_NA(float *m_matrix, float *m_cofactors, float *m_submatrix33)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 2;
	j = 0;
	k = 0;
	l = 6;
	while (i < 18)
	{
		if (i >= l)
		{
			j++;
			k = 0;
			l += 4;
		}
		m_cofactors[i] = minor_44_NA(m_matrix, j, k);
		k++;
		i++;
	}
}

float	determinant_44_NA(float *m_44, float *m_submatrix33)
{
	float	determinant;

	if (check_matrix_44(m_44) == false)
		return (0.0);
	determinant = m_44[2] * minor_44(m_44, 0, 0);
	determinant += m_44[3] * minor_44(m_44, 0, 1);
	determinant += m_44[4] * minor_44(m_44, 0, 2);
	determinant += m_44[5] * minor_44(m_44, 0, 3);
	return (determinant);
}

float	minor_44_NA(float *m_matrix, flaot *m_submatrix33,  int row, int col)
{
//	float	*m_submatrix;
	float	determinant;

	m_submatrix = submatrix(m_matrix, row, col);
	if (!m_submatrix)
		return (0.0);
	determinant = determinant_33(m_submatrix);
	determinant *= cofactors(row, col);
	return (determinant);
}

static float determinant3x3(float *m) {
    return
        m[0] * (m[4] * m[8] - m[5] * m[7]) -
        m[1] * (m[3] * m[8] - m[5] * m[6]) +
        m[2] * (m[3] * m[7] - m[4] * m[6]);
}

float	determinant_33(float *m_33)
{
	float	determinant;

	if (check_matrix_33(m_33) == false)
		return (0.0);
	determinant = m_33[2] * minor_33(m_33, 0, 0);
	determinant += m_33[3] * minor_33(m_33, 0, 1);
	determinant += m_33[4] * minor_33(m_33, 0, 2);
	return (determinant);
}*/