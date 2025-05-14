/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:24:48 by syl               #+#    #+#             */
/*   Updated: 2025/05/14 22:49:33 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// These functions' signatures are also updated to receive the context
int	mouse_position(int x, int y, t_program_context *context)
{
	(void) context;
	printf("mouse is at : %i - %i \n", x, y);
	return (0);
}

int	position_mouse_pressed(int button, int x, int y, t_program_context *context)
{
	(void) context;
	if (button == 1)
		printf("mouse is at : %i - %i \n", x, y);
	return (0);
}

int	mouse_hook(int keycode, t_program_context *context)
{
	(void) context;
	printf("keycode mouse: %d\n", keycode);
	return (0);
}

int	ft_exit(t_program_context *context)
{
	free_all(context);
	exit(0);
	return (0);
}

int	ft_keys(int keycode, t_program_context *context)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		new_free(context->pix);
	//	free_all(context);
		exit(0);
		return (0);
	}
	return (0);
}

void	image_hooks(t_program_context *context)
{
	mlx_hook(context->mlx_win, 2, 1L << 0, ft_keys, context);
	mlx_hook(context->mlx_win, 4, 1L << 2, position_mouse_pressed, context);
	mlx_hook(context->mlx_win, 17, 0, ft_exit, context);
	mlx_loop(context->mlx_ptr);
}
