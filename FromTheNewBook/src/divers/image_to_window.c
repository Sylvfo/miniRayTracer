/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:21:36 by syl               #+#    #+#             */
/*   Updated: 2025/02/12 15:22:02 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


void pix_to_window(t_pix ***pix)
{
	/// ici qu on va faire le raytracer etc...
	color_pixels(pix);
	
	color_image_wind(pix);
}

void color_image_wind(t_pix ***pix)
{
	int x;
	int y;

	x = 0;
	while(x < 1600)//1600 = canva width
	{
		y = 0; 
		while (y < 1200) // 1200 = canva height
		{
			color_float_to_int(pix[x][y]->col);
			mlx_pixel_put(pix[0][0]->ima->mlx_ptr, pix[0][0]->ima->mlx_win, x, y, pix[x][y]->col->rgb);
			y++;
		}
		x++;
	}
}

void color_pixels(t_pix ***pix)
{
	int x;
	int y;

	x = 0;
	while(x < 1600)//1600 = canva width
	{
		y = 0; 
		while (y < 1200) // 1200 = canva height
		{
			scalar_mult_color(pix[x][y]->col, 0.3);
			pix[x][y]->color = 200;
			y++;
		}
		x++;
	}
}