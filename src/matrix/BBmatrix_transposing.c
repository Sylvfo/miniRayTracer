/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BBmatrix_transposing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:27:31 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 10:48:40 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// celle de corentin
// À ajouter dans votre bibliothèque de matrices
float *transpose_matrix(float *m)
{
	float *result;
	int i;
	int j;
	
	if (!m || m[0] != 4 || m[1] != 4)
		return (NULL);
	
	result = create_matrix(4, 4);
	if (!result)
		return (NULL);
	
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
	return (result);
}

void transpose_matrix_NA(float *result, float *m)
{
	int i;
	int j;
	
	if (!m || m[0] != 4 || m[1] != 4)
	{
		printf("problème\n");
		return;
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

//celle de syl
void	transposing_matrix_44(float *m_matrix)
{
	float	m_tmp[18];
	int		i;
	int		j;

	check_matrix_44(m_matrix);
	copy_matrix_44_stack(m_matrix, m_tmp);
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
//heap
void	copy_matrix_44_stack(float *m_matrix, float *m_tmp)
{
	int	i;

	i = 0;
	while (i < 18)
	{
		m_tmp[i] = m_matrix[i];
		i++;
	}
}

void	copy_matrix_44(float *m_result, float *m_matrix)
{
	int	i;

	if (!m_matrix || !m_result)
	{
		printf("no matrix in copy matrix 44\n");
		return;
	}
	i = 0;
	while (i < 18)
	{
		m_result[i] = m_matrix[i];
		i++;
	}
}