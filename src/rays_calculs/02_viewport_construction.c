/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_viewport_construction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:57:11 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 11:00:33 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_viewport(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			init_viewport_x_y(pix[x][y], x, y);
			init_camera_pix_ray(pix[x][y], pix[x][y]->cam);
			y++;
		}
		x++;
	}
}

void	init_camera_pix_ray(t_pix *pix, t_camera *cam)
{
	matrix_point_multiplication_new(pix->r_origin, pix->cam->m_inverse,
		pix->cam->p_zero);
	matrix_point_multiplication_new(pix->p_viewport_world,
		pix->cam->m_inverse, pix->p_viewport);
	substraction_p_to_v_NA(pix->r_dir, pix->p_viewport_world, pix->r_origin);
	normalize_vector_NA(pix->r_dir);
}

void	init_viewport_x_y(t_pix *pix, int x, int y)
{
	pix->p_viewport->x = pix->cam->half_width
		- ((x + 0.5) * pix->cam->pixel_size);
	pix->p_viewport->y = pix->cam->half_height
		- ((y + 0.5) * pix->cam->pixel_size);
}
