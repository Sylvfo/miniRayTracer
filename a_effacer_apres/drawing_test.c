/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:26:24 by syl               #+#    #+#             */
/*   Updated: 2025/03/11 10:44:34 by syl              ###   ########.fr       */
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

