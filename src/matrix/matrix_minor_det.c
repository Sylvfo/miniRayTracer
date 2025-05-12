/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor_det.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:49:56 by syl               #+#    #+#             */
/*   Updated: 2025/05/12 14:12:50 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	determinant_44(float *m_matrix, float *m_minor)
{
	float	determinant;
	int		i;
	int		sign;

	sign = 1;
	determinant = 0;
	i = 2;
	while (i < 6)
	{
		determinant += sign * m_matrix[i] * m_minor[i];
		sign = -sign;
		i++;
	}
	return (determinant);
}

void	minor_44(float *m_minor, float *m_matrix)
{
	float	m_submatrix_33[11];
	int		i;
	int		a;
	int		b;
	int		sign;

	init_stack_matrix_33(m_submatrix_33);
	i = 2;
	a = 0;
	b = 0;
	while (i < 18)
	{
		sign = 1;
		submatrix_33(m_submatrix_33, m_matrix, b, a);
		if ((a + b) % 2 == 0)
			sign = -1;
		m_minor[i] = sign * minor_33(m_submatrix_33);
		a++;
		if (a > 3)
		{
			a = 0;
			b++;
		}
		i++;
	}
}

float	minor_33(float *m)
{
	float	determinant;

	determinant = m[2] * (m[6] * m[10] - m[7] * m[9])
		- m[3] * (m[5] * m[10] - m[7] * m[8])
		+ m[4] * (m[5] * m[9] - m[6] * m[8]);
	return (determinant);
}
