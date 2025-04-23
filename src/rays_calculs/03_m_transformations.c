/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_m_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/23 12:31:01 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void matrix_transformations(t_pix ***pix)
{

	// calcule les matrix de transfo pour tous les objets
	set_transformation(pix[0][0]->obj);
	// applique toutes les transfo sur chaque ray de chaque pixel pour chaque object
	apply_transformation(pix);
	//faire pour tous les objets
//	apply_transf_sph_center(pix[0][0]);
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
					if (!pix[x][y]->obj[a][b]->m_inv)
					{
						printf("missing matrix in apply \n");
						exit (0);
					}
					pix[x][y]->hits[a][b]->r_origin = matrix_multiplication_44_coord(pix[x][y]->obj[a][b]->m_inv, pix[x][y]->r_origin);									
					pix[x][y]->hits[a][b]->r_dir = matrix_multiplication_44_coord(pix[x][y]->obj[a][b]->m_inv, pix[x][y]->r_dir);
					if (pix[x][y]->obj[a][b]->obj_type == SPHERE)
						pix[x][y]->obj[a][b]->p_world = matrix_multiplication_44_point(pix[x][y]->obj[a][b]->m_transf, pix[x][y]->obj[a][b]->p_coord);
					b++;
				}
				a++;
			}
			y++;
		}
		x++;
	}
}

/*
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
			pix->obj[a][b]->p_world = matrix_multiplication_44_point(pix->obj[a][b]->m_transf, pix->obj[a][b]->p_coord);
		//	update_world_position(pix->obj[a][b]);
			printf("\np_coord avant ");
			print_point(pix->obj[a][b]->p_coord);
//			printf("p_world resultat ");
			print_matrix(pix->obj[a][b]->m_inv);
			printf("p_world resultat ");
			print_point(pix->obj[a][b]->p_world);

			b++;
		}
		a++;
	}	
}*/

void update_world_position(t_obj *obj)
{
    if (!obj) return;
    
    // Multiplier la position locale par la matrice de transformation
    obj->p_world->x = obj->m_transf[2] * obj->p_coord->x + 
                    obj->m_transf[6] * obj->p_coord->y + 
                    obj->m_transf[10] * obj->p_coord->z + 
                    obj->m_transf[14];
                    
    obj->p_world->y = obj->m_transf[3] * obj->p_coord->x + 
                    obj->m_transf[7] * obj->p_coord->y + 
                    obj->m_transf[11] * obj->p_coord->z + 
                    obj->m_transf[15];
                    
    obj->p_world->z = obj->m_transf[4] * obj->p_coord->x + 
                    obj->m_transf[8] * obj->p_coord->y + 
                    obj->m_transf[12] * obj->p_coord->z + 
                    obj->m_transf[16];
                    
    obj->p_world->t = 1.0f; // Important pour un point
}


