/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:36:21 by syl               #+#    #+#             */
/*   Updated: 2025/02/07 21:34:29 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/**
 * @brief print a vector
 *
 * if v_vector is not a vector, print an error message and return
 * 
 * @param x t_coord *v_vector
 *                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
 * @return no return value
 */
void print_vector(t_coord *v_vector)
{
	if (is_vector(v_vector) == false)
		return ;
	printf("vector : x %.2f, y %.2f, z %.2f\n", v_vector->x, v_vector->y, v_vector->z);
}

/**
 * @brief print a point
 *
 * if p_point is not a point, print an error message and return
 * 
 * @param x t_coord *p_point
 *                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
 * @return no return value
 */
void print_point(t_coord *p_point)
{
	if (is_point(p_point) == false)
		return ;
	printf("point : x %.2f, y %.2f, z %.2f\n", p_point->x, p_point->y, p_point->z);
}

