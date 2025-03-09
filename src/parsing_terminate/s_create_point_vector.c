/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_create_point_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:37:18 by sforster          #+#    #+#             */
/*   Updated: 2025/03/09 12:23:20 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/**
 * @brief create a new point with allocated memory
 *
 * @param x float coordinate x
 * @param y float coordinate y
 * @param z float coordinate z
 * 
 * @return pointer on new point
 */
t_coord	*create_point(float x, float y, float z)
{
	t_coord	*p_point;

	p_point = malloc(sizeof(t_coord));
	if (!p_point)
	{
		perror("Error allocating point\n");
		return (NULL);
	}
	p_point->x = x;
	p_point->y = y;
	p_point->z = z;
	p_point->t = 1.0;
	return (p_point);
}

/**
 * @brief create a new vector with allocated memory
 *
 * @param x float coordinate x
 * @param y float coordinate y
 * @param z float coordinate z
 *
 * @return pointer on new vector
 */
t_coord	*create_vector(float x, float y, float z)
{
	t_coord	*v_vector;

	v_vector = malloc(sizeof(t_coord));
	if (!v_vector)
	{
		perror("Error allocating vector\n");
		return (NULL);
	}
	v_vector->x = x;
	v_vector->y = y;
	v_vector->z = z;
	v_vector->t = 0;
	return (v_vector);
}
