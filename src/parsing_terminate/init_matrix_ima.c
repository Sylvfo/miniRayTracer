/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix_ima.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:31 by sforster          #+#    #+#             */
/*   Updated: 2025/03/10 11:01:39 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	init_matrix_ref(t_pix ***pix)
{
	t_matrix	*neo;

	neo = malloc(sizeof(t_matrix));
	if (!neo)
		return (false);
	neo->m_rot_x = NULL; //A CALCULER APRES SELON ANGLE
	neo->m_rot_y = NULL; //A CALCULER APRES SELON ANGLE
	neo->m_rot_z = NULL; //A CALCULER APRES SELON ANGLE
	neo->m_transl = NULL; // A CALCULER APRES SELON X Y Z DEPLACEMENT
	neo->m_identity = create_indentity_matrix_44();
	link_pix_matrix(pix, neo);
	return (true);
}

void		link_pix_matrix(t_pix ***pix, t_matrix *neo)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
//			pix[x][y]->neo = malloc(sizeof(t_matrix *));
//			pix[x][y]->t1 = 5;
			pix[x][y]->neo = neo;
			y++;
		}
		x++;
	}
	return ;
}

bool	init_ima(t_pix ***pix)
{
	t_image	*ima;

	ima = NULL;
	ima = malloc(sizeof(t_image));
	if (!ima)
		return (false);
	ima->mlx_ptr = mlx_init();
	if (ima->mlx_ptr == NULL)
	{
		free(ima);
		return (false);
	}	
	ima->mlx_win = mlx_new_window(ima->mlx_ptr, WND_WIDTH, WND_HEIGHT, "Fen");
	ima->img = mlx_new_image(ima->mlx_ptr, WND_WIDTH, WND_HEIGHT); // ca on peut modifier pour avoir des légendes sur l image
	ima->addr = mlx_get_data_addr(ima->img, &ima->bits_per_pixel,
			&ima->line_length, &ima->endian);
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0); // ca on peut modifier pour avoir des légendes sur l image
	link_pix_ima(pix, ima);
	return (true);
}

void	link_pix_ima(t_pix ***pix, t_image *ima)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
//			pix[x][y]->ima = malloc(sizeof(t_image *));
			pix[x][y]->ima = ima;
			y++;
		}
		x++;
	}
	return ;
}
