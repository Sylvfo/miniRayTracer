/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:54:35 by sforster          #+#    #+#             */
/*   Updated: 2025/05/12 17:54:36 by syl              ###   ########.fr       */
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

void	print_matrix_44(float *m)
{
	int	i;

	i = 0;
	printf("%.2f - ", m[0]);
	printf("%.2f \n", m[1]);
	printf("%.2f - ", m[2]);
	printf("%.2f - ", m[3]);
	printf("%.2f - ", m[4]);
	printf("%.2f \n", m[5]);
	printf("%.2f - ", m[6]);
	printf("%.2f - ", m[7]);
	printf("%.2f - ", m[8]);
	printf("%.2f \n", m[9]);
	printf("%.2f - ", m[10]);
	printf("%.2f - ", m[11]);
	printf("%.2f - ", m[12]);
	printf("%.2f \n", m[13]);
	printf("%.2f - ", m[14]);
	printf("%.2f - ", m[15]);
	printf("%.2f - ", m[16]);
	printf("%.2f \n", m[17]);
}