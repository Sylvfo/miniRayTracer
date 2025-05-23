/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/05/10 12:40:05 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	compute_pointlight(t_pix *pix, t_light *lux)
{
	float	n_dot_l;
	float	intensity;

    if (pix->comps->p_touch->x == 0 && pix->comps->p_touch->y == 0 && pix->comps->p_touch->z == 0)
        printf("no p touch\n");
    intensity = 0.0;
    substraction_p_to_v_NA(pix->comps->v_point_to_light, lux->p_coord, pix->comps->p_touch);
    normalize_vector_NA(pix->comps->v_point_to_light);
    n_dot_l = dot_product(pix->comps->v_norm_parral, pix->comps->v_point_to_light);
    // DEBUG : Affiche la normale, la direction vers la lumière, le dot product et la position (après calcul)
    if (pix->comps->type == CYLINDER) {
        printf("[CYLINDER] p_touch=(%.3f,%.3f,%.3f) v_norm=(%.3f,%.3f,%.3f) v_light=(%.3f,%.3f,%.3f) dot=%.3f\n",
            pix->comps->p_touch->x, pix->comps->p_touch->y, pix->comps->p_touch->z,
            pix->comps->v_norm_parral->x, pix->comps->v_norm_parral->y, pix->comps->v_norm_parral->z,
            pix->comps->v_point_to_light->x, pix->comps->v_point_to_light->y, pix->comps->v_point_to_light->z,
            n_dot_l);
    }
    if (n_dot_l > 0)
    {
        intensity = lux->ratio * n_dot_l;
    }
    return intensity;
}

float	compute_specular(t_pix *pix, t_light *lux)
{
	float	specular_intensity;
	float	reflect_dot_view;
	float	dot_p;

	specular_intensity = 0.0;
	dot_p = dot_product(pix->comps->v_norm_parral, pix->comps->v_light_to_point);
	scalar_mult_NA(pix->comps->scalar, pix->comps->v_norm_parral, 2.0 * dot_p);
	substraction_p_to_v_NA(pix->comps->reflect_dir, pix->comps->scalar, pix->comps->v_light_to_point);
	normalize_vector_NA(pix->comps->reflect_dir);
	substraction_p_to_v_NA(pix->comps->view_dir, pix->cam->p_coord, pix->comps->p_touch);
	normalize_vector_NA(pix->comps->view_dir);
	reflect_dot_view = dot_product(pix->comps->reflect_dir, pix->comps->view_dir);
	if (reflect_dot_view > 0)
	{
		specular_intensity = lux->ratio * pow(reflect_dot_view, SHININESS) * 0.5;
	}
	return (specular_intensity);
}
