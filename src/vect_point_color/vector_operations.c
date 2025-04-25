/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:43:15 by sforster          #+#    #+#             */
/*   Updated: 2025/04/23 14:33:01 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// division mieux vaut multiplier par 0.5
// racine carree rapide. A voir entre precision et temps. 

/**
 * @brief to know the opposit of a vector
 * 
 * @param v a vector
 * 
 * @return new vector
 */
t_coord *negat(t_coord *v)
{
    t_coord *result = malloc(sizeof(t_coord));
    if (!result)
        return NULL;
    result->x = -v->x;
    result->y = -v->y;
    result->z = -v->z;
    result->t = v->t; // conserver le type ou autre information
    return result;
}

void negat_NA(t_coord *result, t_coord *old)
{
    if (!result || !old)
        return ;
    result->x = -old->x;
    result->y = -old->y;
    result->z = -old->z;
    result->t = old->t; // conserver le type ou autre information
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

//	if (is_vector(v_1) == false || is_vector(v_2) == false)// a enlever
//		return (0);
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


void cross_product_NA(t_coord *result, t_coord *v_1, t_coord *v_2)
{
	if (!result)
		return ;
	if (is_vector(v_1) == false || is_vector(v_2) == false)
		return ;
	result->x = (v_1->y * v_2->z) - (v_1->z * v_2->y);
	result->y = (v_1->z * v_2->x) - (v_1->x * v_2->z);
	result->z = (v_1->x * v_2->y) - (v_1->y * v_2->x);
}