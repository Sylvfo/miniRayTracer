/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_length.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:36:44 by syl               #+#    #+#             */
/*   Updated: 2025/02/17 09:30:47 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// check size scale...not neg, not too big...
/**
 * @brief to scale vector 
 * 
 * 0.5 to make it half
 * 
 * @param v_1 a vector
 * @param scale
 * 
 * @return new vector
 */
t_coord	*scalar_mult(t_coord *v_1, float scale)
{
	t_coord	*v_new;

	if (is_vector(v_1) == false)
		return (NULL);
	v_new = malloc(sizeof(t_coord));
	if (!v_new)
		return (NULL);
	v_new->x = scale * v_1->x;
	v_new->y = scale * v_1->y;
	v_new->y = scale * v_1->z;
	v_new->t = 0;
	return (v_new);
}

/**
 * @brief find the norm of a vector
 * 
 * the norm the lenght of a vector or its magnitude
 * 
 * @param v_1 a vector
 * 
 * @return the norm of the vector 
 */
float	length_vector(t_coord *v_1)
{
	float	length;

	if (is_vector(v_1) == false)
		return (0);
//	WHAAAAAAAAAAAAAAT????
//	length = (float)sqrt((v_1->x * v_1->x) + (v_1->y * v_1->y) + (v_1->z * v_1->z));
	length = 2;
	return (length);
}

/**
 * @brief normalize a vector
 * 
 * @param v_1 a vector
 * 
 * @return unit vector
 */
t_coord	*normalize_vector(t_coord *v_1)
{
	t_coord	*v_new;
	float	length;

	if (is_vector(v_1) == false)
		return (NULL);
	length = length_vector(v_1);
	if (length == 0)
	{
		printf("error in normalization \n");
		return (NULL);
	}
	v_new = malloc(sizeof(t_coord));
	if (!v_new)
		return (NULL);
	// optimiser avec multiplication factor...
	v_new->x = v_1->x / length;
	v_new->y = v_1->y / length;
	v_new->z = v_1->z / length;
	v_new->t = 0;
	return (v_new);
}
