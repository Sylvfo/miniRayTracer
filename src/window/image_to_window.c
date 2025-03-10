/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:21:36 by syl               #+#    #+#             */
/*   Updated: 2025/03/10 22:57:23 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// 1200 = canva height
//1600 = canva width
void	pix_to_window(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			color_float_to_int(pix[x][y]->color);
//			mlx_pixel_put(pix[0][0]->ima->mlx_ptr, pix[0][0]->ima->mlx_win,
//				x, y, pix[x][y]->color->rgb);
			mlx_pixel_put(pix[x][y]->ima->mlx_ptr, pix[x][y]->ima->mlx_win,
				x, y, pix[x][y]->color->rgb);
			y++;
		}
		x++;
	}
}
