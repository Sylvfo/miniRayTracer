/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAmatrix_submatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:19:23 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 16:12:55 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
// a voir si on peut réduire en enlevant les / et %
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
}*/



