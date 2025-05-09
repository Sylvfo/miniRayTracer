/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AA_new_inv_syl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:54:40 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 16:37:11 by syl              ###   ########.fr       */
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

void	new_inverse_matrix_44(float *m_inverted, float *m_matrix)
{
	float	determinant;
	float	minor_matrix[18];
	float	m_transpose[18];
	int		i;

	init_stack_matrix_44(minor_matrix);
	init_stack_matrix_44(m_transpose);
	i = 2;
	determinant = 0;
	new_minor_44(minor_matrix, m_matrix);
	determinant = new_determinant_44(m_matrix, minor_matrix);
	if (determinant == 0)
	{
		printf("matrix not invertible \n");
		return ;
	}
	transpose_matrix_NA(m_transpose, minor_matrix);
	while (i < 18)
	{
		m_inverted[i] = m_transpose[i] / determinant;
		i++;
	}
}

void init_stack_matrix_44(float *m_matrix)
{
	int i;
	
	i = 2;
	m_matrix[0] = 4;
	m_matrix[1] = 4;
	while(i < 18)
	{
		m_matrix[i] = 0;
		i++;
	}
}

void init_stack_matrix_33(float *m_matrix)
{
	int i;
	
	i = 2;
	m_matrix[0] = 3;
	m_matrix[1] = 3;
	while(i < 11)
	{
		m_matrix[i] = 0;
		i++;
	}
}

float	new_determinant_44(float *m_matrix, float *m_minor)
{
	float	determinant;
	int i;
	int sign;

	sign = 1;
	determinant = 0;
	i = 2;
	while (i < 6)
	{
		determinant += sign * m_matrix[i] * m_minor[i];
		sign = -sign;
		i++;
	}
	return (determinant);
}

void	new_minor_44(float *m_minor, float *m_matrix)
{
	float	submatrix_33[11];
	int i;
	int a;
	int b;
	int sign;

	init_stack_matrix_33(submatrix_33);
	i = 2;
	a = 0;
	b = 0;
	sign = 1;
	while (i < 18)
	{
		new_submatrix_33(submatrix_33, m_matrix, b, a);
		if ((a + b) % 2 == 0)
			sign = -1;
		m_minor[i] = sign * new_minor_33(submatrix_33);
		a++;
		if (a > 3)
		{
			a = 0;
			b++;
		}
		sign = 1;
		i++;
	}
}

float new_minor_33(float *m)
{
	float determinant;

	determinant = m[2] * (m[6] * m[10] - m[7] * m[9])  - m[3] * (m[5] * m[10] - m[7] * m[8]) + m[4] * (m[5] * m[9] - m[6] * m[8]);
	return (determinant);
}

void	new_submatrix_33(float *m_submatrix, float *m_matrix, int row_to_rm, int col_to_rm)
{
	int		i;
	int		j;
	int		m_size;

	if (!check_submatrix(m_matrix, row_to_rm, col_to_rm))
		return ;
	i = 2;
	j = 2;
	m_size = (m_matrix[0] * m_matrix[1]) + 2;
	while (i < m_size)
	{
		if (get_curr_row(i, m_matrix[1]) != row_to_rm
			&& get_curr_col(i, m_matrix[1]) != col_to_rm)
		{
			m_submatrix[j] = m_matrix[i];
			j++;
		}
		i++;
	}
}

int	get_curr_row(int i, float width)
{
	return ((i - 2) / (int)width);
}

int	get_curr_col(int i, float width)
{
	return ((i - 2) % (int)width);
}

int	check_submatrix(float *m_matrix, int row_rm, int col_rm)
{
	if (!m_matrix || row_rm < 0 || col_rm < 0)
		return (0);
	if (row_rm >= m_matrix[0] || col_rm >= m_matrix[1])
		return (0);
	return (1);
}

float	cofactors(int row, int col)
{
	float	cofactor;

	cofactor = 1;
	if ((row + col) % 2 != 0)
		cofactor = -1;
	return (cofactor);
}
