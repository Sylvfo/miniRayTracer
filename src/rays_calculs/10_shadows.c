/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/13 15:53:45 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	prepare_v_light(t_pix *pix, int lux_num)
{
	t_coord	offset_point;
	t_coord	tmp;

	scalar_mult_na(&tmp, pix->comps->v_norm_parral, EPSILON * 100);
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

bool	intersect_sphere_shadow(t_pix *pix, int sphere_num, int lux_num)
{
	float	coeffs[3];
	float	discriminant;
	float	roots[2];
	float	sqrt_discr;

	substraction_p_to_v_na(pix->comps->v_sphere_to_point, pix->comps->p_touch,
		pix->obj[1][sphere_num]->p_coord);
	coeffs[0] = dot_product(pix->comps->v_light_to_point,
			pix->comps->v_light_to_point);
	coeffs[1] = 2.0f * dot_product(pix->comps->v_sphere_to_point,
			pix->comps->v_light_to_point);
	coeffs[2] = dot_product(pix->comps->v_sphere_to_point,
			pix->comps->v_sphere_to_point) - (pix->obj[1][sphere_num]->radius
			* pix->obj[1][sphere_num]->radius);
	discriminant = coeffs[1] * coeffs[1] - 4.0f * coeffs[0] * coeffs[2];
	if (discriminant < 0.0f)
		return (false);
	sqrt_discr = sqrtf(discriminant);
	roots[0] = (-coeffs[1] - sqrt_discr) / (2.0f * coeffs[0]);
	roots[1] = (-coeffs[1] + sqrt_discr) / (2.0f * coeffs[0]);
	if ((roots[0] > EPSILON && roots[0] < pix->comps->distance_light_p_touch)
		|| (roots[1] > EPSILON
			&& roots[1] < pix->comps->distance_light_p_touch))
		return (true);
	return (false);
}

bool	intersect_plan_shadow(t_pix *pix, int pln_num, int lux_num)
{
	t_coord	p0_minus_p;
	float	denom;
	float	t;

	denom = dot_product(pix->obj[2][pln_num]->v_axe,
			pix->comps->v_light_to_point);
	if (fabs(denom) < EPSILON)
		return (false);
	p0_minus_p.x = pix->obj[2][pln_num]->p_coord->x - pix->comps->p_touch->x;
	p0_minus_p.y = pix->obj[2][pln_num]->p_coord->y - pix->comps->p_touch->y;
	p0_minus_p.z = pix->obj[2][pln_num]->p_coord->z - pix->comps->p_touch->z;
	t = dot_product(pix->obj[2][pln_num]->v_axe, &p0_minus_p) / denom;
	if (t > EPSILON && t < pix->comps->distance_light_p_touch)
		return (true);
	return (false);
}

bool	intersect_cylinder_shadow(t_pix *pix, int cyl_num, int lux_num)
{
	(void)pix;
	(void)cyl_num;
	(void)lux_num;
	return (false);
}
