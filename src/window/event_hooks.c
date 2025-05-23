/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:24:48 by syl               #+#    #+#             */
/*   Updated: 2025/02/17 22:35:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	image_hooks(t_image *ima)
{
	mlx_hook(ima->mlx_win, 2, 1L << 0, ft_keys, ima);
	// Hook to detect mouse button presses (event code 4)
	mlx_hook(ima->mlx_win, 4, 1L << 2, position_mouse_pressed, ima);
//	mlx_hook(ima->mlx_win, 6, 1 << 6, mouse_position, ima);
//	mlx_mouse_hook(ima->mlx_win, mouse_hook, ima);
	mlx_loop(ima->mlx_ptr);
}

int mouse_position(int x, int y, t_image *ima)
{
	(void) ima;
	printf("mouse is at : %i - %i \n", x, y);
	return (0);
}

int position_mouse_pressed(int button, int x, int y, t_image *ima)
{
	(void) ima;
	if (button == 1)
		printf("mouse is at : %i - %i \n", x, y);
	return (0);	
}

int mouse_hook(int keycode, t_image *ima)
{
	(void) ima;
	printf("keycode mouse: %d\n", keycode);
	return (0);
}

int	ft_exit(t_image *ima)
{
	mlx_destroy_image(ima->mlx_ptr, ima->img);
	mlx_destroy_window(ima->mlx_ptr, ima->mlx_win);
	printf("Window closed\n");
//	ft_free_list(&ima->map);
//	free(ima);
	exit(0);
	return (0);
}

int	ft_keys(int keycode, t_image *ima)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_image(ima->mlx_ptr, ima->img);
		mlx_destroy_window(ima->mlx_ptr, ima->mlx_win);
		printf("ESC pressed.\nWindow closed\n");
//		ft_free_list(&ima->map);
//		free(ima);
		exit(0);
		return (0);
	}
	return (0);
}