/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/04/04 11:57:07 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	new_light(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			ComputeLighting(pix[x][y]);
			y++;
		}
		x++;
	}
}

void ComputeLighting(t_pix *pix)
{
//	pix->comps->p_point = P
//	pix->comps->v_norm_parral = N // A normé??

	float intensity;

	intensity = light_intensity(pix);
	scalar_mult_color(pix->color, intensity);
}

float 	compute_pointlight(t_pix *pix, t_light *lux)
{
	t_coord *v_light;
	float n_dot_l;
	float intensity;

	intensity = 0.0;
	// Calcul du vecteur lumière (L)
	v_light = substraction(lux->p_coord, pix->comps->p_point);

	// Calcul du produit scalaire entre la normal (N) et le vecteur lumière (L)
	n_dot_l =  dot_product(pix->comps->v_norm_parral, v_light);

	if (n_dot_l > 0)
		intensity = lux->ratio * n_dot_l / (length_vector(pix->comps->v_norm_parral) * length_vector(v_light));

	free (v_light);
	return (intensity);
}
/* 
float 	compute_pointlight(t_pix *pix, t_light *lux)
{
	t_coord *v_light;
	float n_dot_l;
	float i;

	i = 0.0;
	v_light = substraction(lux->p_coord, pix->comps->p_point);
	n_dot_l =  dot_product(pix->comps->v_norm_parral, v_light);
	if (n_dot_l > 0) 
		i = -lux->ratio * n_dot_l/((length_vector(pix->comps->v_norm_parral) * length_vector(v_light)));
	i = lux->ratio * n_dot_l/((length_vector(pix->comps->v_norm_parral) * length_vector(v_light)));
	free (v_light);
	return (i);
} */

float light_intensity(t_pix *pix)//rajouter plusieurs lampes
{
	float i;
	float n_dot_l;

	i = 0.0;
//	i += compute_ambient(pix);// ok
	//boucle while pour toutes les lumières
	i += compute_pointlight(pix, pix->lux[1][0]);
	
//	i += computre_directionlight 
	return (i);
}

//ok
float 	compute_ambient(t_pix *pix)
{
	float i;

	i = pix->lux[0][0]->ratio;
	return (i);
}