/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:17:21 by syl               #+#    #+#             */
/*   Updated: 2025/04/06 14:36:20 by syl              ###   ########.fr       */
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
	inv_transform = inverted_matrix_44(object->m_tranf);
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
	t_coord *normalized_normal = normalize_vector(world_normal);
	free(world_normal);
	
	return (normalized_normal);
}

//normal sphere
//Algorithmically speaking, you find the normal by taking the point in question and subtracting
// the origin of the sphere ((0,0,0) in your case). Here it is in
/* t_coord *normal_at(t_obj *sphere, t_coord *point_on_sphere)
{
	t_coord *v_center_point;
	t_coord *v_normal;

	// Calculer le vecteur entre le point sur la sphère et le centre de la sphère
	v_center_point = substraction(point_on_sphere, sphere->p_coord);
	if (!v_center_point)
		return (NULL); // Vérifier si l'allocation a échoué dans substraction

	// Normaliser le vecteur pour obtenir la normale
	v_normal = normalize_vector(v_center_point);
	if (!v_normal)
	{
		free(v_center_point); // Libérer la mémoire si normalize_vector échoue
		return (NULL);
	}

	// Définir le type du vecteur (0 pour un vecteur)
	v_normal->t = 0;

	// Libérer la mémoire de v_center_point car elle n'est plus nécessaire
	free(v_center_point);

	return (v_normal);
} */

/*
/// a continuer à coder avec ce transpose inverse machin 
t_coord *normal_at_suite(t_obj *sphere, t_coord *point_on_sphere)
{
//	t_coord *v_center_point;
	t_coord *v_normal; // world normal
	t_coord	*p_object;
	t_coord *v_obj_normal;

	p_object = matrix_multiplication_44_coord(inverted_matrix_44(sphere->m_tranf), point_on_sphere);
	v_obj_normal = substraction(p_object, point 000);


	v_center_point = substraction(point_on_sphere, sphere->p_coord);// c est sensé etre zer0???
	v_normal = normalize_vector(v_center_point);

	return (v_normal);
}

function normal_at(sphere, world_point)
object_point ← inverse(sphere.transform) * world_point
object_normal ← object_point - point(0, 0, 0) // ici c est le normal
world_normal ← transpose(inverse(sphere.transform)) * object_normal // la transpose
world_normal.w ← 0
return normalize(world_normal)
end function*/