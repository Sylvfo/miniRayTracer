/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_light_shadow_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:44:59 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 11:31:42 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	new_light(t_pix ***pix)
{
	int	x;
	int	y;
	float intensity;

	intensity = 0.0;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			intensity = light_intensity(pix[x][y]);
			pix[x][y]->color->r = pix[x][y]->comps->obj_color->r;
			pix[x][y]->color->g = pix[x][y]->comps->obj_color->g;
			pix[x][y]->color->b = pix[x][y]->comps->obj_color->b;
			scalar_mult_color(pix[x][y]->color, intensity);
			y++;
		}
		x++;
	}
}

float	light_intensity(t_pix *pix)
{
	float intensity;
	int i;

	intensity = 0.0;
	intensity += pix->lux[0][0]->ratio;

	i = 0;
    while (pix->lux[1][i] != NULL)
	{
 		if (pix->comps->type == SPHERE || pix->comps->type == PLAN || pix->comps->type == CYLINDER)
		{
			prepare_v_light(pix, i);
			if (intersect_objects_shadow(pix, i) == false)
			{
				intensity = intensity + compute_pointlight(pix, pix->lux[1][i]);
				intensity = intensity + compute_specular(pix, pix->lux[1][i]);
			}
		}
        i++;
	}
    return (intensity);
}