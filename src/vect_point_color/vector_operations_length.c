/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_length.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:36:44 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 17:16:48 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	scalar_mult_NA(t_coord *result, t_coord *v_1, float scale)
{
	if (is_vector(v_1) == false)
		return ;
	result->x = scale * v_1->x;
	result->y = scale * v_1->y;
	result->z = scale * v_1->z;
	result->t = 0;
}

/**
 * @brief find the norm of a vector
 * 
 * the norm the lenght of a vector or its magnitude
 * A REVERIFIER
 * 
 * @param v_1 a vector
 * 
 * @return the norm of the vector 
 */
float	length_vector(t_coord *v_1)
{
	float	length;

	if (is_vector(v_1) == false)
	{
		printf("not a vector in lenght vector");
		return (0);
	}
	length = (float)sqrtf((v_1->x * v_1->x) + (v_1->y * v_1->y) + (v_1->z * v_1->z));
	return (length);
}

void	normalize_vector_NA(t_coord *v_1)
{
	double	length;

	if (is_vector(v_1) == false)
	{
		printf("Error: Input is not a valid vector. in NA\n");
		return ;
	}
	length = length_vector(v_1);
	if (length == 0)
	{
		printf("Error: Cannot normalize a zero-length vector.\n");
		return ;
	}
	length = 1 / length;
	v_1->x = v_1->x * length;
	v_1->y = v_1->y * length;
	v_1->z = v_1->z * length;
	v_1->t = 0;
}

