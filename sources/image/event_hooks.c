/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:24:48 by syl               #+#    #+#             */
/*   Updated: 2025/01/26 14:08:07 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minirt.h"

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

