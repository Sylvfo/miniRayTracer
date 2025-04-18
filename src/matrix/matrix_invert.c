/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:18:41 by syl               #+#    #+#             */
/*   Updated: 2025/04/18 15:49:19 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//It’ll be crucial to the transforma-
//tion of shapes in your ray tracer, allowing you to move shapes around, make
//them bigger or smaller, rotate them, and more.
//not every matrix is invertible
//pas testé
bool	is_matrix_invertible(float *m_matrix)
{
	float	determinant;

	if (check_matrix_22(m_matrix) == true)
		determinant = determinant_22(m_matrix);
	else if (check_matrix_33(m_matrix) == true)
		determinant = determinant_33(m_matrix);
	else if (check_matrix_44(m_matrix) == true)
		determinant = determinant_44(m_matrix);
	else
		return (false);
	if (determinant == 0)
		return (false);
	return (true);
}

float	*inverted_matrix_44(float *m_matrix)
{
	float	*m_inverted;
	float	determinant;

	if (check_matrix_44(m_matrix) == false)
		return (NULL);
	if (is_matrix_invertible(m_matrix) == false)
		return (NULL);
	m_inverted = create_matrix(4, 4);
	if (!m_inverted)
		return (NULL);
	matrix_cofactors_44(m_matrix, m_inverted);
	transposing_matrix_44(m_inverted);
	determinant = determinant_44(m_matrix);
	matrix_division(m_inverted, determinant);
	return (m_inverted);
}

void	matrix_cofactors_44(float *m_matrix, float *m_cofactors)
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
		m_cofactors[i] = minor_44(m_matrix, j, k);
		k++;
		i++;
	}
}



//////////////// ca c est fait au début du raytracing pour la matrice de chaque forme
/*
void	inverted_matrix_44_2(float *m_matrix)
{

	float	determinant;

	if (check_matrix_44(m_matrix) == false)
		return (NULL);
	if (is_matrix_invertible(m_matrix) == false)
		return (NULL);
//	m_inverted = create_matrix(4, 4);
//	if (!m_inverted)
//		return (NULL);
	matrix_cofactors_44(m_matrix, m_inverted);
	transposing_matrix_44(m_inverted);
	determinant = determinant_44(m_matrix);
	matrix_division(m_inverted, determinant);
	return (m_inverted);
}*/