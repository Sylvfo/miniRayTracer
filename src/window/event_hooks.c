/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:24:48 by syl               #+#    #+#             */
/*   Updated: 2025/05/15 10:34:09 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	image_hooks(t_program_context *context)
{
	mlx_hook(context->mlx_win, 2, 1L << 0, ft_keys, context);
	mlx_hook(context->mlx_win, 4, 1L << 2, position_mouse_pressed, context);
	mlx_hook(context->mlx_win, 17, 0, ft_exit, context);
	mlx_loop(context->mlx_ptr);
}
