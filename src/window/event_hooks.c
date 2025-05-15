/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:24:48 by syl               #+#    #+#             */
/*   Updated: 2025/05/15 08:39:27 by syl              ###   ########.fr       */
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
	printf("in ft_exit\n");
	if (context->pix)
		new_free(context->pix);
//	exit(0);
	return (0);
}

int	ft_keys(int keycode, t_program_context *context)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		if (context->ima)
		{
			free_image(context->ima);
			context->ima = NULL;
		}

	// 2. MLX
		if (context->mlx_ptr || context->mlx_win)
		{
			free_mlx(context->mlx_ptr, context->mlx_win);
			context->mlx_ptr = NULL;
			context->mlx_win = NULL;
		}
		printf("jklfj\n");
		if (context->pix)
			new_free(context->pix);
		printf("	OUT OF FREE IN KEYS\n");
	//	exit(0);
		return (0);
	}
	return (0);
}

void	image_hooks(t_program_context *context)
{
	mlx_hook(context->mlx_win, 2, 1L << 0, ft_keys, context);
	mlx_hook(context->mlx_win, 17, 0, ft_exit, context);
	mlx_loop(context->mlx_ptr);
}
