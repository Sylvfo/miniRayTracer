/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/10 12:39:38 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	prepare_v_light(t_pix *pix, int lux_num)
{
	substraction_p_to_v_NA(pix->comps->v_light_to_point, pix->lux[1][lux_num]->p_coord, pix->comps->p_touch);
	pix->comps->distance_light_p_touch = length_vector(pix->comps->v_light_to_point);
	normalize_vector_NA(pix->comps->v_light_to_point);
}

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
			else if (a == PLAN)
				in_shadow = intersect_plan_shadow(pix, b, lux_num);
			else if (a == CYLINDER)
				in_shadow = intersect_cylinder_shadow(pix, b, lux_num);
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
    t_coord *n = pix->obj[2][pln_num]->v_axe;
    t_coord *p0 = pix->obj[2][pln_num]->p_coord;
    t_coord *p = pix->comps->p_touch;
    t_coord *d = pix->comps->v_light_to_point;
    float denom = dot_product(n, d);
    if (fabs(denom) < EPSILON)
        return false; // Rayon parallèle au plan
    t_coord p0_minus_p;
    p0_minus_p.x = p0->x - p->x;
    p0_minus_p.y = p0->y - p->y;
    p0_minus_p.z = p0->z - p->z;
    float t = dot_product(n, &p0_minus_p) / denom;
    if (t > EPSILON && t < pix->comps->distance_light_p_touch)
        return true; // Le plan bloque la lumière
    return false;
}

bool intersect_cylinder_shadow(t_pix *pix, int cyl_num, int lux_num)
{
    return false;
}