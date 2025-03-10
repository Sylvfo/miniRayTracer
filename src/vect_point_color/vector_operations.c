/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:43:15 by sforster          #+#    #+#             */
/*   Updated: 2025/03/10 11:43:20 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// division mieux vaut multiplier par 0.5
// racine carree rapide. A voir entre precision et temps. 

/**
 * @brief to know the opposit of a vector
 * 
 * @param v_1 a vector
 * 
 * @return new vector
 */
t_coord	*negat(t_coord *v_1)
{
	t_coord	*v_new;

	if (is_vector(v_1) == false)
		return (NULL);
	v_new = malloc(sizeof(t_coord));
	v_new->x = -v_new->x;
	v_new->y = -v_new->y;
	v_new->z = -v_new->z;
	v_new->t = v_new->t;
	return (v_new);
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

	if (is_vector(v_1) == false || is_vector(v_2) == false)// a enlever
		return (0);
	dot = (v_1->x * v_2->x) + (v_1->y * v_2->y) + (v_1->z * v_2->z);
	return (dot);
}

/**
 * @brief cross product
 * 
 * You get a new vector that is perpendicular to both of the original vectors.
 * order is important
 * 
 * @param v_1 a vector
 * @param v_2 an other vector
 * 
 * @return new vector
 */
t_coord	*cross_product(t_coord *v_1, t_coord *v_2)
{
	t_coord	*v_new;

	v_new = malloc(sizeof(t_coord));
	if (!v_new)
		return (NULL);
	if (is_vector(v_1) == false || is_vector(v_2) == false)
		return (0);
	v_new->x = (v_1->y * v_2->z) - (v_1->z * v_2->y);
	v_new->y = (v_1->z * v_2->x) - (v_1->x * v_2->z);
	v_new->z = (v_1->x * v_2->y) - (v_1->y * v_2->x);
	return (v_new);
}
