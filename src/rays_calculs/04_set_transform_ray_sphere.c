/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_set_transform_ray_sphere.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:47:30 by syl               #+#    #+#             */
/*   Updated: 2025/04/29 12:13:44 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
float	*create_translation_matrix(float x, float y, float z)
{
	float	*m_transl;

	m_transl = create_indentity_matrix_44();
	if (!m_transl)
		return (NULL);
	matrix_fill(m_transl, 0, 3, x);
	matrix_fill(m_transl, 1, 3, y);
	matrix_fill(m_transl, 2, 3, z);
	matrix_fill(m_transl, 3, 3, 1);
	return (m_transl);
}


float	*matrix_multiplication_44(float *m_a, float *m_b)
{
	float	*m_new_matrix;
	int		count;
	float	sum;
	int		row;
	int		col;

	if (check_matrix_44_44(m_a, m_b) == false)
		return (NULL);
	m_new_matrix = create_matrix(4, 4);
	if (m_new_matrix == NULL)
		return (NULL);
	count = 0;
	while (count < 16)
	{
		row = count / 4;
		col = count % 4;
		sum = 0;
		sum += m_a[2 + row * 4] * m_b[2 + col];
		sum += m_a[2 + row * 4 + 1] * m_b[2 + 4 + col];
		sum += m_a[2 + row * 4 + 2] * m_b[2 + 8 + col];
		sum += m_a[2 + row * 4 + 3] * m_b[2 + 12 + col];
		m_new_matrix[2 + count] = sum;
		count++;
	}
	return (m_new_matrix);
}*/

/*
//old
void set_transformation(t_obj ***obj)
{
	int x;
	int y;

	obj[0][0]->m_transf = create_indentity_matrix_44();
	x = 1;
	while(x < 4)/// (obj[x] != NULL) on pourra changer après pour les autres objets...
	{
		y = 0;
		while(obj[x][y] != NULL)
		{
		//	obj[x][y]->m_identity = create_indentity_matrix_44();// a initialiser avant...
			obj[x][y]->m_transl = create_translation_matrix(obj[x][y]->p_coord->x, obj[x][y]->p_coord->y, obj[x][y]->p_coord->z);
			obj[x][y]->m_transf = matrix_multiplication_44(obj[x][y]->m_transf, obj[x][y]->m_transl);
			// pas rotations.
			if (obj[x][y]->obj_type == PLAN || obj[x][y]->obj_type == CYLINDER)
			{
			//	obj[x][y]->m_rot = create_indentity_matrix_44(); // à déplacer
				rotation_from_vector_NA(obj[x][y]->m_rot, obj[x][y]->v_axe, obj[x][y]);
			//	rotation_from_vector(obj[x][y]->m_rot, obj[x][y]->v_axe);
				obj[x][y]->m_transf = matrix_multiplication_44(obj[x][y]->m_transf, obj[x][y]->m_rot);
			}
			if (obj[x][y]->obj_type == SPHERE || obj[x][y]->obj_type == CYLINDER)
			{
				obj[x][y]->m_scale = create_scaling_matrix(obj[x][y]->diam, obj[x][y]->diam, obj[x][y]->diam);
				obj[x][y]->m_transf = matrix_multiplication_44(obj[x][y]->m_transf, obj[x][y]->m_scale);
			}	
			obj[x][y]->m_transf = inverted_matrix_44(obj[x][y]->m_transf);
			// inverse
			y++;
		}
		x++;
	}
}*/


/*

//bizzare mais ok
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
			//	init_matrix_zero(obj[a][b]->m_tmp);
				//obj[a][b]->m_scale = create_scaling_matrix(obj[a][b]->diam, obj[a][b]->diam, obj[a][b]->diam);
				create_scaling_matrix_NA(obj[a][b]->m_scale, obj[a][b]->diam, obj[a][b]->diam, obj[a][b]->diam);
	//			matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_scale, obj[a][b]->m_tmp);
				matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_scale);
			//	printf("aaaa\n");
			}
		//	if (obj[a][b]->obj_type == PLAN || obj[a][b]->obj_type == CYLINDER)
			if (a == 2 || a == 3)
			{
				//init_matrix_zero(obj[a][b]->m_tmp);
			//	rotation_from_vector_NA(obj[a][b]);
				rotation_from_vector_NA(obj[a][b]);
				matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_rot);
//				matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_rot, obj[a][b]->m_tmp);
			}
			init_matrix_zero(obj[a][b]->m_tmp);
			fill_translation_matrix(obj[a][b]->m_transl, obj[a][b]->p_coord->x, obj[a][b]->p_coord->y, obj[a][b]->p_coord->z);
			matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_transl);
		//	matrix_multiplication_44_NA(obj[a][b]->m_transf, obj[a][b]->m_transl, obj[a][b]->m_tmp);			
			obj[a][b]->m_inv = inverted_matrix_44(obj[a][b]->m_transf);
		//	print_matrix_44(obj[a][b]->m_inv);
			if (!obj[a][b]->m_inv)
				printf("miss inv\n");
			init_matrix_zero(obj[a][b]->m_tmp);
		//	printf("bbb\n");
			b++;
		}
		a++;
	}
}*/

void set_transformation(t_obj ***obj)
{
    int a = 1;  // Start from 1 assuming obj[0] is something else
    int b;

    while(obj[a] != NULL)
    {
        b = 0;
        while(obj[a][b] != NULL)
        {
            // Initialize transformation matrix to identity
		//	if (obj[a][b]->m_transf != NULL)	
		//		obj[a][b]->m_transf = create_indentity_matrix_44();
        //    set_identity_matrix(obj[a][b]->m_transf);

            // Apply scaling for spheres and cylinders
            if (obj[a][b]->obj_type == SPHERE || obj[a][b]->obj_type == CYLINDER)
            {
				if (obj[a][b]->m_rot != NULL)	
				obj[a][b]->m_rot = create_indentity_matrix_44();
                create_scaling_matrix_NA(obj[a][b]->m_scale, 
                                       obj[a][b]->diam, 
                                       obj[a][b]->diam, 
                                       obj[a][b]->diam);
                matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_scale);
            }

            // Apply rotation for planes and cylinders
            if (obj[a][b]->obj_type == PLAN || obj[a][b]->obj_type == CYLINDER)
            {
                rotation_from_vector_NA(obj[a][b]);
                matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_rot);
            }
			if (!obj[a][b]->m_transl)
			{
				printf("miss transl \n");
				obj[a][b]->m_transl = create_indentity_matrix_44();
			}
            // Apply translation
            fill_translation_matrix(obj[a][b]->m_transl, 
                                  obj[a][b]->p_coord->x, 
                                  obj[a][b]->p_coord->y, 
                                  obj[a][b]->p_coord->z);
            matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_transl);
            // Calculate inverse transformation
            if (!inverse4x4(obj[a][b]->m_transf, obj[a][b]->m_inv))
            {
                printf("Warning: Could not invert transformation matrix for object %d-%d\n", a, b);
				free(obj[a][b]->m_inv);
				obj[a][b]->m_inv = create_indentity_matrix_44();
				//	set_identity_matrix(obj[a][b]->m_inv);  // Fallback to identity
            }
            b++;
        }
        a++;
    }
}

//ACTUELLLE!!!!!!!!!!!!
/*void 	set_transformation(t_obj ***obj)
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
			//	obj[a][b]->m_inv = inverted_matrix_44(obj[a][b]->m_transf);
				matrix_mult_2(obj[a][b]->m_scale, obj[a][b]->m_scale);
			}
			if (!obj[a][b]->m_transf)
				printf("miss transf\n");
			//if (a == 2 || a == 3)
			if (obj[a][b]->obj_type == PLAN || obj[a][b]->obj_type == CYLINDER)
			{
				rotation_from_vector_NA(obj[a][b]);
				//obj[a][b]->m_rot = inverted_matrix_44(obj[a][b]->m_rot);
				matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_rot);
			}
			if (!obj[a][b]->m_transf)
				printf("miss transf 2\n");
			fill_translation_matrix(obj[a][b]->m_transl, obj[a][b]->p_coord->x, obj[a][b]->p_coord->y, obj[a][b]->p_coord->z);
		//	obj[a][b]->m_transl = inverted_matrix_44(obj[a][b]->m_transl);
			matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_transl);
			if (!obj[a][b]->m_transf)
				printf("miss transf 3\n");
			obj[a][b]->m_inv = inverted_matrix_44(obj[a][b]->m_transf);
			//inverse4x4(obj[a][b]->m_transf, obj[a][b]->m_inv);
			if (!obj[a][b]->m_inv)
				printf("miss inv\n");
			b++;
		}
		a++;
	}
}*/

/*
void	set_transformation(t_obj ***obj)s
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
}*/

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
			inverted_matrix_44(lux[x][y]->m_transf);
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
			matrix_point_multiplication_new(lux[x][y]->p_world, lux[x][y]->m_transf, lux[x][y]->p_coord);
			y++;
		}
		x++;
	}
}

