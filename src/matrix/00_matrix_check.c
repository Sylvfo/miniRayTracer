/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:00:57 by syl               #+#    #+#             */
/*   Updated: 2025/05/12 14:10:14 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	check_matrix_44(float *m_a)
{
	if (!m_a)
	{
		printf("Matrix 44 is missing\n");
		return (false);
	}
	if (m_a[0] != 4 || m_a[1] != 4)
	{
		printf("Matrix not 4x4\n");
		return (false);
	}
	return (true);
}

bool	check_matrix_33(float *m_a)
{
	if (!m_a)
	{
		printf("Matrix 33 is missing\n");
		return (false);
	}
	if (m_a[0] != 3 || m_a[1] != 3)
	{
		printf("Matrix not 3x3\n");
		return (false);
	}
	return (true);
}

bool	check_matrix_22(float *m_a)
{
	if (!m_a)
	{
		printf("Matrix 22 is missing\n");
		return (false);
	}
	if (m_a[0] != 2 || m_a[1] != 2)
	{
		printf("Matrix not 2x2\n");
		return (false);
	}
	return (true);
}

bool	check_matrix_44_44(float *m_a, float *m_b)
{
	if (!m_a || !m_b)
	{
		printf("Matrix 44 and 44 are missing\n");
		return (false);
	}
	if (m_a[0] != 4 || m_a[1] != 4 || m_b[0] != 4 || m_b[1] != 4)
	{
		printf("Matrix not 4x4 in multiplication\n");
		return (false);
	}
	return (true);
}
