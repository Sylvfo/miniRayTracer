/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_comparison.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:18:41 by syl               #+#    #+#             */
/*   Updated: 2025/02/13 15:32:35 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//how to itarate without double while...

bool	matrix_comparision(float **m_a, float **m_b, int msize)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i > msize)
	{
		j = 0;
		while(j > msize)
		{
			if (fabs(m_a[i][j] - m_b[i][j]) > EPSILON)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}