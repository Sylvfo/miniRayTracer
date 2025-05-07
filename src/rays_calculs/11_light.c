/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 10:51:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float compute_pointlight(t_pix *pix, t_light *lux)
{
    float n_dot_l;
    float intensity;
    float distance;
    float attenuation;

	if (pix->comps->p_touch->x == 0 && pix->comps->p_touch->y == 0 && pix->comps->p_touch->z == 0)
		printf("no p touch\n");
	intensity = 0.0;
  	substraction_p_to_v_NA(pix->comps->v_point_to_light, lux->p_coord, pix->comps->p_touch);
	normalize_vector_NA(pix->comps->v_point_to_light);
	n_dot_l = dot_product(pix->comps->v_norm_parral, pix->comps->v_point_to_light);
    if (n_dot_l > 0)
    {
	/*	distance = length_vector(pix->comps->v_point_to_light);
        // attenuation douce pour éviter de "couper" la lumière trop vite
		//BONUS??
        attenuation = 1.0;// / (1.0 + 0.1 * distance + 0.05 * distance * distance);
        intensity = lux->ratio * n_dot_l * attenuation;*/

		//celui ci normalement
		intensity = lux->ratio * n_dot_l;// /
	}
    return intensity;
}

//5
float	compute_specular(t_pix *pix, t_light *lux)
{
	float	specular_intensity;
	float	reflect_dot_view;
	float	dot_p;

	specular_intensity = 0.0;
	dot_p = dot_product(pix->comps->v_norm_parral,pix->comps->v_light_to_point);
	scalar_mult_NA(pix->comps->scalar, pix->comps->v_norm_parral,2.0 * dot_p);
	substraction_p_to_v_NA(pix->comps->reflect_dir,  pix->comps->scalar, pix->comps->v_light_to_point);
	normalize_vector_NA(pix->comps->reflect_dir);
	//ici syl a modifié
	//view_dir = normalize_vector(scalar_mult(pix->comps->v_norm_parral, -1.0));
	substraction_p_to_v_NA(pix->comps->view_dir, pix->cam->p_coord, pix->comps->p_touch);
	normalize_vector_NA(pix->comps->view_dir);
	
	reflect_dot_view = dot_product(pix->comps->reflect_dir, pix->comps->view_dir);
	if (reflect_dot_view > 0)
	{
		specular_intensity = lux->ratio * pow(reflect_dot_view, SHININESS) * 0.5;
	}
	return (specular_intensity);
}

    