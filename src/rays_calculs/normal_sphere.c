/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:17:21 by syl               #+#    #+#             */
/*   Updated: 2025/04/23 14:29:50 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// À ajouter dans votre bibliothèque de matrices
float *transpose_matrix(float *m)
{
	float *result;
	int i;
	int j;
	
	if (!m || m[0] != 4 || m[1] != 4)
		return (NULL);
	
	result = create_matrix(4, 4);
	if (!result)
		return (NULL);
	
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
	return (result);
}

void transpose_matrix_NA(float *result, float *m)
{
	int i;
	int j;
	
	if (!m || m[0] != 4 || m[1] != 4)
		return;
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

/*
t_coord	*normal_at(t_obj *object, t_coord *p_touch)
{
	t_coord *p_object_space;   // Point dans l'espace de l'objet
	t_coord *origin_object;    // Origine de l'objet dans son espace local (0,0,0)
	t_coord *object_normal;    // Normale dans l'espace de l'objet
	t_coord *world_normal;     // Normale dans l'espace du monde
	float *inv_transform;      // Inverse de la matrice de transformation
	float *transp_inv;         // Transposée de l'inverse

	// Créer un point représentant l'origine (0,0,0) dans l'espace local de l'objet
	//mneme
	origin_object = create_point(0, 0, 0);
	if (!origin_object)
		return (NULL);

	// Obtenir l'inverse de la matrice de transformation de l'objet
//	inv_transform = inverted_matrix_44(object->m_transf);
	inv_transform = object->m_transf;
	if (!inv_transform)
	{
		free(origin_object);
		return (NULL);
	}

	// Transformer le point du monde vers l'espace local de l'objet
//	p_object_space = matrix_multiplication_44_point(object->m_inv, p_touch);
	p_object_space = matrix_multiplication_44_coord(object->m_inv, p_touch);
	if (!p_object_space)
	{
		free(origin_object);
		free(inv_transform);
		return (NULL);
	}
	// Calculer la normale dans l'espace local de l'objet
	object_normal = substraction(p_object_space, origin_object);
	free(origin_object);
	free(p_object_space);
//	if (!object_normal)
//	{
//		free(inv_transform);§
//		return (NULL);
//	}
	//a enlever
//	t_coord *normalized_normal = malloc(sizeof(t_coord));
//	normalized_normal = normalize_vector(object_normal);


	// Obtenir la transposée de l'inverse de la matrice de transformation
	transp_inv = transpose_matrix(object->m_inv);
//	free(inv_transform);
	if (!transp_inv)
	{
		free(object_normal);
		return (NULL);
	}
	// Transformer la normale vers l'espace du monde
	world_normal = matrix_multiplication_44_coord(transp_inv, object_normal);
	free(object_normal);
	free(transp_inv);
	if (!world_normal)
		return (NULL);

	// S'assurer que c'est un vecteur, pas un point
	world_normal->t = 0;

	// Normaliser le vecteur résultant
//	t_coord *normalized_normal = normalize_vector(world_normal);
	// syl a modifié pour ajouter malloc a normalized_normal
	t_coord *normalized_normal = malloc(sizeof(t_coord));
	normalized_normal = normalize_vector(world_normal);

	free(world_normal);
	
	return (normalized_normal);
}*/

void	normal_at_NA(t_comps *comps)
{
	comps->obj->p_object_space = matrix_multiplication_44_coord(comps->obj->m_inv, comps->p_touch);
	if (!comps->obj->p_object_space)
	{
		printf("a\n");
		exit (0);
	}
	// Calculer la normale dans l'espace local de l'objet
//	comps->obj->object_normal = substraction(comps->obj->p_object_space, comps->obj->origin_zero);
	substraction_p_to_v_NA(comps->obj->object_normal, comps->obj->p_object_space, comps->obj->origin_zero);
	transpose_matrix_NA(comps->obj->transp_inv, comps->obj->m_inv);

	matrix_multiplication_44_coord_NA(comps->v_norm_parral, comps->obj->transp_inv, comps->obj->object_normal);
//	comps->v_norm_parral = matrix_multiplication_44_coord(comps->obj->transp_inv, comps->obj->object_normal);
	comps->v_norm_parral->t = 0;

	normalize_vector_NA(comps->v_norm_parral);
}

/*
//pix[x][y]->comps->v_norm_parral = normal_at(pix[x][y]->comps->obj, pix[x][y]->comps->p_touch);
//t_coord	*normal_at_NA(t_coord *v t_obj *object, t_coord *p_touch)
void	normal_at_NA(t_pix *pix)
{
	pix->comps->obj->p_object_space = matrix_multiplication_44_coord(pix->comps->obj->m_inv, pix->comps->p_touch);

	// Calculer la normale dans l'espace local de l'objet
	pix->comps->obj->object_normal = substraction(pix->comps->obj->p_object_space, pix->comps->obj->origin_zero);

	pix->comps->obj->transp_inv = transpose_matrix(pix->comps->obj->m_inv);
	//transp_inv = transpose_matrix(object->m_inv);

//	free(inv_transform);
	//YA DES ERREURS ICI...
	pix->comps->v_norm_parral = matrix_multiplication_44_coord(pix->comps->obj->transp_inv, pix->comps->obj->object_normal);
	pix->comps->v_norm_parral->t = 0;
	clean...
	// Normaliser le vecteur résultant
	normalize_vector_NA(pix->comps->v_norm_parral);
}*/