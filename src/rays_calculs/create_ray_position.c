/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:17:39 by syl               #+#    #+#             */
/*   Updated: 2025/05/06 09:06:40 by syl              ###   ########.fr       */
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

//void position_NA(t_coord *result, t_coord *r_origin, t_coord *r_dir, float t)
void position_NA(t_pix *pix, t_coord *r_dir, float t)
{
    t_coord    tmp;
	t_coord	*r_dir_norm;

	r_dir_norm = create_vector(0,0,0);
	copy_coord(r_dir_norm, r_dir);
	normalize_vector_NA_fabs(r_dir_norm);
    scalar_mult_NA(&tmp, r_dir_norm, t);

	addition_NA(pix->comps->p_touch, pix->cam->p_coord, &tmp);
}

/*
void position_NA(t_coord *result, t_coord *r_origin, t_coord *r_dir, float t)
{
    t_coord    tmp;
	t_coord	*r_dir_norm;
	t_coord	*p_point;

//	print_vector(r_dir);
//	r_dir_norm = normalize_vector(r_dir);

//	r_dir_norm = create_vector(0,0,0);
//	copy_coord(r_dir_norm, r_dir);
//	p_point = create_point(0, 0, 0);
//	p_point->z = 20;
//	fill_point_vector(p_point, 0, 0, 20);

//	normalize_vector_NA_fabs(r_dir_norm);
//	printf("\nlength r dir norm %f \n",length_vector(r_dir));
//	normalize_vector_NA(r_dir_norm);
//	printf("normalized r dir \n");
//	print_vector(r_dir_norm);
scalar_mult_NA(&tmp, r_dir_norm, t);
print_vector(&tmp);
//	print_vector(&tmp);



//  addition_NA(result, r_origin, &tmp);
addition_NA(result, pix->cam->p_coord, &tmp);
	fabs(result->x);
fabs(result->y);
fabs(result->z);
print_point(result); pix[x][y]->comps->p_touch
//	print_point(result);

}*/

