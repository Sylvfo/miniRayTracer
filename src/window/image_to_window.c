/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:21:36 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 14:52:04 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// 1200 = canva height
//1600 = canva width
void    pix_to_window(t_pix ***pix)
{
    int        x;
    int        y;
    t_image    *ima;

    ima = pix[0][0]->ima; // Un seul contexte image partagé
    x = 0;
    while (x < WND_WIDTH)
    {
        y = 0;
        while (y < WND_HEIGHT)
        {
            color_float_to_int(pix[x][y]->color);
            my_mlx_pixel_put(ima, x, y, pix[x][y]->color->rgb); // Mets le pixel dans le buffer image
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0); // Affiche l'image complète
}
