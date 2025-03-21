/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:27:28 by syl               #+#    #+#             */
/*   Updated: 2025/03/21 11:19:44 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static float clamp(float value)
{
	if (value < 0.0f) return 0.0f;
	if (value > 255.0f) return 255.0f;
	return value;
}

void main_light(t_pix ***pix)
{
	int     x;
	int     y;
	float   ambient_ratio;
	t_color *ambient_color;

	ambient_ratio = (*pix)[0][0].lux[0][0]->ratio;
	ambient_color = (*pix)[0][0].lux[0][0]->color;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			printf("Before: R=%f, G=%f, B=%f\n", pix[x][y]->color->r, pix[x][y]->color->g, pix[x][y]->color->b);
			pix[x][y]->color->r = clamp(pix[x][y]->color->r * ((float)ambient_color->r / 255.0f * ambient_ratio));
			pix[x][y]->color->g = clamp(pix[x][y]->color->g * ((float)ambient_color->g / 255.0f * ambient_ratio));
			pix[x][y]->color->b = clamp(pix[x][y]->color->b * ((float)ambient_color->b / 255.0f * ambient_ratio));
			printf("After: R=%f, G=%f, B=%f\n", pix[x][y]->color->r, pix[x][y]->color->g, pix[x][y]->color->b);
			y++;
		}
		x++;
	}
}
