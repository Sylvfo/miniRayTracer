/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:45:30 by sforster          #+#    #+#             */
/*   Updated: 2025/03/10 11:47:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/**
 * @brief addition operation
 *
 * add a vector to a point to get a point
 * add 2 vectors to get a new one
 * 
 * @param p_v_1 vector or point
 * @param p_v_2 vector or point
 * 
 * @return new vector
 */
t_coord	*addition(t_coord *p_v_1, t_coord *p_v_2)
{
	t_coord	*p_v_new;

	if (is_point(p_v_1) == true && is_point(p_v_2) == true)
	{
		perror("Try to add two points \n");
		return (NULL);
	}
	p_v_new = malloc(sizeof(t_coord));
	p_v_new->x = p_v_1->x + p_v_2->x;
	p_v_new->y = p_v_1->y + p_v_2->y;
	p_v_new->z = p_v_1->z + p_v_2->z;
	p_v_new->t = p_v_1->t + p_v_2->t;
	return (p_v_new);
}

/**
 * @brief substraction operation
 *
 * substraction of 2 points to get a vector
 * substraction of vectors to represent the change of direction between the 2
 * 
 * @param p_v_1 vector or point
 * @param p_v_2 vector or point
 * 
 * @return new vector
 */
t_coord	*substraction(t_coord *p_v_1, t_coord *p_v_2)
{
	t_coord	*v_new;

	v_new = malloc(sizeof(t_coord));
	v_new->x = p_v_1->x - p_v_2->x;
	v_new->y = p_v_1->y - p_v_2->y;
	v_new->z = p_v_1->z - p_v_2->z;
	v_new->t = p_v_1->t - p_v_2->t;
	return (v_new);
}
