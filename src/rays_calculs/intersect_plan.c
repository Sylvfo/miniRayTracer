/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:04:59 by syl               #+#    #+#             */
/*   Updated: 2025/04/10 15:09:36 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
1 ray  parralèlle plan -> no intersection
2 ray coplanar to plan -> no intersection
3 ray origin above the plan
4 ray origin below the plan
*/
void intersect_plan(t_pix *pix, int plan_num)
{
	//empty set, no intersection
	if (fabs(pix->hits[2][plan_num]->r_ray_calculs->v_dir->y) < EPSILON)
	{
		pix->hits[2][plan_num]->t_count = 0;
		pix->hits[2][plan_num]->t1 = 0;
		pix->hits[2][plan_num]->t2 = 0;
	}
	pix->hits[2][plan_num]->t1 = -(pix->hits[2][plan_num]->r_ray_calculs->p_origin->y / pix->hits[2][plan_num]->r_ray_calculs->v_dir->y);
	pix->hits[2][plan_num]->t_count = 0;
}

/*
FROM OLD BOOK
void intersectrayplane(t_pix *pix, t_plane *plane)
{
	float DdotN;
	float t;

	DdotN = dot_product(pix->D, plane->normal);
	if (DdotN == 0.0)
		return ;//false??

	t = dot_product(substraction_point(plane->point, pix->global->cam), plane->normal) / DdotN;
//	if (t <= RAY_T_MIN || t >= pix->t1);
//	{
//	//	pix->color = 0x62414e;
//		return;
//	}
	pix->t1 = t;
//	pix->color = plane->color;
//	return (true)
}

	// CO = O - sphere.center  do product of the ray with himself
	// Dot Product: The dot product of a vector with itself is computed by 
	//⟨P−C,P−C⟩=(Px−Cx)2+(Py−Cy)2+(Pz−Cz)2⟨P−C,P−C⟩
	// Square of rr: The right-hand side of the equation is r2r2, which is just a scalar valu

*/