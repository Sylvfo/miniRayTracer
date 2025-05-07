/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 11:43:05 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// le rayon entre tous les p touch et toutes les lumières
void	prepare_v_light(t_pix *pix, int lux_num)
{
	substraction_p_to_v_NA(pix->comps->v_light_to_point, pix->lux[1][lux_num]->p_coord, pix->comps->p_touch);
	pix->comps->distance_light_p_touch = length_vector(pix->comps->v_light_to_point);
	normalize_vector_NA(pix->comps->v_light_to_point);
}

//main
bool intersect_objects_shadow(t_pix *pix, int lux_num)
{
	int a;
	int b;
	bool	in_shadow;

	in_shadow = false;
	a = 0;
	while (pix->obj[a] != NULL)
	{
		b = 0;
		while (pix->obj[a][b] != NULL) 
		{
			if (a == SPHERE)
				in_shadow = intersect_sphere_shadow(pix, b, lux_num);
	/*		else if (a == PLAN)
				in_shadow = intersect_plan_shadow(pix, b, lux_num);
			else if (a == CYLINDER)
				in_shadow = intersect_cylinder_shadow(pix, b, lux_num);*/
			if (in_shadow == true)
				return (true);
			b++;
		}
		a++;
	}
	return false;
}

bool intersect_sphere_shadow(t_pix *pix, int sphere_num, int lux_num)
{
	float a;
	float b;
	float c;
	float discriminant;
	float sqrt_discr;

	substraction_p_to_v_NA(pix->comps->v_sphere_to_point, pix->comps->p_touch, pix->obj[1][sphere_num]->p_coord);
	a = dot_product(pix->comps->v_light_to_point, pix->comps->v_light_to_point); // a optimiser...
	b = 2.0f * dot_product(pix->comps->v_sphere_to_point, pix->comps->v_light_to_point);
//	c = dot_product(pix->comps->v_sphere_to_point, pix->comps->v_sphere_to_point) - pix->obj[1][sphere_num]->diam / 2 * pix->obj[1][sphere_num]->radius;			 
	c = dot_product(pix->comps->v_sphere_to_point, pix->comps->v_sphere_to_point) - pix->obj[1][sphere_num]->radius * pix->obj[1][sphere_num]->radius;			 
	discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return false;
	sqrt_discr = sqrtf(discriminant);
	float t1 = (-b - sqrt_discr) / (2*a);
	float t2 = (-b + sqrt_discr) / (2*a);
	return ((t1 > EPSILON && t1 < pix->comps->distance_light_p_touch) || 
			(t2 > EPSILON && t2 < pix->comps->distance_light_p_touch));
}


bool intersect_plan_shadow(t_pix *pix, int pln_num, int lux_num)
{
	if (fabs(dot_product(pix->obj[2][pln_num]->v_axe, pix->comps->v_light_to_point)) < EPSILON)
		return false;
	//empty set, no intersection
	// fabs mets tous les nombres en positif
//	if (fabs(pix->obj[2][pln_num]->r_dir->y) < EPSILON)
//		return false;
	//origin.y + t * dir.y = 0 c est l équation de l intersection entre le plan et le ray
	return true;
}

/*
bool intersect_cylinder_shadow(t_pix *pix, int pln_num, int lux_num)
{
	
}*/

/*
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
	// !!!! ICI OBJET PAS DANS ESPACE WORLD
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
}*/