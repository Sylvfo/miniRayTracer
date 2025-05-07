/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:17:21 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 10:11:16 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void transpose_matrix_NA(float *result, float *m)
{
	int i;
	int j;
	
	if (!m || m[0] != 4 || m[1] != 4)
	{
		printf("problème\n");
		return;
	}
	
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix_fill(result, i, j, m[2 + j * 4 + i]);
			j++;
		}
		i++;
	}
}

//normal = normalize(p_object_space - origin)
void	normal_at_NA(t_comps *comps)
{
	//p_touch dans espace objet
	matrix_point_multiplication_new(comps->p_space, comps->obj_inv, comps->p_touch);

	// Calculer la normale dans l'espace local de l'objet
	substraction_p_to_v_NA(comps->object_normal, comps->p_space, comps->origin_zero);
	normalize_vector_NA(comps->object_normal);///A RETIRER??
	transpose_matrix_NA(comps->transp_inv, comps->obj_inv);
	matrix_point_multiplication_new(comps->v_norm_parral, comps->transp_inv, comps->object_normal);
	normalize_vector_NA(comps->v_norm_parral);
//	if (comps->obj_type == CYLINDER && comps->p_space->x == 1, comps->p_space->y == 0, comps->p_space->z == 0)
//		print_vector(comps->v_norm_parral);
	if (comps->obj_type == CYLINDER)
		normal_caps(comps);	

}

void	normal_caps(t_comps *comps)
{
	float dist;

	dist = (comps->p_space->x * comps->p_space->x) + (comps->p_space->z * comps->p_space->z);
	if (dist <= 1 && comps->p_space->y >= comps->height - EPSILON)
	{
	//	printf("cyl height %.2f \n", comps->height);
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = 1;
		comps->v_norm_parral->z = 0;
		return;
	}
	if (dist <= 1 && comps->p_space->y <= -comps->height + EPSILON)
	{
	//	printf("cyl height %.2f \n", comps->height);
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = -1;
		comps->v_norm_parral->z = 0;
		return;
	}
//	printf(".");

	comps->v_norm_parral->x = comps->p_space->x;
	comps->v_norm_parral->y = 0;
	comps->v_norm_parral->z = comps->p_space->z;
//	print_vector(comps->v_norm_parral);
}