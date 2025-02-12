/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:26:24 by syl               #+#    #+#             */
/*   Updated: 2025/02/12 16:33:38 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	pix_drawings(t_pix ***pix)
{
	color_pixels3(pix);
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
			y++;
		}
		x++;
	}
}

// degradé
void color_pixels2(t_pix ***pix)
{
	int x;
	int y;
	float degradé;

	degradé = 0.001;

	x = 0;
	while(x < 1600)//1600 = canva width
	{
		y = 0; 
		while (y < 1200) // 1200 = canva height
		{
			if (y != 0)
			degradé = y / 100;
			scalar_mult_color(pix[x][y]->col, degradé);
			y++;
		}
		x++;
	}
}

void color_pixels3(t_pix ***pix)
{
	int x;
	int y;
	t_color *c_new_one;

	c_new_one = create_color(200, 255, 200);


//	multipling_color(pix[0][0]->col, c_new_one);

	x = 0;
	while(x < 1600)//1600 = canva width
	{
		y = 400; 
		while (y < 800) // 1200 = canva height
		{
			multipling_color(pix[x][y]->col, c_new_one);
//			color_float_to_int(pix[x][y]->col);// devrait etre effacé
			y++;
		}
		while (y < 1200) // 1200 = canva heigdht
		{
			change_color(pix[x][y]->col, 10, 10, 200);
			y++;
		}
		x++;
	}
}