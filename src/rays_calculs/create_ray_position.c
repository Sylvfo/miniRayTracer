/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:17:39 by syl               #+#    #+#             */
/*   Updated: 2025/05/02 16:16:49 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//Ray casting is the process of creating a ray, or line, and finding 
//the intersections of that ray with the objects in a scene.

t_coord *position(t_coord *r_origin, t_coord *r_dir, float t)
{
	return addition(r_origin,scalar_mult(r_dir, t));
}

/*
void position_NA(t_coord *result, t_coord *r_origin, t_coord *r_dir, float t)
{
	scalar_mult_NA(result, r_dir, t);
	addition_NA(result, r_origin, result);
//	return addition(r_origin, scalar_mult(r_dir, t));
}*/

void position_NA(t_coord *result, t_coord *r_origin, t_coord *r_dir, float t)
{
    t_coord    tmp;
	t_coord	*r_dir_norm;

//	print_vector(r_dir);
//	r_dir_norm = normalize_vector(r_dir);

	r_dir_norm = create_vector(0,0,0);
	copy_coord(r_dir_norm, r_dir);
	normalize_vector_NA(r_dir_norm);
	printf("normalized r dir \n");
	print_vector(r_dir);
    scalar_mult_NA(&tmp, r_dir_norm, t);
	print_vector(&tmp);
    addition_NA(result, r_origin, &tmp);
	print_point(result);
	
}