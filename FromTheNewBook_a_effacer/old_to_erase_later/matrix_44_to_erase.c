/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_44_to_erase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:34:13 by syl               #+#    #+#             */
/*   Updated: 2025/02/14 11:46:51 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minirt.h"

#define M 3
#define N 4
#define P 3

/*
The first thing to notice is when talking about the individual elements of the
matrix, we specify the element’s row first, and then its column. For example,
element M23 is the one at row 2, column 3. Also note in this book, row and
column indices will be zero-based, so row 2 is actually the third row.
*/

float **create_matrix_44(void) // ahah like 44 Lewis Hamilton
{
	float	**m_matrix;
	int	i;
	int j;

	i = 0;
	m_matrix = malloc(4 *sizeof(float *));
	if (!m_matrix)
	{
		printf("Error allocating matrix\n");
		return (NULL);
	}
	while (i < 4)
	{
		j = 0;
		m_matrix[i] = malloc(4 *sizeof(float));
		if (!m_matrix[i])
		{
			printf("Error allocating matrix\n");
			while(i--)
				free(m_matrix[i]);
			free(m_matrix);
			return (NULL);
		}
		while (j < 4)
		{
			m_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m_matrix);
}

float **create_matrix_33(void)
{
	float	**m_matrix;
	int	i;
	int j;

	i = 0;
	m_matrix = malloc(3 *sizeof(float *));
	if (!m_matrix)
	{
		printf("Error allocating matrix\n");
		return (NULL);
	}
	while (i < 3)
	{
		j = 0;
		m_matrix[i] = malloc(3 *sizeof(float));
		if (!m_matrix[i])
		{
			printf("Error allocating matrix\n");
			while(i--)
				free(m_matrix[i]);
			free(m_matrix);
			return (NULL);
		}
		while (j < 3)
		{
			m_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m_matrix);
}



float **create_matrix_22(void)
{
	float	**m_matrix;
	int	i;
	int j;

	i = 0;
	m_matrix = malloc(2 *sizeof(float *));
	if (!m_matrix)
	{
		printf("Error allocating matrix\n");
		return (NULL);
	}
	while (i < 2)
	{
		j = 0;
		m_matrix[i] = malloc(2 *sizeof(float));
		if (!m_matrix[i])
		{
			printf("Error allocating matrix\n");
			while(i--)
				free(m_matrix[i]);
			free(m_matrix);
			return (NULL);
		}
		while (j < 2)
		{
			m_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m_matrix);
}




