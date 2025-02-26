/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:40:09 by syl               #+#    #+#             */
/*   Updated: 2025/02/26 14:58:33 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float degree_to_radian(float degree)
{
	float radian;

	radian = degree * PIRAD;
	return (radian);
}

bool check_rotation_values(t_coord *p_point, int axe, int dir,  float degree)
{
	if (axe < 0 || axe > 2)
		return (false);
	if (dir != 3 && dir != 4)
		return (false);
	(void) degree;
//	if (degree < -360 || degree > 360)
//		return (false);
	if (is_point(p_point) == false)
		return (false);
	return (true);
}
