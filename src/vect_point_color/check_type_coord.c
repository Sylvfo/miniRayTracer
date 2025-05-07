/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_coord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:07:58 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 17:21:32 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/**
 * @brief check if a t_coord is a vector
 *
 * @param t_coord *v_vector
 * 
 * @return true/false
 */
bool	is_vector(t_coord *v_vector)
{
	if (v_vector->t != 0)
	{
		printf("Not a vector\n");// il faudra effacer
		return (false);
	}
	return (true);
}

/**
 * @brief check if a t_coord is a point
 *
 * @param t_coord *p_point
 * 
 * @return true/false
 */
bool	is_point(t_coord *p_point)
{
	if (p_point->t != 1.0)
	{
	//	printf("Not a point\n");// il faudra effacer ça
		return (false);
	}
	return (true);
}
