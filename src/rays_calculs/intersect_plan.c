/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:04:59 by syl               #+#    #+#             */
/*   Updated: 2025/04/19 10:43:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
1 ray  parralèlle plan -> no intersection
2 ray coplanar to plan -> no intersection
3 ray origin above the plan
4 ray origin below the plan
*/

//intersect scaled plan
void intersect_plan(t_pix *pix, int plan_num)
{
	//empty set, no intersection
	// fabs mets tous les nombres en positif
	if (fabs(pix->hits[2][plan_num]->r_dir->y) < EPSILON)
	{
		pix->hits[2][plan_num]->t_count = 0;
		pix->hits[2][plan_num]->t1 = 0;
		pix->hits[2][plan_num]->t2 = 0;
		return ;
	}
	//origin.y + t * dir.y = 0 c est l équation de l intersection entre le plan et le ray
	pix->hits[2][plan_num]->t1 = -(pix->hits[2][plan_num]->r_origin->y / pix->hits[2][plan_num]->r_dir->y);
	pix->hits[2][plan_num]->t_count = 1;
	pix->hits[2][plan_num]->obj_type = PLAN;
}
