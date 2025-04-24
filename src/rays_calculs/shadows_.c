/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/04/24 11:35:20 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
	substraction_p_to_v_NA(pix->comps->v_sphere_to_point, pix->comps->p_touch, pix->obj[1][sphere_num]->p_world);
	float a = dot_product(pix->comps->v_light_to_point, pix->comps->v_light_to_point);
	float b = 2.0f * dot_product(pix->comps->v_sphere_to_point, pix->comps->v_light_to_point);
	float c = dot_product(pix->comps->v_sphere_to_point, pix->comps->v_sphere_to_point) - pix->obj[1][sphere_num]->radius * pix->obj[1][sphere_num]->radius;			 
    float discriminant = b*b - 4*a*c;
    if (discriminant < 0)
		return false;
    float sqrt_discr = sqrtf(discriminant);
    float t1 = (-b - sqrt_discr) / (2*a);
    float t2 = (-b + sqrt_discr) / (2*a);
	return ((t1 > EPSILON && t1 < pix->comps->distance_light_p_touch) || 
			(t2 > EPSILON && t2 < pix->comps->distance_light_p_touch));
}

/*
bool intersect_plan_shadow(t_pix *pix, int pln_num, int lux_num)
{
	if (fabs(pix->hits[2][plan_num]->r_dir->y) < EPSILON)
	{
		pix->hits[2][plan_num]->t_count = 0;
		pix->hits[2][plan_num]->t1 = 0;
		pix->hits[2][plan_num]->t2 = 0;
		return ;
	}
}

bool intersect_cylinder_shadow(t_pix *pix, int pln_num, int lux_num)
{
	
}*/