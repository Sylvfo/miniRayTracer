/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_window.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:26:47 by syl               #+#    #+#             */
/*   Updated: 2025/05/11 20:38:08 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_WINDOW_H
# define MINIRT_WINDOW_H

# include "minirt_data_struct.h"

void	image_hooks(t_image *ima);
int		ft_keys(int keycode, t_image *ima);
int		ft_exit(t_image *ima);
int		mouse_hook(int keycode, t_image *ima);
int		mouse_position(int x, int y, t_image *ima);
int		position_mouse_pressed(int button, int x, int y, t_image *ima);

void	my_mlx_pixel_put(t_image *ima, int x, int y, int color);
void	pix_to_window(t_pix ***pix);

#endif