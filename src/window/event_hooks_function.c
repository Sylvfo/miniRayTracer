/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:33:55 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 10:34:19 by cmegret          ###   ########.fr       */
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
	(void) context;
	//free_all(context);
	exit(0);
	return (0);
}

int	ft_keys(int keycode, t_program_context *context)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		(void) context;
		//free_all(context);
		exit(0);
		return (0);
	}
	return (0);
}
