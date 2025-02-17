/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:03:54 by syl               #+#    #+#             */
/*   Updated: 2025/02/17 14:35:35 by syl              ###   ########.fr       */
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
