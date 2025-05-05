/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:17:39 by syl               #+#    #+#             */
/*   Updated: 2025/05/05 10:09:58 by syl              ###   ########.fr       */
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
	t_coord	*p_point;

//	print_vector(r_dir);
//	r_dir_norm = normalize_vector(r_dir);

	r_dir_norm = create_vector(0,0,0);
	copy_coord(r_dir_norm, r_dir);
	p_point = create_point(0, 0, 0);
	p_point->z = 20;
//	fill_point_vector(p_point, 0, 0, 20);

	printf("closestt in position %.2f \n", t);
	print_point(r_origin);
	print_vector(r_dir);
	print_vector(r_dir_norm);
/*	printf("\n\n in position NA \n vector r_dir\n");
	print_vector(r_dir_norm);
	printf("\n in position NA \n p origin\n");
	print_point(r_origin);*/
//	normalize_vector_NA_fabs(r_dir_norm);
//	printf("\nlength r dir norm %f \n",length_vector(r_dir));
//	normalize_vector_NA(r_dir_norm);
//	printf("normalized r dir \n");
//	print_vector(r_dir_norm);
    scalar_mult_NA(&tmp, r_dir_norm, t);
	print_vector(&tmp);
//	print_vector(&tmp);



  //  addition_NA(result, r_origin, &tmp);
	addition_NA(result, p_point, &tmp);
	fabs(result->x);
	fabs(result->y);
	fabs(result->z);
	print_point(result);
//	print_point(result);
	
}