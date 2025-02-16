/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:25:15 by syl               #+#    #+#             */
/*   Updated: 2025/02/16 13:49:03 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float determinant_22(float *m_22)
{
//	check_matrix_22
	float determinant;

	determinant = (m_22[2] * m_22[5]) - (m_22[3] * m_22[4]);
	return (determinant);
}

//we all live in a yellow submatrix! Yellow submatrix! 
/*
float *submatrix(float *m_matrix, int row_to_remove, int col_to_remove)
{
	float *m_submatrix;

	m_submatrix( )
}*/
