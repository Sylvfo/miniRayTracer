/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:03:54 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 17:05:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	print_matrix(float *m_matrix)
{
	int	i;
	int	k;

	i = 2;
	k = (int)m_matrix[0] + 2;
	printf(GREEN4 "Matrix %.0f - %.0f\n" RESET, m_matrix[0], m_matrix[1]);
	while (i < ((m_matrix[0] * m_matrix[1]) + 2))
	{
		printf(GREEN2 "||" RESET);
		while (i < k)
		{
			printf(GREEN1 " %.5f |" RESET, m_matrix[i]);
			i++;
		}
		printf(GREEN3 "|\n" RESET);
		k += (int)m_matrix[0];
	}
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
