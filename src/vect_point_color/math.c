/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:37:36 by syl               #+#    #+#             */
/*   Updated: 2025/03/10 16:12:34 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/**
 * @brief sqrt simplified
 * 
 * 	on pourra determiner le niveau de precision plus tard. 
 * 
 * @param x float x 
 * 
 * @return square root of x. -1 in case of error (neg x)
 */
float	simple_sqrt(float x)
{
	float estimation;
	float precision;
	float max_iterations;
	int i;

	if (x < 0)
		return (-1.0);
	if (x == 0 || x == 1)
		return (x);
	estimation = x / 2.0;
	precision = 0.00001;
	max_iterations = 100;
	i = 0;
	// Méthode de Newton
	while (fabs(estimation * estimation - x) > precision && i < max_iterations)
	{
		estimation = 0.5 * (estimation + x / estimation);
		i++;
	}
	return (estimation);
}