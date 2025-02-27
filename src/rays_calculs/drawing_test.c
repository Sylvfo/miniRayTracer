/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:26:24 by syl               #+#    #+#             */
/*   Updated: 2025/02/27 13:40:15 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	pix_drawings(t_pix ***pix)
{
	color_pixels(pix);
}

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
		while (y < WND_HIGHT)
		{
			scalar_mult_color(pix[x][y]->col, 0.3);
			y++;
		}
		x++;
	}
}
