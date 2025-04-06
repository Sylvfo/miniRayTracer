/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/04/06 23:55:41 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	new_light(t_pix ***pix)
{
	int	x;
	int	y;
	int a_effacer = 0;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->comps->t_count == 1)
			{
				printf("on entre dans calcul lum pour %i %i et total %i\n", x, y, a_effacer);
				a_effacer++;
			}
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


float compute_pointlight(t_pix *pix, t_light *lux)
{
	t_coord *v_light;
	float n_dot_l;
	float intensity;

	intensity = 0.0;

	// Calcul du vecteur lumière (L)
//	printf("Appel à substraction avec :\n");
//	printf("lux->p_coord : x = %f, y = %f, z = %f\n", lux->p_coord->x, lux->p_coord->y, lux->p_coord->z);
	printf("pix->comps->p_touch : x = %f, y = %f, z = %f\n", pix->comps->p_touch->x, pix->comps->p_touch->y, pix->comps->p_touch->z);
	v_light = substraction(lux->p_world, pix->comps->p_touch);
//	printf("Vecteur lumière (L) : x = %f, y = %f, z = %f\n", v_light->x, v_light->y, v_light->z);

	// Normalisation des vecteurs
//	pix->comps->v_norm_parral = normalize_vector(pix->comps->v_norm_parral);
	printf("Normale (N) normalisée : x = %f, y = %f, z = %f\n",
		pix->comps->v_norm_parral->x, pix->comps->v_norm_parral->y, pix->comps->v_norm_parral->z);

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
		printf("Intensité calculée : %f\n", intensity);
	}
//	else
//		printf("Produit scalaire négatif, aucune contribution lumineuse.\n");

	// Libération de la mémoire pour le vecteur lumière
	free(v_light);

	return (intensity);
}

/*FONCTIONNE A PEU PRES... AVANT DE CHANGER LIGHTS...
float compute_pointlight(t_pix *pix, t_light *lux)
{
	t_coord *v_light;
	float n_dot_l;
	float intensity;

	intensity = 0.0;

	// Calcul du vecteur lumière (L)
//	printf("Appel à substraction avec :\n");
//	printf("lux->p_coord : x = %f, y = %f, z = %f\n", lux->p_coord->x, lux->p_coord->y, lux->p_coord->z);
	printf("pix->comps->p_touch : x = %f, y = %f, z = %f\n", pix->comps->p_touch->x, pix->comps->p_touch->y, pix->comps->p_touch->z);
	v_light = substraction(lux->p_coord, pix->comps->p_touch);
//	printf("Vecteur lumière (L) : x = %f, y = %f, z = %f\n", v_light->x, v_light->y, v_light->z);

	// Normalisation des vecteurs
//	pix->comps->v_norm_parral = normalize_vector(pix->comps->v_norm_parral);
	printf("Normale (N) normalisée : x = %f, y = %f, z = %f\n",
		pix->comps->v_norm_parral->x, pix->comps->v_norm_parral->y, pix->comps->v_norm_parral->z);

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
		printf("Intensité calculée : %f\n", intensity);
	}
//	else
//		printf("Produit scalaire négatif, aucune contribution lumineuse.\n");

	// Libération de la mémoire pour le vecteur lumière
	free(v_light);

	return (intensity);
}
*/
/*p
float compute_pointlight(t_pix *pix, t_light *lux)
{
    t_coord *v_light;
    float n_dot_l;
    float intensity;

    intensity = 0.0;

    // Calcul du vecteur lumière (L)
    v_light = substraction(lux->p_coord, pix->comps->p_touch);

    // Normalisation des vecteurs
    pix->comps->v_norm_parral = normalize_vector(pix->comps->v_norm_parral);
    v_light = normalize_vector(v_light);

    // Calcul du produit scalaire entre la normale et le vecteur lumière
    n_dot_l = dot_product(pix->comps->v_norm_parral, v_light);
    printf("Produit scalaire (N · L) : %f\n", n_dot_l);

    // Vérifiez l'orientation de la normale pour qu'elle pointe vers la lumière
    if (n_dot_l < 0) {
        printf("Inverser la normale pour l'aligner avec la lumière\n");
        pix->comps->v_norm_parral->x *= -1;
        pix->comps->v_norm_parral->y *= -1;
        pix->comps->v_norm_parral->z *= -1;
        n_dot_l = dot_product(pix->comps->v_norm_parral, v_light);
        printf("Produit scalaire corrigé (N · L) : %f\n", n_dot_l);
    }

    // Vérifiez à nouveau si la normale pointe toujours dans la direction correcte
    if (n_dot_l > 0)
    {
        intensity = lux->ratio * n_dot_l;
        printf("Intensité calculée : %f\n", intensity);
    }
    else
        printf("Produit scalaire négatif, aucune contribution lumineuse.\n");

    // Libération de la mémoire pour le vecteur lumière
    free(v_light);

    return (intensity);
}*/

/* 
float 	compute_pointlight(t_pix *pix, t_light *lux)
{
	t_coord *v_light;
	float n_dot_l;
	float i;

	i = 0.0;
	v_light = substraction(lux->p_coord, pix->comps->p_touch);
	n_dot_l =  dot_product(pix->comps->v_norm_parral, v_light);
	if (n_dot_l > 0) 
		i = -lux->ratio * n_dot_l/((length_vector(pix->comps->v_norm_parral) * length_vector(v_light)));
	i = lux->ratio * n_dot_l/((length_vector(pix->comps->v_norm_parral) * length_vector(v_light)));
	free (v_light);
	return (i);
} */

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

float light_intensity(t_pix *pix)
{
	float intensity;
	int i;

	intensity = 0.0;

	// Lumière ambiante
	intensity += compute_ambient(pix);

	// Lumières ponctuelles
	i = 0;
	while (pix->lux[1][i] != NULL) // Parcourt toutes les lumières ponctuelles
	{
		//if (!is_in_shadow(pix->comps->p_touch, pix->lux[1][i], pix->obj))
		if (pix->comps->t_count > 0)
		{
			intensity += compute_pointlight(pix, pix->lux[1][i]);
		}	
		i++;
	}

	return (intensity);
}

//ok
float 	compute_ambient(t_pix *pix)
{
	float i;

	i = pix->lux[0][0]->ratio;
	return (i);
}

