/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 10:01:40 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//1
void	new_light(t_pix ***pix)
{
	int	x;
	int	y;
	float intensity;

	intensity = 0.0;
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
	intensity += pix->lux[0][0]->ratio;

//	intensity = 0.8;
	// Lumières ponctuelles
	i = 0;
    while (pix->lux[1][i] != NULL)// && i < 2)
	{
 		if (pix->comps->obj_type == SPHERE || pix->comps->obj_type == PLAN || pix->comps->obj_type == CYLINDER)
		{
			prepare_v_light(pix, i);
			if (intersect_objects_shadow(pix, i) == false)
			{
				intensity = intensity + compute_pointlight(pix, pix->lux[1][i]);
				intensity = intensity + compute_specular(pix, pix->lux[1][i]);
			}
		}
        i++;
	}
    return (intensity);
}

float compute_pointlight(t_pix *pix, t_light *lux)
{
    float n_dot_l;
    float intensity;
    float distance;
    float attenuation;

	if (pix->comps->p_touch->x == 0 && pix->comps->p_touch->y == 0 && pix->comps->p_touch->z == 0)
		printf("no p touch\n");
	intensity = 0.0;
  	substraction_p_to_v_NA(pix->comps->v_point_to_light, lux->p_coord, pix->comps->p_touch);
	normalize_vector_NA(pix->comps->v_point_to_light);
	n_dot_l = dot_product(pix->comps->v_norm_parral, pix->comps->v_point_to_light);
    if (n_dot_l > 0)
    {
	/*	distance = length_vector(pix->comps->v_point_to_light);
        // attenuation douce pour éviter de "couper" la lumière trop vite
		//BONUS??
        attenuation = 1.0;// / (1.0 + 0.1 * distance + 0.05 * distance * distance);
        intensity = lux->ratio * n_dot_l * attenuation;*/

		//celui ci normalement
		intensity = lux->ratio * n_dot_l;// /
	}
    return intensity;
}


//5
float	compute_specular(t_pix *pix, t_light *lux)
{
	float	specular_intensity;
	float	reflect_dot_view;
	float	dot_p;

	specular_intensity = 0.0;
	dot_p = dot_product(pix->comps->v_norm_parral,pix->comps->v_light_to_point);
	scalar_mult_NA(pix->comps->scalar, pix->comps->v_norm_parral,2.0 * dot_p);
	substraction_p_to_v_NA(pix->comps->reflect_dir,  pix->comps->scalar, pix->comps->v_light_to_point);
	normalize_vector_NA(pix->comps->reflect_dir);
	//ici syl a modifié
	//view_dir = normalize_vector(scalar_mult(pix->comps->v_norm_parral, -1.0));
	substraction_p_to_v_NA(pix->comps->view_dir, pix->cam->p_coord, pix->comps->p_touch);
	normalize_vector_NA(pix->comps->view_dir);
	
	reflect_dot_view = dot_product(pix->comps->reflect_dir, pix->comps->view_dir);
	if (reflect_dot_view > 0)
	{
		specular_intensity = lux->ratio * pow(reflect_dot_view, SHININESS) * 0.5;
	}
	return (specular_intensity);
}









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
    