/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:38:19 by sforster          #+#    #+#             */
/*   Updated: 2025/01/26 15:23:44 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int main(void)
{
	t_pix	***pix;// data struc des pixels
	t_image *ima; // gestion de l image
	char *string; // a effacer. cest la chenille qui parle :)

	string = malloc(60 * sizeof(char));
	string = "See you",
	
	pix = init_data();
	ima = init_image(pix[0][0]->global);
	
//	color_image(pix[0][0]->global, ima);
	ray_tracing(pix, ima);
	mlx_string_put(ima->mlx_ptr, ima->mlx_win, 600, 500, 0xff8000, string);
	image_hooks(ima);
	printf("Hello new thing\n");
}
