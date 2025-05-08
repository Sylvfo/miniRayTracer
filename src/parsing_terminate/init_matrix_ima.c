/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix_ima.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:31 by sforster          #+#    #+#             */
/*   Updated: 2025/05/08 10:45:22 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	init_ima(t_pix ***pix)
{
	t_image	*ima;

	ima = NULL;
	ima = malloc(sizeof(t_image));
	if (!ima)
		return (false);
	ima->mlx_ptr = mlx_init();
	if (ima->mlx_ptr == NULL)
	{
		free(ima);
		return (false);
	}	
	ima->mlx_win = mlx_new_window(ima->mlx_ptr, WND_WIDTH, WND_HEIGHT, "Fen");
	ima->img = mlx_new_image(ima->mlx_ptr, WND_WIDTH, WND_HEIGHT); // ca on peut modifier pour avoir des légendes sur l image
	ima->addr = mlx_get_data_addr(ima->img, &ima->bits_per_pixel,
			&ima->line_length, &ima->endian);
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0); // ca on peut modifier pour avoir des légendes sur l image
	link_pix_ima(pix, ima);
	return (true);
}

void	link_pix_ima(t_pix ***pix, t_image *ima)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->ima = ima;
			y++;
		}
		x++;
	}
	return ;
}
