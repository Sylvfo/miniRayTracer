/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:54:35 by sforster          #+#    #+#             */
/*   Updated: 2025/05/08 15:27:13 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	check_matrix_44_coord(float *m_a, t_coord *p_v_1)
{
	if (!m_a)
	{
		printf("Matrix is missing S\n");
		return (false);
	}
	if (m_a[0] != 4 || m_a[1] != 4)
	{
		printf("Matrix not 4x4 in multiplication\n");
		return (false);
	}
	if (!p_v_1)
	{
		printf("vect or point is missing\n");
		return (false);
	}
	return (true);
}

void	matrix_from_coord(t_coord *p_v_1, float coord[4])
{
	coord[0] = p_v_1->x;
	coord[1] = p_v_1->y;
	coord[2] = p_v_1->z;
	coord[3] = p_v_1->t;
}
