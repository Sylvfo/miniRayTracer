/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/14 23:19:15 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	cut_cylinder_shad(t_pix *pix, int cyl_n, float t1, float t2);

// Helper function to check if a 't' value for cylinder body shadow is valid
static bool check_shadow_cyl_body_t(float t, t_coord *s_o_local, t_coord *s_d_local, float max_dist)
{
	if (t > EPSILON && t < max_dist)
	{
		float y_intersect = s_o_local->y + t * s_d_local->y;
		if (y_intersect >= -1.0f && y_intersect <= 1.0f)
			return (true);
	}
	return (false);
}

// Helper function to check if a 't' value for cylinder cap shadow is valid
static bool check_shadow_cyl_cap_t(float t, t_coord *s_o_local, t_coord *s_d_local, float max_dist)
{
	if (t > EPSILON && t < max_dist)
	{
		float x_cap = s_o_local->x + t * s_d_local->x;
		float z_cap = s_o_local->z + t * s_d_local->z;
		if (x_cap * x_cap + z_cap * z_cap <= 1.0f)
			return (true);
	}
	return (false);
}

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
	t_coord	s_o_world;
	t_coord	s_d_world;
	t_coord	s_o_local;
	t_coord	s_d_local;
	t_obj	*cylinder = pix->obj[CYLINDER][cyl_num];
	float	a, b, c, discriminant, sqrt_d, t1, t2;

	(void)lux_num;

	scalar_mult_na(&s_o_world, pix->comps->v_norm_parral, EPSILON * 10.0f);
	addition_na(&s_o_world, pix->comps->p_touch, &s_o_world);
	copy_coord(&s_d_world, pix->comps->v_light_to_point);

	matrix_point_multiplication_new(&s_o_local, cylinder->m_inv, &s_o_world);
	t_coord temp_s_d_world;
	copy_coord(&temp_s_d_world, &s_d_world);
	temp_s_d_world.t = 0;
	matrix_point_multiplication_new(&s_d_local, cylinder->m_inv, &temp_s_d_world);
	normalize_vector_na(&s_d_local);

	a = s_d_local.x * s_d_local.x + s_d_local.z * s_d_local.z;
	if (fabs(a) > EPSILON)
	{
		b = 2.0f * (s_o_local.x * s_d_local.x + s_o_local.z * s_d_local.z);
		c = s_o_local.x * s_o_local.x + s_o_local.z * s_o_local.z - 1.0f;
		discriminant = b * b - 4.0f * a * c;
		if (discriminant >= 0.0f)
		{
			sqrt_d = simple_sqrt(discriminant);
			t1 = (-b - sqrt_d) / (2.0f * a);
			if (check_shadow_cyl_body_t(t1, &s_o_local, &s_d_local, pix->comps->distance_light_p_touch))
				return (true);
			t2 = (-b + sqrt_d) / (2.0f * a);
			if (check_shadow_cyl_body_t(t2, &s_o_local, &s_d_local, pix->comps->distance_light_p_touch))
				return (true);
		}
	}

	if (fabs(s_d_local.y) > EPSILON)
	{
		t1 = (-1.0f - s_o_local.y) / s_d_local.y;
		if (check_shadow_cyl_cap_t(t1, &s_o_local, &s_d_local, pix->comps->distance_light_p_touch))
			return (true);

		t2 = (1.0f - s_o_local.y) / s_d_local.y;
		if (check_shadow_cyl_cap_t(t2, &s_o_local, &s_d_local, pix->comps->distance_light_p_touch))
			return (true);
	}
	return (false);
}

bool	cut_cylinder_shad(t_pix *pix, int cyl_n, float t1, float t2)
{
	float	y1;
	float	y2;
	float	tmp;

	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	y1 = pix->hits[3][cyl_n]->r_origin->y + t1 * pix->hits[3][cyl_n]->r_dir->y;
	if (-pix->obj[3][cyl_n]->height / 2 < y1 && y1 < pix->obj[3][cyl_n]->height / 2)
	{
		return (true);
	}
	y2 = pix->hits[3][cyl_n]->r_origin->y + t2 * pix->hits[3][cyl_n]->r_dir->y;
	if (-pix->obj[3][cyl_n]->height / 2 < y2 && y2 < pix->obj[3][cyl_n]->height / 2)
	{
		return (true);
	}
	return (false);
}