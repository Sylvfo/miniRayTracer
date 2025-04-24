/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_set_transform_ray_sphere.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:47:30 by syl               #+#    #+#             */
/*   Updated: 2025/04/24 19:38:06 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
void 	set_transformation(t_obj ***obj)
{
	int a;
	int b;

	a = 1;
	while(obj[a] != NULL)
	{
		b = 0;
		while(obj[a][b] != NULL)
		{
			if (obj[a][b]->obj_type == SPHERE || obj[a][b]->obj_type == CYLINDER)
			{
				create_scaling_matrix_NA(obj[a][b]->m_scale, obj[a][b]->diam, obj[a][b]->diam, obj[a][b]->diam);
				matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_scale, obj[a][b]->m_tmp);
			}
			if (obj[a][b]->obj_type == PLAN || obj[a][b]->obj_type == CYLINDER)
			{
				rotation_from_vector_NA(obj[a][b]->m_rot, obj[a][b]->v_axe, obj[a][b]);
				matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_rot, obj[a][b]->m_tmp);
			}
			fill_translation_matrix(obj[a][b]->m_transl, obj[a][b]->p_coord->x, obj[a][b]->p_coord->y, obj[a][b]->p_coord->z);
			matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_transl, obj[a][b]->m_tmp);			
			obj[a][b]->m_inv = inverted_matrix_44(obj[a][b]->m_transf);
			b++;
		}
		a++;
	}
}*/


void	set_transformation(t_obj ***obj)
{
	int a = 1;
	int b;

	while (obj[a] != NULL)
	{
		b = 0;
		while (obj[a][b] != NULL)
		{
			t_obj *o = obj[a][b];

			// Matrice de transformation finale (commence à l'identité)
		//	copy_matrix_44_stack(o->m_identity, o->m_transf);

			// SCALE : uniquement pour sphères et cylindres
			if (o->obj_type == SPHERE || o->obj_type == CYLINDER)
			{
				create_scaling_matrix_NA(o->m_scale, o->diam, o->diam, o->diam);
				matrix_multiplication_44_NA(o->m_transf, o->m_scale, o->m_tmp);
			}
			// ROTATION : pour plans et cylindres
			if (o->obj_type == PLAN || o->obj_type == CYLINDER)
			{
				rotation_from_vector_NA(o->m_rot, o->v_axe, o);
				matrix_multiplication_44_NA(o->m_transf, o->m_rot, o->m_tmp);
			}

			// TRANSLATION : toujours
			fill_translation_matrix(o->m_transl, o->p_coord->x, o->p_coord->y, o->p_coord->z);
			matrix_multiplication_44_NA(o->m_transf, o->m_transl, o->m_tmp);

			// Inverse finale
			o->m_inv = inverted_matrix_44(o->m_transf);

			b++;
		}
		a++;
	}
}

void set_transformation_light(t_light ***lux)
{
	int x;
	int y;

	x = 1;
	while(lux[x] != NULL)
	{
		y = 0;
		while(lux[x][y] != NULL)
		{
			fill_translation_matrix(lux[x][y]->m_transf, lux[x][y]->p_coord->x, lux[x][y]->p_coord->y, lux[x][y]->p_coord->z);
			y++;
		}
		x++;
	}
}

void transform_lights(t_light ***lux)
{
//	printf("enter in transform lights\n");
	int x;
	int y;

	x = 1;
	while(x < 2)
	{
		y = 0;
		while(lux[x][y] != NULL)
		{
			//matrix_multiplication_44_coord_NA(lux[x][y]->p_world, lux[x][y]->m_transf, lux[x][y]->p_coord);
			copy_coord(lux[x][y]->p_world,lux[x][y]->p_coord);
			//lux[x][y]->p_world = matrix_multiplication_44_coord(lux[x][y]->m_transf, lux[x][y]->p_coord);
			y++;
		}
		x++;
	}
}

