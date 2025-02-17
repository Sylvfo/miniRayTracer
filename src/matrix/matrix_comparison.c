/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_comparison.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:18:41 by syl               #+#    #+#             */
/*   Updated: 2025/02/17 08:59:46 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//plus ou moins verifie
bool	matrix_comparision(float *m_a, float *m_b)
{
	int	i;

	if (m_a[0] != m_b[0] || m_a[1] != m_b[1])
	{
		printf("Comparision between matrix not the same size");
		return (false);
	}
	i = 2;
	while (i < (int)((m_a[0] * m_a[1]) + 2))
	{
		if (fabs(m_a[i] - m_b[i]) > EPSILON)
		{
			return (false);
		}
		i++;
	}
	return (true);
}
