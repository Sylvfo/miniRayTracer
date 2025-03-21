/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:17:21 by syl               #+#    #+#             */
/*   Updated: 2025/03/19 12:35:54 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//normal sphere
//Algorithmically speaking, you find the normal by taking the point in question and subtracting
// the origin of the sphere ((0,0,0) in your case). Here it is in
t_coord *normal_at(t_obj *sphere, t_coord *point_on_sphere)
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
}

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