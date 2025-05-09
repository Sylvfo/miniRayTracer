/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_attenuation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:45:33 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 14:46:00 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
float	compute_pointlight(t_pix *pix, t_light *lux)
{
    float	n_dot_l;
    float	intensity;
    float	distance;
    float	attenuation;

	if (pix->comps->p_touch->x == 0 && pix->comps->p_touch->y == 0 && pix->comps->p_touch->z == 0)
		printf("no p touch\n");
	intensity = 0.0;
  	substraction_p_to_v_NA(pix->comps->v_point_to_light, lux->p_coord, pix->comps->p_touch);
	normalize_vector_NA(pix->comps->v_point_to_light);
	n_dot_l = dot_product(pix->comps->v_norm_parral, pix->comps->v_point_to_light);
    if (n_dot_l > 0)
    {
		distance = length_vector(pix->comps->v_point_to_light);
        // attenuation douce pour éviter de "couper" la lumière trop vite
		//BONUS??
        attenuation = 1.0;// / (1.0 + 0.1 * distance + 0.05 * distance * distance);
        intensity = lux->ratio * n_dot_l * attenuation;

		//celui ci normalement
		//intensity = lux->ratio * n_dot_l;// /
	}
    return intensity;
}*/