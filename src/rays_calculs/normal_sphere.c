/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:17:21 by syl               #+#    #+#             */
/*   Updated: 2025/04/18 18:03:56 by syl              ###   ########.fr       */
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

t_coord	*normal_at(t_obj *object, t_coord *point_on_object)
{
	t_coord *p_object_space;   // Point dans l'espace de l'objet
	t_coord *origin_object;    // Origine de l'objet dans son espace local (0,0,0)
	t_coord *object_normal;    // Normale dans l'espace de l'objet
	t_coord *world_normal;     // Normale dans l'espace du monde
	float *inv_transform;      // Inverse de la matrice de transformation
	float *transp_inv;         // Transposée de l'inverse

	// Créer un point représentant l'origine (0,0,0) dans l'espace local de l'objet
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
	p_object_space = matrix_multiplication_44_coord(inv_transform, point_on_object);
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
	if (!object_normal)
	{
		free(inv_transform);
		return (NULL);
	}

	// Obtenir la transposée de l'inverse de la matrice de transformation
	transp_inv = transpose_matrix(inv_transform);
	free(inv_transform);
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
}

