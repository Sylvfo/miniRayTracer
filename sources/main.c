/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:38:19 by sforster          #+#    #+#             */
/*   Updated: 2025/01/24 15:31:43 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int main(void)
{
	t_pix	***pix;// data struc des pixels
	t_image *ima;
	char *string;

	string = malloc(60 * sizeof(char));
	string = "See you",
	
	pix = init_data();
	ima = init_image(pix[0][0]->global);
	
//	color_image(pix[0][0]->global, ima);
	ray_tracing(pix, ima);
	mlx_string_put(ima->mlx_ptr, ima->mlx_win, 600, 500, 0xff8000, string);
//	mlx_string_put(ima->mlx_ptr, ima->win_ptr, int 20, int 20, int color, char *string)
	image_hooks(ima);
	printf("Hello new thing\n");
}
/*
define raymin and raymax

#define RAY_T_MIN 0.0001f

vector unit
*/