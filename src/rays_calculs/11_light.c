/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/05/11 21:00:00 by you             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	compute_pointlight(t_pix *pix, t_light *lux)
{
	float	n_dot_l;
	float	intensity;

	intensity = 0.0f;
	substraction_p_to_v_na(pix->comps->v_point_to_light, lux->p_coord,
		pix->comps->p_touch);

	normalize_vector_na(pix->comps->v_point_to_light);
	fabs(pix->comps->v_point_to_light->x);
	fabs(pix->comps->v_point_to_light->y);
	fabs(pix->comps->v_point_to_light->z);
	n_dot_l = dot_product(pix->comps->v_norm_parral,
			pix->comps->v_point_to_light);
	if (n_dot_l > 0.0f)
		intensity = lux->ratio * n_dot_l;

	//return (0.5);
	return (intensity);

}

float	compute_specular(t_pix *pix, t_light *lux)
{
	float	specular_intensity;
	float	reflect_dot_view;
	float	dot_p;
	float	power_term;

	specular_intensity = 0.0f;
	dot_p = dot_product(pix->comps->v_norm_parral,
			pix->comps->v_light_to_point);
	scalar_mult_na(pix->comps->scalar, pix->comps->v_norm_parral, 2.0f * dot_p);
	substraction_p_to_v_na(pix->comps->reflect_dir, pix->comps->scalar,
		pix->comps->v_light_to_point);
	normalize_vector_na(pix->comps->reflect_dir);
	substraction_p_to_v_na(pix->comps->view_dir, pix->cam->p_coord,
		pix->comps->p_touch);
	normalize_vector_na(pix->comps->view_dir);
	reflect_dot_view = dot_product(pix->comps->reflect_dir,
			pix->comps->view_dir);
	if (reflect_dot_view > 0.0f)
	{
		power_term = powf(reflect_dot_view, SHININESS);
		specular_intensity = lux->ratio * power_term * 0.5f;
	}
	return (specular_intensity);
}
