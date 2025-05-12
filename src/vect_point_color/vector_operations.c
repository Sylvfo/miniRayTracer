/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:43:15 by sforster          #+#    #+#             */
/*   Updated: 2025/05/12 14:14:56 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	cross_product_NA(t_coord *result, t_coord *v_1, t_coord *v_2)
{
	if (!result)
		return ;
	if (is_vector(v_1) == false || is_vector(v_2) == false)
		return ;
	result->x = (v_1->y * v_2->z) - (v_1->z * v_2->y);
	result->y = (v_1->z * v_2->x) - (v_1->x * v_2->z);
	result->z = (v_1->x * v_2->y) - (v_1->y * v_2->x);
}

void	negat_NA(t_coord *result, t_coord *old)
{
	if (!result || !old)
		return ;
	result->x = -old->x;
	result->y = -old->y;
	result->z = -old->z;
	result->t = old->t;
}

/**
 * @brief dot product
 * 
 * avec les angles et les cosin...
 * 
 * @param v_1 a vector
 * @param v_2 an other vector
 * 
 * @return dot product
 */
float	dot_product(t_coord *v_1, t_coord *v_2)
{
	float	dot;

	dot = (v_1->x * v_2->x) + (v_1->y * v_2->y) + (v_1->z * v_2->z);
	return (dot);
}

void	position_NA(t_pix *pix, t_coord *r_dir, float t)
{
	t_coord	tmp;
	t_coord	r_dir_norm;

	copy_coord(&r_dir_norm, r_dir);
	normalize_vector_NA(&r_dir_norm);
	scalar_mult_NA(&tmp, &r_dir_norm, t);
	addition_NA(pix->comps->p_touch, pix->cam->p_coord, &tmp);
}

/*
void position_NA(t_pix *pix, t_coord *r_dir, float t)
{
    t_coord    tmp;
	t_coord	*r_dir_norm;

	r_dir_norm = create_vector(0,0,0);
	copy_coord(r_dir_norm, r_dir);
	normalize_vector_NA(r_dir_norm);
    scalar_mult_NA(&tmp, r_dir_norm, t);
	addition_NA(pix->comps->p_touch, pix->cam->p_coord, &tmp);
}
*/