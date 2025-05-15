/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:45:17 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 10:48:19 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	calculate_shadow_sphere_coeffs(t_pix *pix, t_obj *sphere,
	float *coeffs)
{
	t_coord	sphere_to_point;

	substraction_p_to_v_na(&sphere_to_point, pix->comps->p_touch,
		sphere->p_coord);
	coeffs[0] = dot_product(pix->comps->v_light_to_point,
			pix->comps->v_light_to_point);
	coeffs[1] = 2.0f * dot_product(&sphere_to_point,
			pix->comps->v_light_to_point);
	coeffs[2] = dot_product(&sphere_to_point, &sphere_to_point)
		- (sphere->radius * sphere->radius);
}

static bool	check_shadow_sphere_roots(float discriminant, float *coeffs,
	float max_dist)
{
	float	sqrt_discr;
	float	root1;
	float	root2;

	if (discriminant < 0.0f)
		return (false);
	sqrt_discr = sqrtf(discriminant);
	root1 = (-coeffs[1] - sqrt_discr) / (2.0f * coeffs[0]);
	root2 = (-coeffs[1] + sqrt_discr) / (2.0f * coeffs[0]);
	if ((root1 > EPSILON && root1 < max_dist)
		|| (root2 > EPSILON && root2 < max_dist))
		return (true);
	return (false);
}

bool	intersect_sphere_shadow(t_pix *pix, int sphere_num, int lux_num)
{
	float	coeffs[3];
	float	discriminant;
	t_obj	*sphere;

	(void)lux_num;
	sphere = pix->obj[SPHERE][sphere_num];
	calculate_shadow_sphere_coeffs(pix, sphere, coeffs);
	discriminant = coeffs[1] * coeffs[1] - 4.0f * coeffs[0] * coeffs[2];
	return (check_shadow_sphere_roots(discriminant, coeffs,
			pix->comps->distance_light_p_touch));
}
