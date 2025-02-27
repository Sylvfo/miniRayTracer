/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:40:09 by syl               #+#    #+#             */
/*   Updated: 2025/02/27 10:36:54 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	degree_to_radian(float degree)
{
	float	radian;

	radian = degree * PIRAD;
	return (radian);
}

bool	check_rotation_values(t_coord *p_point, int axe, int dir, float radian)
{
	if (axe < 0 || axe > 2)
		return (false);
	if (dir != 3 && dir != 4)
		return (false);
	if (radian < (-2 * M_PI) || radian > (2 * M_PI))
		return (false);
	if (is_point(p_point) == false)
		return (false);
	return (true);
}
