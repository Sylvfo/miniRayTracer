/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_old.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/04/19 16:12:41 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// EFFACE PAS TOUT DE SUITE... C EST CE QUE TU AVAIS FAIT
/*
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
			//scalar_mult_color(pix[x][y]->comps->obj->color, intensity);
			scalar_mult_color(pix[x][y]->color, intensity);
			//ComputeLighting(pix[x][y]);
			y++;
		}
		x++;
	}
}*/

/*
bool is_in_shadow(t_coord *point, t_light *light, t_obj ***objects)
{
	// pix->comps->p_touch = point
	t_coord *r_shadow_point;
	t_coord *r_shodow_dir;
	
	t_ray shadow_ray;
	t_hits hits;

	shadow_ray.p_origin = point;
	//syl a modifié light->p_coord par light p_world
	//idme v_light?
	shadow_ray.v_dir = substraction(light->p_world, point);
	//probleme normalize()
	//corr par syl
	shadow_ray.v_dir = normalize_vector(shadow_ray.v_dir);
//
	hits = intersect_objects(objects, &shadow_ray);
	if (hits.t_count > 0 && hits.t1 > EPSILON)
	{
	//	printf(".");
		return (true); // Le point est dans l'ombre
	}
//	printf("-");
		return (false);
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
}

//RENOMMER
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
}*/ 


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