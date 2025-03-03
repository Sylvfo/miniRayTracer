/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:08:38 by sforster          #+#    #+#             */
/*   Updated: 2025/03/03 15:03:24 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


// my_mlx_pixel_put(ima, (int)round(p->l1), (int)round(p->l2), color);
void	my_mlx_pixel_put(t_image *ima, int x, int y, int color)
{
	char	*dst;

	if (!x || !y)
		return ;
//	if (x >= 2200)
//		return ;
//	if (y >= 1300)
//		return ;
	dst = ima->addr + (y * ima->line_length + x * (ima->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0); // ca on peut modifier pour avoir des légendes sur l image


/*
void	drawings(struct s_data *ima)
{
	float	sizezoom;

	ima->img = mlx_new_image(ima->mlx_ptr, 2200, 1300);
	ima->addr = mlx_get_data_addr(ima->img, &ima->bits_per_pixel,
			&ima->line_length, &ima->endian);
	ft_iso_30(ima->map);
	sizezoom = scale(ima->map);
	zoom(ima->map, sizezoom);
	ft_iso_30(ima->map);
	center_pict(ima->map, 2200, 1300);
	draw_lines(ima);
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0);
}

*/