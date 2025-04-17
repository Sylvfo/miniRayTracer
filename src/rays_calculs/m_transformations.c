/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_transformations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 11:34:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void matrix_transformations(t_pix ***pix)
{
	// calcule les matrix de transfo pour tous les objets
	set_transformation(pix[0][0]->obj);
	// applique toutes les transfo sur chaque ray de chaque pixel pour chaque object
	apply_transformation(pix);
	//pareil pour les lumières
	// a deplacer
}

void apply_transformation(t_pix ***pix)
{
	int	x;
	int	y;
	int a;
	int b;
	int u = 0;
	
	printf("enter apply\n");
	a = 1;
	x = 0;
	while (x < WND_WIDTH && u < 550000)// a changer
	{
		a = 1;
		y = 0;
		while (y < WND_HEIGHT)
		{ 
			a = 1;
			while (a < 4)// a changer
			{
				b = 0;
				while(pix[x][y]->obj[a][b] != NULL && b < 4)// a changer
				{
					u++;
					pix[x][y]->hits[a][b]->r_ray_calculs->p_origin = matrix_multiplication_44_coord(pix[x][y]->obj[a][b]->m_tranf, pix[x][y]->r_original->p_origin);									
					pix[x][y]->hits[a][b]->r_ray_calculs->v_dir = matrix_multiplication_44_coord(pix[x][y]->obj[a][b]->m_tranf, pix[x][y]->r_original->v_dir);
				//	pix[x][y]->hits[a][b]->r_ray_calculs->v_dir = normalize_vector(pix[x][y]->hits[a][b]->r_ray_calculs->v_dir);
					b++;
				}
				a++;
			}
			y++;
		}
		x++;
	}
	printf("uu %i \n", u);
}


