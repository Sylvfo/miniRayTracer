/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:46:14 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 11:44:56 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static bool	check_shadow_cyl_body_t(float t, t_coord *s_o_local,
	t_coord *s_d_local, float max_dist)
{
	float	y_intersect;

	if (t > EPSILON && t < max_dist)
	{
		y_intersect = s_o_local->y + t * s_d_local->y;
		if (y_intersect >= -1.0f && y_intersect <= 1.0f)
			return (true);
	}
	return (false);
}

static bool	check_shadow_cyl_cap_t(float t, t_coord *s_o_local,
	t_coord *s_d_local, float max_dist)
{
	float	x_cap;
	float	z_cap;

	if (t > EPSILON && t < max_dist)
	{
		x_cap = s_o_local->x + t * s_d_local->x;
		z_cap = s_o_local->z + t * s_d_local->z;
		if (x_cap * x_cap + z_cap * z_cap <= 1.0f + EPSILON)
			return (true);
	}
	return (false);
}

static bool	intersect_cyl_body_shadow_calc(t_coord *s_o_l, t_coord *s_d_l,
	float max_d, t_obj *cyl)
{
	float	coeffs[3];
	float	dsc;
	float	sqrt_dsc;
	float	t1;
	float	t2;

	coeffs[0] = s_d_l->x * s_d_l->x + s_d_l->z * s_d_l->z;
	if (fabs(coeffs[0]) < EPSILON)
		return (false);
	coeffs[1] = 2.0f * (s_o_l->x * s_d_l->x + s_o_l->z * s_d_l->z);
	coeffs[2] = s_o_l->x * s_o_l->x + s_o_l->z * s_o_l->z - 1.0f;
	dsc = coeffs[1] * coeffs[1] - 4.0f * coeffs[0] * coeffs[2];
	if (dsc < 0.0f)
		return (false);
	sqrt_dsc = simple_sqrt(dsc);
	t1 = (-coeffs[1] - sqrt_dsc) / (2.0f * coeffs[0]);
	if (check_shadow_cyl_body_t(t1, s_o_l, s_d_l, max_d))
		return (true);
	t2 = (-coeffs[1] + sqrt_dsc) / (2.0f * coeffs[0]);
	if (check_shadow_cyl_body_t(t2, s_o_l, s_d_l, max_d))
		return (true);
	(void)cyl;
	return (false);
}

static bool	intersect_cyl_caps_shadow_calc(t_coord *s_o_l, t_coord *s_d_l,
	float max_d, t_obj *cyl)
{
	float	t;

	if (fabs(s_d_l->y) < EPSILON)
		return (false);
	if (cyl->closed_down)
	{
		t = (-1.0f - s_o_l->y) / s_d_l->y;
		if (check_shadow_cyl_cap_t(t, s_o_l, s_d_l, max_d))
			return (true);
	}
	if (cyl->closed_up)
	{
		t = (1.0f - s_o_l->y) / s_d_l->y;
		if (check_shadow_cyl_cap_t(t, s_o_l, s_d_l, max_d))
			return (true);
	}
	return (false);
}

bool	intersect_cylinder_shadow(t_pix *pix, int cyl_num, int lux_num)
{
	t_obj	*cylinder;
	t_coord	s_o_world;
	t_coord	s_o_local;
	t_coord	s_d_local;
	t_coord	temp_s_d_transform;

	(void)lux_num;
	cylinder = pix->obj[CYLINDER][cyl_num];
	scalar_mult_na(&s_o_world, pix->comps->v_norm_parral, EPSILON * 10.0f);
	addition_na(&s_o_world, pix->comps->p_touch, &s_o_world);
	matrix_point_multiplication_new(&s_o_local, cylinder->m_inv, &s_o_world);
	copy_coord(&temp_s_d_transform, pix->comps->v_light_to_point);
	temp_s_d_transform.t = 0;
	matrix_point_multiplication_new(&s_d_local, cylinder->m_inv,
		&temp_s_d_transform);
	normalize_vector_na(&s_d_local);
	if (intersect_cyl_body_shadow_calc(&s_o_local, &s_d_local,
			pix->comps->distance_light_p_touch, cylinder))
		return (true);
	if (intersect_cyl_caps_shadow_calc(&s_o_local, &s_d_local,
			pix->comps->distance_light_p_touch, cylinder))
		return (true);
	return (false);
}
