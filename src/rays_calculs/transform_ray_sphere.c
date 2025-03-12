/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:47:30 by syl               #+#    #+#             */
/*   Updated: 2025/03/12 15:30:36 by syl              ###   ########.fr       */
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

	x = 1;
	while(x < 2)/// (obj[x] != NULL) on pourra changer après pour les autres objets...
	{
		y = 0;
		while(obj[x][y] != NULL)
		{
			obj[x][y]->m_identity = create_indentity_matrix_44();// a initialiser avant...
		//	translation_on_identity(obj[x][y]->m_tranf, obj[x][y]->p_coord->x, obj[x][y]->p_coord->y, obj[x][y]->p_coord->z);
			obj[x][y]->m_transl = create_translation_matrix(obj[x][y]->p_coord->x, obj[x][y]->p_coord->y, obj[x][y]->p_coord->z);
			obj[x][y]->m_scale = create_scaling_matrix(obj[x][y]->diam, obj[x][y]->diam, obj[x][y]->diam);
			// pas rotations.
			obj[x][y]->m_tranf = matrix_multiplication_44(obj[x][y]->m_identity, obj[x][y]->m_transl);
			obj[x][y]->m_tranf = matrix_multiplication_44(obj[x][y]->m_tranf, obj[x][y]->m_scale);
			obj[x][y]->m_tranf = inverted_matrix_44(obj[x][y]->m_tranf);
			// inverse
			y++;
		}
		x++;
	}
}
//void transform(t_ray *r_original, float *trans_matrix)
void transform(t_pix *pix, float *m_transf)
{
	pix->r_ray->p_origin = matrix_multiplication_44_coord(m_transf, pix->r_original->p_origin);
//	pix->r_ray->v_dir = matrix_multiplication_44_coord(m_transf, pix->r_original->v_dir); bon ca change pas grande chose

	pix->r_ray->v_dir = pix->r_original->v_dir; //celui la ca marche

//	pix->r_ray->v_dir = normalize_vector(pix->r_original->v_dir);
	return ;
}

/*
t_ray transform_ray(t_ray ray, t_matrix inv_M) {
    t_ray transformed;
    
    transformed.origin = matrix_mult_point(inv_M, ray.origin);
    transformed.dir = matrix_mult_vector(inv_M, ray.dir);
    transformed.dir = normalize(transformed.dir);
    
    return transformed;
}

*/

/*
 Générer le rayon dans l’espace global
Appliquer l’inverse de la transformation de la sphère au rayon
Calculer l’intersection avec une sphère standard
Convertir le point d’intersection en coordonnées réelles

calculer les rays a zero zero??
matrice de transformation de chaque objet avec toutes les transformations. 

*/