/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:17:21 by syl               #+#    #+#             */
/*   Updated: 2025/03/11 13:38:27 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//normal sphere
//Algorithmically speaking, you find the normal by taking the point in question and subtracting
// the origin of the sphere ((0,0,0) in your case). Here it is in
t_coord *normal_at(t_obj *sphere, t_coord *point_on_sphere)
{
	t_coord *v_center_point;
	t_coord *v_normal;
	
	v_center_point = substraction(point_on_sphere, sphere->p_coord);
	v_normal = normalize_vector(v_center_point);

	return (v_normal);
}