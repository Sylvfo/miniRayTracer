/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:19:22 by syl               #+#    #+#             */
/*   Updated: 2025/02/13 15:17:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_matrix_44(float **m_matrix)
{
	int a;

	a = 0;
	while(a < 4)
	{
		free(m_matrix[a]);
		a++;
	}
	free(m_matrix);
}

void	free_matrix_33(float **m_matrix)
{
	int a;

	a = 0;
	while(a < 3)
	{
		free(m_matrix[a]);
		a++;
	}
	free(m_matrix);
}

void	free_matrix_22(float **m_matrix)
{
	int a;

	a = 0;
	while(a < 2)
	{
		free(m_matrix[a]);
		a++;
	}
	free(m_matrix);
}
