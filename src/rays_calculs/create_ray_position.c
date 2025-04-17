/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:17:39 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 14:17:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//Ray casting is the process of creating a ray, or line, and finding 
//the intersections of that ray with the objects in a scene.


t_coord *position(t_coord *r_origin, t_coord *r_dir, float t)
{
	return addition(r_origin,scalar_mult(r_dir, t));
}

