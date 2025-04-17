/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 19:27:34 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// VERSION CORENTIN DU 14 AVRIL
/*
#include "../inc/minirt.h"

float	compute_specular(t_pix *pix, t_light *lux)
{
	t_coord	*view_dir;
	t_coord	*reflect_dir;
	float	specular_intensity;
	float	reflect_dot_view;
	t_coord *light_dir;

	specular_intensity = 0.0;
	// Calcul du vecteur lumière (L)
	light_dir = normalize_vector(substraction(lux->p_world, pix->comps->p_touch));

	// Calcul de la réflexion du vecteur lumière : R = 2 (N . L) N - L
	reflect_dir = substraction(
		scalar_mult(
			pix->comps->v_norm_parral,
			2.0 * dot_product(
				pix->comps->v_norm_parral,
				light_dir
			)
		),
		light_dir
	);
	reflect_dir = normalize_vector(reflect_dir);

	// Vecteur d'observation (inverse du vecteur vers le point d'intersection)
	view_dir = normalize_vector(scalar_mult(pix->comps->v_norm_parral, -1.0));

	// Produit scalaire entre R et V (reflect_dot_view)
	reflect_dot_view = dot_product(reflect_dir, view_dir);
	if (reflect_dot_view > 0)
	{
		// Application de shininess et factor de specular
		specular_intensity = lux->ratio * pow(reflect_dot_view, 50.0) * 0.5;
	}

	free(view_dir);
	free(reflect_dir);
	free(light_dir);
	return (specular_intensity);
}


void	new_light(t_pix ***pix)
{
	int	x;
	int	y;
//	int a_effacer = 0;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
		//	if (pix[x][y]->comps->t_count == 1)
		//	{
		//		printf("on entre dans calcul lum pour %i %i et total %i\n", x, y, a_effacer);
		//		a_effacer++;
		//	}
			ComputeLighting(pix[x][y]);
			y++;
		}
		x++;
	}
}

void ComputeLighting(t_pix *pix)
{
//	pix->comps->p_touch = P
//	pix->comps->v_norm_parral = N // A normé??

	float intensity;

	intensity = light_intensity(pix);
	scalar_mult_color(pix->color, intensity);
}

t_hits intersect_object(t_obj *object, t_ray *ray)
{
	t_hits hits;
	t_coord *oc;
	float a, b, c, discriminant;

	// Initialisation des hits
	hits.t_count = 0;
	hits.t1 = -1;
	hits.t2 = -1;

	// Calcul des coefficients pour l'équation quadratique
	oc = substraction(ray->p_origin, object->p_coord);
	a = dot_product(ray->v_dir, ray->v_dir);
	b = 2.0 * dot_product(oc, ray->v_dir);
	c = dot_product(oc, oc) - (object->diam / 2) * (object->diam / 2);
	discriminant = b * b - 4 * a * c;

	if (discriminant >= 0)
	{
		hits.t1 = (-b - sqrt(discriminant)) / (2.0 * a);
		hits.t2 = (-b + sqrt(discriminant)) / (2.0 * a);

		// Remplacement de l'opérateur ternaire
		if (discriminant > 0)
			hits.t_count = 2;
		else
			hits.t_count = 1;
	}

	free(oc);
	return hits;
}

t_hits intersect_objects(t_obj ***objects, t_ray *ray)
{
	t_hits hits;
	int i, j;
	t_hits temp_hits;

	// Initialisation des hits
	hits.t_count = 0;
	hits.t1 = -1;
	hits.t2 = -1;

	// Parcourt tous les objets de la scène
	i = 0;
	while (objects[i] != NULL) // Parcourt les types d'objets (sphère, plan, etc.)
	{
		j = 0;
		while (objects[i][j] != NULL) // Parcourt les instances d'un type d'objet
		{
			// Vérifie l'intersection avec l'objet courant
			temp_hits = intersect_object(objects[i][j], ray);

			// Si une intersection est trouvée, met à jour les hits
			if (temp_hits.t_count > 0)
			{
				if (hits.t_count == 0 || temp_hits.t1 < hits.t1)
				{
					hits.t1 = temp_hits.t1;
					hits.t2 = temp_hits.t2;
					hits.t_count = temp_hits.t_count;
				}
			}
			j++;
		}
		i++;
	}

	return hits;
}

bool is_in_shadow(t_coord *point, t_light *light, t_obj ***objects)
{
	t_ray shadow_ray;
	t_hits hits;

	shadow_ray.p_origin = point;
	shadow_ray.v_dir = substraction(light->p_coord, point);
	//probleme normalize()
	normalize_vector(shadow_ray.v_dir);

	hits = intersect_objects(objects, &shadow_ray);
	if (hits.t_count > 0 && hits.t1 > 0)
		return (true); // Le point est dans l'ombre
	return (false);
}


 float compute_pointlight(t_pix *pix, t_light *lux)
{
    t_coord *v_light;
    float n_dot_l;
    float intensity;

    // Vérifier si le point d'intersection est dans l'ombre pour cette lumière
    if (is_in_shadow(pix->comps->p_touch, lux, pix->obj))
        return 0.0;

    intensity = 0.0;
    v_light = substraction(lux->p_world, pix->comps->p_touch);
    v_light = normalize_vector(v_light);
    
    n_dot_l = dot_product(pix->comps->v_norm_parral, v_light);
    if (n_dot_l > 0)
    {
        intensity = lux->ratio * n_dot_l /
                    (length_vector(pix->comps->v_norm_parral) * length_vector(v_light));
    }
    free(v_light);
    return intensity;
} 

float light_intensity(t_pix *pix)
{
	float intensity;
	int i;

	intensity = 0.0;
	// Lumière ambiante
	intensity += pix->lux[0][0]->ratio;
	// Lumières ponctuelles
	i = 0;
    while (pix->lux[1][i] != NULL)
    {
        if (pix->comps->t_count > 0)
        {
            // Lumière diffuse
            intensity += compute_pointlight(pix, pix->lux[1][i]); // Problème ici
            // Lumière spéculaire
            intensity += compute_specular(pix, pix->lux[1][i]);
        }
        i++;
    }
    return (intensity);
}*/

/*
float compute_pointlight(t_pix *pix, t_light *lux)
{
	t_coord *v_light;
	float n_dot_l;
	float intensity;

	intensity = 0.0;

	// Calcul du vecteur lumière (L)
//	printf("Appel à substraction avec :\n");
//	printf("lux->p_coord : x = %f, y = %f, z = %f\n", lux->p_coord->x, lux->p_coord->y, lux->p_coord->z);
//	printf("pix->comps->p_touch : x = %f, y = %f, z = %f\n", pix->comps->p_touch->x, pix->comps->p_touch->y, pix->comps->p_touch->z);
	v_light = substraction(lux->p_world, pix->comps->p_touch);
//	printf("Vecteur lumière (L) : x = %f, y = %f, z = %f\n", v_light->x, v_light->y, v_light->z);

	// Normalisation des vecteurs
//	pix->comps->v_norm_parral = normalize_vector(pix->comps->v_norm_parral);
//	printf("Normale (N) normalisée : x = %f, y = %f, z = %f\n",
//		pix->comps->v_norm_parral->x, pix->comps->v_norm_parral->y, pix->comps->v_norm_parral->z);

	v_light = normalize_vector(v_light);
//	printf("Vecteur lumière (L) normalisé : x = %f, y = %f, z = %f\n",
//		v_light->x, v_light->y, v_light->z);

	// Calcul du produit scalaire entre la normale (N) et le vecteur lumière (L)
	n_dot_l = dot_product(pix->comps->v_norm_parral, v_light);
//	printf("Produit scalaire (N . L) : %f\n", n_dot_l);
	// Vérification si le produit scalaire est positif
	if (n_dot_l > 0)
	{
		intensity = lux->ratio * n_dot_l / (length_vector(pix->comps->v_norm_parral) * length_vector(v_light));
	//	printf("Intensité calculée : %f\n", intensity);
	}
//	else
//		printf("Produit scalaire négatif, aucune contribution lumineuse.\n");

	// Libération de la mémoire pour le vecteur lumière
	free(v_light);

	return (intensity);
}*/