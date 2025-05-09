/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAmatrix_minors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:30:15 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 16:13:27 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
/*
//The minor of an element at row i and column j is the determinant of the sub-
//matrix at (i,j).
// also minor is the determinant of the submatrix
float	minor_44(float *m_matrix, int row, int col)
{
	float	*m_submatrix;
	float	determinant;

	m_submatrix = submatrix(m_matrix, row, col);
	if (!m_submatrix)
		return (0.0);
	determinant = determinant_33(m_submatrix);
	determinant *= cofactors(row, col);
	return (determinant);
}


//The minor of an element at row i and column j is the determinant of the sub-
//matrix at (i,j).
// also minor is the determinant of the submatrix
float	minor_33(float *m_matrix, int row, int col)
{
	float	*m_submatrix;
	float	determinant;

	m_submatrix = submatrix(m_matrix, row, col);
	if (!m_submatrix)
		return (0.0);
	determinant = determinant_22(m_submatrix);
	determinant *= cofactors(row, col);
	return (determinant);
}*/




