/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:43:15 by sforster          #+#    #+#             */
/*   Updated: 2025/05/07 17:11:22 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	cross_product_NA(t_coord *result, t_coord *v_1, t_coord *v_2)
{
	if (!result)
		return ;
	if (is_vector(v_1) == false || is_vector(v_2) == false)
		return ;
	result->x = (v_1->y * v_2->z) - (v_1->z * v_2->y);
	result->y = (v_1->z * v_2->x) - (v_1->x * v_2->z);
	result->z = (v_1->x * v_2->y) - (v_1->y * v_2->x);
}

void	negat_NA(t_coord *result, t_coord *old)
{
	if (!result || !old)
		return ;
	result->x = -old->x;
	result->y = -old->y;
	result->z = -old->z;
	result->t = old->t;
}

/**
 * @brief dot product
 * 
 * avec les angles et les cosin...
 * 
 * @param v_1 a vector
 * @param v_2 an other vector
 * 
 * @return dot product
 */
float	dot_product(t_coord *v_1, t_coord *v_2)
{
	float	dot;

	dot = (v_1->x * v_2->x) + (v_1->y * v_2->y) + (v_1->z * v_2->z);
	return (dot);
}
