/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BBmatrix_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:55:10 by sforster          #+#    #+#             */
/*   Updated: 2025/04/24 13:44:24 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	matrix_division(float *m_matrix, float div)
{
	int	i;

	if (!m_matrix)
	{
		printf("no matrix\n");
		return ;
	}
	i = 2;
	div = (1 / div);
	while (i < (m_matrix[0] * m_matrix[1]) + 2)
	{
		m_matrix[i] *= div;
		i++;
	}
}
