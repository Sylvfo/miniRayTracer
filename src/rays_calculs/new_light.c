/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/04/18 17:18:50 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//1
void	new_light(t_pix ***pix)
{
	int	x;
	int	y;
	float intensity;


	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			intensity = light_intensity(pix[x][y]);
			pix[x][y]->color->r = pix[x][y]->comps->obj_color->r;
			pix[x][y]->color->g = pix[x][y]->comps->obj_color->g;
			pix[x][y]->color->b = pix[x][y]->comps->obj_color->b;
			scalar_mult_color(pix[x][y]->color, intensity);
			y++;
		}
		x++;
	}
}

//2
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
 		if (pix->comps->obj_type != NONE)
		{
			if (intersect_objects_shadow(pix, i) == true)
			{
				printf("a");
				return intensity;
			}
			intensity += compute_pointlight(pix, pix->lux[1][i]);
		//	intensity += compute_specular(pix, pix->lux[1][0]);
		}
        i++;
	}
    return (intensity);
}

float compute_pointlight(t_pix *pix, t_light *lux)
{
    t_coord *v_light;
    float n_dot_l;
    float intensity;

	intensity = 0.0;
    // Vérifier si le point d'intersection est dans l'ombre pour cette lumière
//    if (is_in_shadow(pix->comps->p_touch, lux, pix->obj))
//		return 0.0;
/*	if (intersect_objects_shadow(pix) == true)
	{
		printf("i");
		return 0.0;
	}	*/
    
//	printf(".");
    v_light = substraction(lux->p_world, pix->comps->p_touch);
    v_light = normalize_vector(v_light);
    n_dot_l = dot_product(pix->comps->v_norm_parral, v_light);
    if (n_dot_l > 0)
    {
        intensity = lux->ratio * n_dot_l;// /
                   // (length_vector(pix->comps->v_norm_parral) * length_vector(v_light));
		//pris de gpt pour calculer l atténuation de la lumière par la distanche...
//	float distance = length_vector(substraction(lux->p_world, pix->comps->p_touch));
//	float attenuation = 1.0 / (1.0 + 0.1 * distance + 0.05 * distance * distance);
//	intensity = lux->ratio * n_dot_l * attenuation;
	}
    free(v_light);
    return intensity;
}



/* avant modif rays. 
bool is_in_shadow(t_coord *point, t_light *light, t_obj ***objects)
{
	t_coord *r_shadow_point;
	t_coord *r_shodow_dir;
	
	t_ray shadow_ray;
	t_hits hits;

	shadow_ray.p_origin = point;
	//syl a modifié light->p_coord par light p_world
	shadow_ray.v_dir = substraction(light->p_world, point);
	//probleme normalize()
	//corr par syl
	shadow_ray.v_dir = normalize_vector(shadow_ray.v_dir);

	hits = intersect_objects(objects, &shadow_ray);
	if (hits.t_count > 0 && hits.t1 > EPSILON)
	{
	//	printf(".");
		return (true); // Le point est dans l'ombre
	}
//	printf("-");
		return (false);
}*/


//5
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
	//ici syl a modifié
	//view_dir = normalize_vector(scalar_mult(pix->comps->v_norm_parral, -1.0));
	view_dir = normalize_vector(substraction(pix->cam->p_coord, pix->comps->p_touch));

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






/*
//2 PLUS UTILISEE
void ComputeLighting(t_pix *pix)
{
	float intensity;

	intensity = light_intensity(pix);
	pix->color->r = pix->comps->obj->color->r;
	pix->color->g = pix->comps->obj->color->g;
	pix->color->b = pix->comps->obj->color->b;
	scalar_mult_color(pix->color, intensity);
	
	//scalar_mult_color(pix->color, intensity);
}*/


/*
pas utilisée?
//4
float compute_pointlight(t_pix *pix, t_light *lux)
{
	t_coord *v_light;
	float n_dot_l;
	float intensity;

    // Vérifier si le point d'intersection est dans l'ombre pour cette lumière
	if (is_in_shadow(pix->comps->p_touch, lux, pix->obj))
		return 0.0;
	intensity = 0.0;
	// Calcul du vecteur lumière (L)
	v_light = substraction(pix->comps->p_touch, lux->p_world);
	//v_light = substraction(lux->p_world, pix->comps->p_touch);
//	printf("Vecteur lumière (L) : x = %f, y = %f, z = %f\n", v_light->x, v_light->y, v_light->z);
	// Normalisation des vecteurs
	v_light = normalize_vector(v_light);
//	printf("Vecteur lumière (L) normalisé : x = %f, y = %f, z = %f\n",
//		v_light->x, v_light->y, v_light->z);
	// Calcul du produit scalaire entre la normale (N) et le vecteur lumière (L)
	n_dot_l = dot_product(pix->comps->v_norm_parral, v_light);
//	printf("Produit scalaire (N . L) : %f\n", n_dot_l);
	// Vérification si le produit scalaire est positif
	if (n_dot_l > 0)
	{
	//	printf("dot = %.3f\n", n_dot_l);
		intensity = lux->ratio * n_dot_l / (length_vector(pix->comps->v_norm_parral) * length_vector(v_light));
		
//		//pris de gpt pour calculer l atténuation de la lumière par la distanche...
	//	float distance = length_vector(substraction(lux->p_world, pix->comps->p_touch));
	//	float attenuation = 1.0 / (1.0 + 0.1 * distance + 0.05 * distance * distance);
	//	intensity = lux->ratio * n_dot_l * attenuation;
		//	printf("Intensité calculée : %f\n", intensity)
	}
//	else
//		printf("Produit scalaire négatif, aucune contribution lumineuse.\n");
	// Libération de la mémoire pour le vecteur lumière
	free(v_light);
	return (intensity);
}*/
    