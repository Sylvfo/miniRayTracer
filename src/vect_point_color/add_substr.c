/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:45:30 by sforster          #+#    #+#             */
/*   Updated: 2025/05/12 14:13:39 by syl              ###   ########.fr       */
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
void	addition_NA(t_coord *result, t_coord *p_v_1, t_coord *p_v_2)
{
	result->x = p_v_1->x + p_v_2->x;
	result->y = p_v_1->y + p_v_2->y;
	result->z = p_v_1->z + p_v_2->z;
	result->t = 1;
}

/**
 * @brief substraction operation
 *
 * substraction of 2 points to get a vector
 * substraction of vectors to represent the change of direction between the 2
 * p_v_1 - p_v_2
 * 
 * @param p_v_1 vector or point
 * @param p_v_2 vector or point
 * 
 * @return new vector
 */
void	substraction_p_to_v_NA(t_coord *v_result, t_coord *p_v_1, t_coord *p_v_2)
{
	if (!p_v_1 || !p_v_2 || !v_result)
	{
		printf("Error: NULL parameter passed to substraction\n");
		return ;
	}
	v_result->x = p_v_1->x - p_v_2->x;
	v_result->y = p_v_1->y - p_v_2->y;
	v_result->z = p_v_1->z - p_v_2->z;
	v_result->t = 0;
}
