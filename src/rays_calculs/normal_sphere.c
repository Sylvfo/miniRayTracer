/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:17:21 by syl               #+#    #+#             */
/*   Updated: 2025/03/14 14:26:50 by syl              ###   ########.fr       */
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
	
	v_center_point = substraction(point_on_sphere, sphere->p_coord);// c est sensé etre zer0???
	v_normal = normalize_vector(v_normal);
	v_normal->t = 0;//rajouté...
	return (v_normal);
}

/*
/// a continuer à coder avec ce transpose inverse machin 
t_coord *normal_at_suite(t_obj *sphere, t_coord *point_on_sphere)
{
//	t_coord *v_center_point;
	t_coord *v_normal; // world normal
	t_coord	*p_object;
	t_coord *v_obj_normal;

	p_object = matrix_multiplication_44_coord(inverted_matrix_44(sphere->m_tranf), point_on_sphere);
	v_obj_normal = substraction(p_object, point 000);


	v_center_point = substraction(point_on_sphere, sphere->p_coord);// c est sensé etre zer0???
	v_normal = normalize_vector(v_center_point);

	return (v_normal);
}

function normal_at(sphere, world_point)
object_point ← inverse(sphere.transform) * world_point
object_normal ← object_point - point(0, 0, 0) // ici c est le normal
world_normal ← transpose(inverse(sphere.transform)) * object_normal // la transpose
world_normal.w ← 0
return normalize(world_normal)
end function*/