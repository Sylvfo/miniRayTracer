/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_transposing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:27:31 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 17:09:39 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	transpose_matrix(float *result, float *m)
{
	int	i;
	int	j;

	if (!m || m[0] != 4 || m[1] != 4)
	{
		printf("problème\n");
		return ;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix_fill(result, i, j, m[2 + j * 4 + i]);
			j++;
		}
		i++;
	}
}

void	copy_matrix_44(float *m_result, float *m_matrix)
{
	int	i;

	if (!m_matrix || !m_result)
	{
		printf("no matrix in copy matrix 44\n");
		return ;
	}
	i = 0;
	while (i < 18)
	{
		m_result[i] = m_matrix[i];
		i++;
	}
}
