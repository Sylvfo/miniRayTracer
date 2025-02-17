/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_window.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:26:47 by syl               #+#    #+#             */
/*   Updated: 2025/02/17 16:49:34 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_WINDOW_H
# define MINIRT_WINDOW_H

# include "minirt_data_struct.h"

//CE QUI EST EN LIENS AVEC MINILIBX
// CREATION DE L IMAGE
// GESTION DES HOOKS...



//////// DRAWINGS ////////////
void	pix_drawings(t_pix ***pix);
void	color_pixels(t_pix ***pix);

/////// IMAGE /////////
//event_hooks
void	image_hooks(t_image *ima);
int		ft_keys(int keycode, t_image *ima);
int		ft_exit(t_image *ima);

//init_image.c
t_image	*init_image(void);
void	my_mlx_pixel_put(t_image *ima, int x, int y, int color);

void	pix_to_window(t_pix ***pix);

#endif