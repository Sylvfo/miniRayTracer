/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_window.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:26:47 by syl               #+#    #+#             */
/*   Updated: 2025/05/12 09:21:41 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_WINDOW_H
# define MINIRT_WINDOW_H

# include "minirt_data_struct.h"

void	image_hooks(t_program_context *context);
int		mouse_position(int x, int y, t_program_context *context);
int		position_mouse_pressed(int button, int x, int y,
			t_program_context *context);
int		mouse_hook(int keycode, t_program_context *context);
int		ft_exit(t_program_context *context);
int		ft_keys(int keycode, t_program_context *context);

void	my_mlx_pixel_put(t_image *ima, int x, int y, int color);
void	pix_to_window(t_pix ***pix);

#endif