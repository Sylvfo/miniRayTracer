/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_viewport.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:20:44 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 20:59:43 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/initialization.h"

void	init_pix_viewport(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->p_viewport = create_point(0, 0, -1);
			pix[x][y]->p_viewport_world = create_point(0, 0, 0);
			pix[x][y]->r_dir = malloc(sizeof(t_coord));
			pix[x][y]->r_origin = malloc(sizeof(t_coord));
			y++;
		}
		x++;
	}
}
