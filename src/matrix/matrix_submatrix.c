/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:45:10 by syl               #+#    #+#             */
/*   Updated: 2025/05/12 14:13:04 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	submatrix_33(float *m_submatrix, float *m_matrix, int row, int col)
{
	int		i;
	int		j;
	int		m_size;

	if (!check_submatrix(m_matrix, row, col))
		return ;
	i = 2;
	j = 2;
	m_size = (m_matrix[0] * m_matrix[1]) + 2;
	while (i < m_size)
	{
		if (get_curr_row(i, m_matrix[1]) != row
			&& get_curr_col(i, m_matrix[1]) != col)
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
