/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/15 10:44:09 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	prepare_v_light(t_pix *pix, int lux_num)
{
	t_coord	offset_point;
	t_coord	tmp;

	scalar_mult_na(&tmp, pix->comps->v_norm_parral, EPSILON * 10.0f);
	addition_na(&offset_point, pix->comps->p_touch, &tmp);
	substraction_p_to_v_na(pix->comps->v_light_to_point,
		pix->lux[1][lux_num]->p_coord, &offset_point);
	pix->comps->distance_light_p_touch
		= length_vector(pix->comps->v_light_to_point);
	normalize_vector_na(pix->comps->v_light_to_point);
}

bool	intersect_objects_shadow(t_pix *pix, int lux_num)
{
	int		a;
	int		b;
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
			if (in_shadow)
				return (true);
			b++;
		}
		a++;
	}
	return (false);
}
