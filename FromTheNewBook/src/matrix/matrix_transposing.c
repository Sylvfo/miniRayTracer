/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transposing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:27:31 by syl               #+#    #+#             */
/*   Updated: 2025/02/16 13:04:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


//cool!
void	transposing_matrix_44(float *m_matrix)
{
	float m_tmp[18];
	int i;
	int j;

	check_matrix_44(m_matrix);
	copy_matrix_44_stack(m_matrix, m_tmp);
	i = 2;
	j = 2;
	while(i < 18)
	{
		m_matrix[i] = m_tmp[j];
		if (j > 13)
			j -= 11;
		else
			j += 4;
		i++;
	}
}

void	copy_matrix_44_stack(float *m_matrix, float *m_tmp)
{
	int i;

	i = 0;
	while(i < 18)
	{
		m_tmp[i] = m_matrix[i];
		i++;
	}
}