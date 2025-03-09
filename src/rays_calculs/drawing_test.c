/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:26:24 by syl               #+#    #+#             */
/*   Updated: 2025/03/09 14:54:25 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	pix_drawings(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
//			pix[x][y]->color = pix[0][0]->obj[0][0]->color;
			pix[x][y]->color->r = pix[0][0]->obj[0][0]->color->r;
			pix[x][y]->color->g = pix[0][0]->obj[0][0]->color->g;
			pix[x][y]->color->b = pix[0][0]->obj[0][0]->color->b;	
/*			pix[x][y]->color->r = 34;
			pix[x][y]->color->g = 180;
			pix[x][y]->color->b = 0;*/
			y++;
		}
		x++;
	}
}

/*
//1600 = canva width
// 1200 = canva height
void	color_pixels(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			(*pix)[x][y].color->r = 10;
			(*pix)[x][y].color->g = 24;
			(*pix)[x][y].color->b = 12;
//			scalar_mult_color(pix[x][y]->color, 0.3);
			y++;
		}
		x++;
	}
}*/
