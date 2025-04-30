/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_m_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/30 16:53:11 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void matrix_transformations(t_pix ***pix)
{

	// calcule les matrix de transfo pour tous les objets
	set_transformation(pix[0][0]->obj);
	printf("Abb \n");
	// applique toutes les transfo sur chaque ray de chaque pixel pour chaque object
	apply_transformation(pix);
	printf("Bub \n");
	//faire pour tous les objets
	apply_transf_sph_center(pix[0][0]);
	//pareil pour les lumières
	set_transformation_light(pix[0][0]->lux);
	transform_lights(pix[0][0]->lux);
	// a deplacer
}

void apply_transformation(t_pix ***pix)
{
	int	x;
	int	y;
	int a;
	int b;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{ 
			a = 1;
			while (pix[x][y]->obj[a] != NULL)
			{
				b = 0;
				while(pix[x][y]->obj[a][b] != NULL)
				{
					matrix_point_multiplication_new(pix[x][y]->hits[a][b]->r_origin, pix[x][y]->obj[a][b]->m_inv, pix[x][y]->r_origin);
					matrix_point_multiplication_new(pix[x][y]->hits[a][b]->r_dir, pix[x][y]->obj[a][b]->m_inv, pix[x][y]->r_dir);
					b++;
				}
				a++;
			}
			y++;
		}
		x++;
	}
}


void apply_transf_sph_center(t_pix *pix)
{
	int a;
	int b;

	a = 1;
	b = 0;
	while (a < 4)// a changer
	{
		b = 0;
		while(pix->obj[a][b] != NULL)// a changer
		{	
		//	pix->obj[a][b]->p_world = create_point(0, 0, 0);
		//	copy_coord(pix->obj[a][b]->p_world, pix->obj[a][b]->p_coord);
			matrix_point_multiplication_new(pix->obj[a][b]->p_world, pix->obj[a][b]->m_transf, pix->obj[a][b]->p_coord);
			//matrix_multiplication_44_coord_NA(pix->obj[a][b]->p_world, pix->obj[a][b]->m_transf, pix->obj[a][b]->p_coord);
		//	print_point(pix->obj[a][b]->p_world);
			b++;
		}
		a++;
	}	
}




