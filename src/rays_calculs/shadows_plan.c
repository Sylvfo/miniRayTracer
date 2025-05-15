/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_plan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:45:34 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 10:46:01 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	intersect_plan_shadow(t_pix *pix, int pln_num, int lux_num)
{
	t_coord	p0_minus_p;
	float	denom;
	float	t;
	t_obj	*plan;

	(void)lux_num;
	plan = pix->obj[PLAN][pln_num];
	denom = dot_product(plan->v_axe, pix->comps->v_light_to_point);
	if (fabs(denom) < EPSILON)
		return (false);
	p0_minus_p.x = plan->p_coord->x - pix->comps->p_touch->x;
	p0_minus_p.y = plan->p_coord->y - pix->comps->p_touch->y;
	p0_minus_p.z = plan->p_coord->z - pix->comps->p_touch->z;
	t = dot_product(plan->v_axe, &p0_minus_p) / denom;
	if (t > EPSILON && t < pix->comps->distance_light_p_touch)
		return (true);
	return (false);
}
