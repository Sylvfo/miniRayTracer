/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_light_shadow_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:44:59 by syl               #+#    #+#             */
/*   Updated: 2025/05/15 11:24:37 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	light_intensity(t_pix *pix)
{
	float	intensity;
	int		i;

	intensity = 0.0;
	intensity += pix->lux[0][0]->ratio;
	pix->comps->obj_color->r *= pix->lux[0][0]->color->r / 255.0;
	pix->comps->obj_color->g *= pix->lux[0][0]->color->g / 255.0;
	pix->comps->obj_color->b *= pix->lux[0][0]->color->b / 255.0;
	i = 0;
	while (pix->lux[1][i] != NULL)
	{
		if (pix->comps->type == SPHERE || pix->comps->type == PLAN
			|| pix->comps->type == CYLINDER)
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

void	new_light(t_pix ***pix)
{
	int		x;
	int		y;
	float	intensity;

	intensity = 1;
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
			if (pix[x][y]->comps->type == SPHERE ||
				pix[x][y]->comps->type == PLAN ||
				pix[x][y]->comps->type == CYLINDER)
				scalar_mult_color(pix[x][y]->color, intensity);
		//	pix[x][y]->color->r = (pix[x][y]->comps->v_norm_parral->x + 1) * 0.5 * 255;
		//	pix[x][y]->color->g = (pix[x][y]->comps->v_norm_parral->y + 1) * 0.5 * 255;
		//	pix[x][y]->color->b = (pix[x][y]->comps->v_norm_parral->z + 1) * 0.5 * 255;

			y++;
		}
		x++;
	}
}
