/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:08:38 by sforster          #+#    #+#             */
/*   Updated: 2025/02/12 10:33:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
t_image *init_image(t_view *global)
{
	t_image *ima;

	ima = NULL;
	ima = malloc(sizeof(t_image));
	if (!ima)
		return (0);
	ima->global = global;
	ima->mlx_ptr = mlx_init();
	if (ima->mlx_ptr == NULL)
		return (0);

	ima->mlx_win = mlx_new_window(ima->mlx_ptr, ima->global->caneva_width, ima->global->caneva_height, "Fen fen");
	ima->img = mlx_new_image(ima->mlx_ptr, ima->global->caneva_width, ima->global->caneva_height);
	ima->addr = mlx_get_data_addr(ima->img, &ima->bits_per_pixel,
			&ima->line_length, &ima->endian);
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0);
	// vient d ajouter
//	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	return (ima);
}

void image_hooks(t_image *ima)
{
	mlx_hook(ima->mlx_win, 2, 1L << 0, ft_keys, ima);
	mlx_loop(ima->mlx_ptr);
}

void	color_image(t_view *global, t_image *ima)
{
	int x = 0;
	int y = 0;

	while (x < ima->global->caneva_width)
	{
		y = 0;
		while (y < ima->global->caneva_height)
		{
			mlx_pixel_put(ima->mlx_ptr, ima->mlx_win, x, y, 65280);
//			my_mlx_pixel_put(ima, x, y, 2545);
			y++;
		}
		x++;
	}
}

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
*/

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