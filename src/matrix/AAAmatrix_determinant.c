/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAmatrix_determinant.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:25:15 by syl               #+#    #+#             */
/*   Updated: 2025/04/27 13:25:16 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	determinant_22(float *m_22)
{
	float	determinant;

	if (check_matrix_22(m_22) == false)
		return (0.0);
	determinant = (m_22[2] * m_22[5]) - (m_22[3] * m_22[4]);
	return (determinant);
}

float	determinant_33(float *m_33)
{
	float	determinant;

	if (check_matrix_33(m_33) == false)
		return (0.0);
	determinant = m_33[2] * minor_33(m_33, 0, 0);
	determinant += m_33[3] * minor_33(m_33, 0, 1);
	determinant += m_33[4] * minor_33(m_33, 0, 2);
	return (determinant);
}


float	determinant_44(float *m_44)
{
	float	determinant;

	if (check_matrix_44(m_44) == false)
		return (0.0);
	determinant = m_44[2] * minor_44(m_44, 0, 0);
	determinant += m_44[3] * minor_44(m_44, 0, 1);
	determinant += m_44[4] * minor_44(m_44, 0, 2);
	determinant += m_44[5] * minor_44(m_44, 0, 3);
	return (determinant);
}
