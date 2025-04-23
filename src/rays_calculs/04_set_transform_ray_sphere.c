/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_set_transform_ray_sphere.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:47:30 by syl               #+#    #+#             */
/*   Updated: 2025/04/23 14:07:07 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
void 	set_transformation(t_obj ***obj)
{
	int a;
	int b;

	a = 1;

//	while (a < 3)
	while (obj[a] != NULL)
	{
		b = 0;
		while(obj[a][b] != NULL)
		{
			if (!obj[a][b]->m_transf)
			{
				printf("debut \n");
				exit (0);
			}
			if (obj[a][b]->obj_type == SPHERE || obj[a][b]->obj_type == CYLINDER)
			{
				create_scaling_matrix_NA(obj[a][b]->m_scale, obj[a][b]->diam, obj[a][b]->diam, obj[a][b]->diam);
				matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_transf, obj[a][b]->m_scale);
			}
			if (obj[a][b]->obj_type == PLAN || obj[a][b]->obj_type == CYLINDER)
			{
				rotation_from_vector_NA(obj[a][b]->m_rot, obj[a][b]->v_axe, obj[a][b]);
				if (!obj[a][b]->m_rot)
				{
					printf("missing matrix here in set rot \n");
					exit (0);
				}
				matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_transf, obj[a][b]->m_rot);
				if (!obj[a][b]->m_transf)
				{
					printf("missing matrix here in set rot transf \n");
					exit (0);
				}
			}
			fill_translation_matrix(obj[a][b]->m_transl, obj[a][b]->p_coord->x, obj[a][b]->p_coord->y, obj[a][b]->p_coord->z);
		//	obj[a][b]->m_transl = create_translation_matrix(obj[a][b]->p_coord->x, obj[a][b]->p_coord->y, obj[a][b]->p_coord->z);
		
			matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_transf, obj[a][b]->m_transl);			
			print_matrix(obj[a][b]->m_transf);
			obj[a][b]->m_inv = inverted_matrix_44(obj[a][b]->m_transf);
			if (obj[a][b]->obj_type == PLAN )
				print_matrix(obj[a][b]->m_transf);
			if (obj[a][b]->obj_type == PLAN )
				print_matrix(obj[a][b]->m_inv);
			if (!obj[a][b]->m_transf)
			{
				printf("missing matrix here in set transf  \n");
				exit (0);
			}
			if (!obj[a][b]->m_inv)
			{
				printf("missing matrix here in set inv \n");
				exit (0);
			}


			b++;
		}
		a++;
	}
}*/

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
				matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_transf, obj[a][b]->m_scale, obj[a][b]->m_tmp);
			}
			if (obj[a][b]->obj_type == PLAN || obj[a][b]->obj_type == CYLINDER)
			{
				print_matrix(obj[a][b]->m_transf);
				rotation_from_vector_NA(obj[a][b]->m_rot, obj[a][b]->v_axe, obj[a][b]);
				matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_transf, obj[a][b]->m_rot, obj[a][b]->m_tmp);
			}
	//		fill_translation_matrix(obj[a][b]->m_transl, obj[a][b]->p_coord->x, obj[a][b]->p_coord->y, obj[a][b]->p_coord->z);
			obj[a][b]->m_transl = create_translation_matrix(obj[a][b]->p_coord->x, obj[a][b]->p_coord->y, obj[a][b]->p_coord->z);
			matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_transf, obj[a][b]->m_transl, obj[a][b]->m_tmp);			
			obj[a][b]->m_inv = inverted_matrix_44(obj[a][b]->m_transf);
			b++;
		}
		a++;
	}
}

void set_transformation_light(t_light ***lux)
{
	int x;
	int y;

	lux[0][0]->m_tranf = create_indentity_matrix_44();
	x = 1;
	while(lux[x] != NULL)
	{
		y = 0;
		while(lux[x][y] != NULL)
		{
			lux[x][y]->m_tranf = create_translation_matrix(lux[x][y]->p_coord->x, lux[x][y]->p_coord->y, lux[x][y]->p_coord->z);	
			y++;
		}
		x++;
	}
}

void transform_lights(t_light ***lux)
{
	printf("enter in transform lights\n");
	int x;
	int y;

	x = 1;
	while(x < 2)
	{
		y = 0;
		while(lux[x][y] != NULL)
		{
			lux[x][y]->p_world = matrix_multiplication_44_coord(lux[x][y]->m_tranf, lux[x][y]->p_coord);
			y++;
		}
		x++;
	}
}

