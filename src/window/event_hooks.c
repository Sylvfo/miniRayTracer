/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:24:48 by syl               #+#    #+#             */
/*   Updated: 2025/05/12 11:05:05 by cmegret          ###   ########.fr       */
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
	if (context)
	{
		free_all(context->pix, context->width,
			context->height, context->num_obj);
		context->pix = NULL;
		context->num_obj = NULL;
		if (context->mlx_ptr && context->mlx_win)
			mlx_destroy_window(context->mlx_ptr, context->mlx_win);
		free(context);
		context = NULL;
	}
	exit(0);
	return (0);
}

int	ft_keys(int keycode, t_program_context *context)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		if (context)
		{
			free_all(context->pix, context->width,
				context->height, context->num_obj);
			if (context->ima && context->mlx_ptr && context->ima->img)
				mlx_destroy_image(context->mlx_ptr, context->ima->img);
			if (context->mlx_ptr && context->mlx_win)
				mlx_destroy_window(context->mlx_ptr, context->mlx_win);
			free(context);
		}
		printf("ESC pressed.\nWindow closed\n");
		exit(0);
		return (0);
	}
	return (0);
}
