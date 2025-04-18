/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/04/18 17:31:54 by syl              ###   ########.fr       */
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
/*			else if (a == PLAN)
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
	t_coord *light_to_point;
	float distance_light_p_touch;
	t_coord *light_dir;
	t_coord *sphere_to_point;
	
	//p_coord
//	light_to_point = substraction(pix->lux[1][0]->p_coord, pix->comps->p_touch);
	light_to_point = substraction(pix->lux[1][lux_num]->p_world, pix->comps->p_touch);
	distance_light_p_touch = length_vector(light_to_point);
	light_dir = normalize_vector(light_to_point);
    float radius = pix->obj[1][sphere_num]->diam / 2.0f;
	//p_coord ou p_world???
//	sphere_to_point = substraction(pix->comps->p_touch, pix->obj[1][sphere_num]->p_coord);
	sphere_to_point = substraction(pix->comps->p_touch, pix->obj[1][sphere_num]->p_world);
	float a = dot_product(light_dir, light_dir);
	float b = 2.0f * dot_product(sphere_to_point, light_dir);
	float c = dot_product(sphere_to_point, sphere_to_point) - radius * radius;			 
    float discriminant = b*b - 4*a*c;
    if (discriminant < 0)
		return false;
    float sqrt_discr = sqrtf(discriminant);
    float t1 = (-b - sqrt_discr) / (2*a);
    float t2 = (-b + sqrt_discr) / (2*a);
    return ((t1 > EPSILON && t1 < distance_light_p_touch) || 
           (t2 > EPSILON && t2 < distance_light_p_touch));
}
/*
bool intersect_plan_shadow(t_pix *pix, int pln_num, int lux_num)
{
	
}

bool intersect_cylinder_shadow(t_pix *pix, int pln_num, int lux_num)
{
	
}*/