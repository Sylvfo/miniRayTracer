/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:47:30 by syl               #+#    #+#             */
/*   Updated: 2025/04/13 16:02:51 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//You say you want to move the sphere, but what you
//really want, fundamentally, is for the distance between the sphere and the
//ray’s origin to increase or decrease, or the relationship between the ray’s
//direction and the sphere’s position to change,

//What if, instead of moving the sphere, you move the ray?

//whatever transformation you want to apply to the sphere,
//apply the inverse of that transformation to the ray

/*
//applies the given transformation matrix to the given ray, 
//and returns a new ray with transformed origin and direction
// a new ray!!!
void transform(t_ray *r_original, float *trans_matrix)
{
	t_ray	*new_ray;
	t_coord *transl;

	new_ray = malloc(sizeof(t_ray));
	new_ray->p_origin = translation(ray->p_origin, 3, 4, 5);// pointeur sur fonction??
	new_ray->v_dir = ray->v_dir;
	return ;
}*/

// ordre transformation: T R S
void set_transformation(t_obj ***obj)
{
	int x;
	int y;

	obj[0][0]->m_tranf = create_indentity_matrix_44();
	x = 1;
	while(x < 3)/// (obj[x] != NULL) on pourra changer après pour les autres objets...
	{
		y = 0;
		while(obj[x][y] != NULL)
		{
			obj[x][y]->m_identity = create_indentity_matrix_44();// a initialiser avant...
		//	translation_on_identity(obj[x][y]->m_tranf, obj[x][y]->p_coord->x, obj[x][y]->p_coord->y, obj[x][y]->p_coord->z);
			obj[x][y]->m_transl = create_translation_matrix(obj[x][y]->p_coord->x, obj[x][y]->p_coord->y, obj[x][y]->p_coord->z);
			obj[x][y]->m_tranf = matrix_multiplication_44(obj[x][y]->m_identity, obj[x][y]->m_transl);

			// pas rotations.
			if (obj[x][y]->obj_type == PLAN)// || obj[x][y]->obj_type == CYLINDER)
			{
				obj[x][y]->m_rot = create_indentity_matrix_44(); // à déplacer
				rotation_from_vector(obj[x][y]->m_rot, obj[x][y]->v_axe);
				obj[x][y]->m_tranf = matrix_multiplication_44(obj[x][y]->m_tranf, obj[x][y]->m_rot);
			}
			if (obj[x][y]->obj_type == SPHERE || obj[x][y]->obj_type == CYLINDER)
			{
				obj[x][y]->m_scale = create_scaling_matrix(obj[x][y]->diam, obj[x][y]->diam, obj[x][y]->diam);
				obj[x][y]->m_tranf = matrix_multiplication_44(obj[x][y]->m_tranf, obj[x][y]->m_scale);
			}	
			obj[x][y]->m_tranf = inverted_matrix_44(obj[x][y]->m_tranf);
			// inverse
			y++;
		}
		x++;
	}
}
void set_transformation_light(t_light ***lux)
{
	int x;
	int y;

	lux[0][0]->m_tranf = create_indentity_matrix_44();
	x = 1;
	while(x < 2)/// (obj[x] != NULL) on pourra changer après pour les autres objets...
	{
		y = 0;
		while(lux[x][y] != NULL)
		{
			lux[x][y]->m_identity = create_indentity_matrix_44();// a initialiser avant...
			lux[x][y]->m_transl = create_translation_matrix(lux[x][y]->p_coord->x, lux[x][y]->p_coord->y, lux[x][y]->p_coord->z);
			lux[x][y]->m_tranf = matrix_multiplication_44(lux[x][y]->m_identity, lux[x][y]->m_transl);
			lux[x][y]->m_tranf = inverted_matrix_44(lux[x][y]->m_tranf);
			y++;
		}
		x++;
	}
}
void transform_lights(t_light ***lux)
{
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
//void transform(t_ray *r_original, float *trans_matrix)
//rename transform sphere
void transform(t_pix *pix, float *m_transf, int sphere_num)
{
	if (pix->hits[1][sphere_num]->r_ray_calculs == NULL)
	{
		printf("error malloc");
		exit;
	}
	if (pix->hits[1][sphere_num]->r_ray_calculs->p_origin == NULL)
	{
		printf("error malloc2");
		exit;
	}
	if (pix->hits[1][sphere_num]->r_ray_calculs->v_dir == NULL)
	{
		printf("error malloc3");
		exit;
	}
	pix->hits[1][sphere_num]->r_ray_calculs->p_origin = matrix_multiplication_44_coord(m_transf, pix->r_original->p_origin);
	pix->hits[1][sphere_num]->r_ray_calculs->v_dir = matrix_multiplication_44_coord(m_transf, pix->r_original->v_dir);
	return ;
}

void transform_plan(t_pix *pix, float *m_transf, int plan_num)
{
	if (pix->hits[2][plan_num]->r_ray_calculs == NULL)
	{
		printf("error malloc");
		exit;
	}
	if (pix->hits[2][plan_num]->r_ray_calculs->p_origin == NULL)
	{
		printf("error malloc2");
		exit;
	}
	if (pix->hits[2][plan_num]->r_ray_calculs->v_dir == NULL)
	{
		printf("error malloc3");
		exit;
	}
	pix->hits[2][plan_num]->r_ray_calculs->p_origin = matrix_multiplication_44_coord(m_transf, pix->r_original->p_origin);
	pix->hits[2][plan_num]->r_ray_calculs->v_dir = matrix_multiplication_44_coord(m_transf, pix->r_original->v_dir);
	//idem pour autres formes
	
	return ;
}

