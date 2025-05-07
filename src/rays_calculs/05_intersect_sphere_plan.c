/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_intersect_sphere_plan.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:04:59 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 10:34:00 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//intersect scaled plan
void intersect_plan(t_pix *pix, int plan_num)
{
	//empty set, no intersection
	// fabs mets tous les nombres en positif
	if (fabs(pix->hits[2][plan_num]->r_dir->y) < EPSILON)
	{
		pix->hits[2][plan_num]->t_count = 0;
		pix->hits[2][plan_num]->t1 = INT_MAX;
		pix->hits[2][plan_num]->t2 = INT_MAX;
		pix->hits[2][plan_num]->obj_type = PLAN;
		return ;
	}
	//origin.y + t * dir.y = 0 c est l équation de l intersection entre le plan et le ray
	pix->hits[2][plan_num]->t1 = -(pix->hits[2][plan_num]->r_origin->y / pix->hits[2][plan_num]->r_dir->y);
	pix->hits[2][plan_num]->t2 = INT_MAX;
	pix->hits[2][plan_num]->t_count = 1;
	pix->hits[2][plan_num]->obj_type = PLAN;
}

void intersect_sphere(t_pix *pix, int sphere_num)
{
	float discriminant;
	float a;
	float b;
	float c;

	substraction_p_to_v_NA(pix->obj[1][sphere_num]->v_sph_camera, pix->hits[1][sphere_num]->r_origin, pix->cam->p_zero);
	a = dot_product(pix->hits[1][sphere_num]->r_dir, pix->hits[1][sphere_num]->r_dir);
	b = 2 * dot_product(pix->hits[1][sphere_num]->r_dir, pix->obj[1][sphere_num]->v_sph_camera);
	c = dot_product(pix->obj[1][sphere_num]->v_sph_camera, pix->obj[1][sphere_num]->v_sph_camera) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 1e-6) // ca veut dire que l objet ne croise pas le point. 
	{
		pix->hits[1][sphere_num]->t_count = 0;
		pix->hits[1][sphere_num]->t1 = INT_MAX;
		pix->hits[1][sphere_num]->t2 = INT_MAX;
		return;
	}
	pix->hits[1][sphere_num]->t_count = 2;
	pix->hits[1][sphere_num]->t1 = (-b - sqrt(discriminant)) / (2*a);
	pix->hits[1][sphere_num]->t2 = (-b + sqrt(discriminant)) / (2*a);
	pix->hits[1][sphere_num]->obj_type = SPHERE;
	return ;
}

