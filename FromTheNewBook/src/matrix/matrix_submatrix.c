/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:19:23 by syl               #+#    #+#             */
/*   Updated: 2025/02/17 16:32:55 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// a voir si on peut réduire en enlevant les / et %
//we all live in a yellow submatrix! Yellow submatrix! 
float	*submatrix(float *m_matrix, int row_to_rm, int col_to_rm)
{
	float	*m_submatrix;
	int		i;
	int		j;
	int		m_size;

	if (!check_submatrix(m_matrix, row_to_rm, col_to_rm))
		return (NULL);
	m_submatrix = create_matrix((m_matrix[0]) - 1, (m_matrix[1] - 1));
	if (!m_submatrix)
		return (NULL);
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
	return (m_submatrix);
}

//with submatrix
int	get_curr_row(int i, float width)
{
	return ((i - 2) / (int)width);
}

//with submatrix
int	get_curr_col(int i, float width)
{
	return ((i - 2) % (int)width);
}

//with submatrix
int	check_submatrix(float *m_matrix, int row_rm, int col_rm)
{
	if (!m_matrix || row_rm < 0 || col_rm < 0)
		return (0);
	if (row_rm >= m_matrix[0] || col_rm >= m_matrix[1])
		return (0);
	return (1);
}
