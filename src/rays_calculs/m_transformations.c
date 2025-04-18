/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_transformations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/18 17:49:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void matrix_transformations(t_pix ***pix)
{
	// calcule les matrix de transfo pour tous les objets
	set_transformation(pix[0][0]->obj);
	// applique toutes les transfo sur chaque ray de chaque pixel pour chaque object
	//ray
	apply_transformation(pix);
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
	int u = 0;
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
					pix[x][y]->hits[a][b]->r_origin = matrix_multiplication_44_coord(pix[x][y]->obj[a][b]->m_tranf, pix[x][y]->r_origin);									
					pix[x][y]->hits[a][b]->r_dir = matrix_multiplication_44_coord(pix[x][y]->obj[a][b]->m_tranf, pix[x][y]->r_dir);
					if (x == 25 && y == 34)
					{
						printf("\nray dir ");
						print_vector(pix[x][y]->hits[a][b]->r_dir);
						printf("r_origin ");
						print_point(pix[x][y]->hits[a][b]->r_origin);
					}
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
			pix->obj[a][b]->p_world = malloc(sizeof(t_coord));
			update_world_position(pix->obj[a][b]);
//			printf("\np_coord avant ");
//			print_point(pix->obj[a][b]->p_coord);
//			printf("p_world resultat ");
//			print_matrix(pix->obj[a][b]->m_tranf);
//			printf("p_world resultat ");
//			print_point(pix->obj[a][b]->p_world);
			b++;
		}
		a++;
	}	
}

void update_world_position(t_obj *obj)
{
    if (!obj) return;
    
    // Multiplier la position locale par la matrice de transformation
    obj->p_world->x = obj->m_no_invese[0] * obj->p_coord->x + 
                    obj->m_no_invese[4] * obj->p_coord->y + 
                    obj->m_no_invese[8] * obj->p_coord->z + 
                    obj->m_no_invese[12];
                    
    obj->p_world->y = obj->m_no_invese[1] * obj->p_coord->x + 
                    obj->m_no_invese[5] * obj->p_coord->y + 
                    obj->m_no_invese[9] * obj->p_coord->z + 
                    obj->m_no_invese[13];
                    
    obj->p_world->z = obj->m_no_invese[2] * obj->p_coord->x + 
                    obj->m_no_invese[6] * obj->p_coord->y + 
                    obj->m_no_invese[10] * obj->p_coord->z + 
                    obj->m_no_invese[14];
                    
    obj->p_world->t = 1.0f; // Important pour un point
}









/*
void update_world_position(t_obj *obj) {
    if (!obj) return;
    
    // Multiplier la position locale par la matrice de transformation
    obj->p_world->x = obj->m_tranf[0] * obj->p_coord->x + 
                    obj->m_tranf[4] * obj->p_coord->y + 
                    obj->m_tranf[8] * obj->p_coord->z + 
                    obj->m_tranf[12];
                    
    obj->p_world->y = obj->m_tranf[1] * obj->p_coord->x + 
                    obj->m_tranf[5] * obj->p_coord->y + 
                    obj->m_tranf[9] * obj->p_coord->z + 
                    obj->m_tranf[13];
                    
    obj->p_world->z = obj->m_tranf[2] * obj->p_coord->x + 
                    obj->m_tranf[6] * obj->p_coord->y + 
                    obj->m_tranf[10] * obj->p_coord->z + 
                    obj->m_tranf[14];
                    
    obj->p_world->t = 1.0f; // Important pour un point
}*/


/*
void apply_transf_sph_center(t_pix ***pix)
{
	int a;
	int b;

	a = 1;
	b = 0;
	while (a < 4)// a changer
	{
		b = 0;
		while(pix[0][0]->obj[a][b] != NULL)// a changer
		{	
			copy_coord(pix[0][0]->obj[a][b]->p_world, pix[0][0]->obj[a][b]->p_coord);
		//	pix[0][0]->obj[a][b]->p_world = matrix_multiplication_44_coord(pix[0][0]->obj[a][b]->m_tranf, pix[0][0]->obj[a][b]->p_coord);									
		//	print_matrix(pix[0][0]->obj[a][b]->m_tranf);

		//	printf("p_coord ");
		//	print_point(pix[0][0]->obj[a][b]->p_coord);
		//	printf("p_world ");
		//	print_point(pix[0][0]->obj[a][b]->p_world);
			b++;
		}
		a++;
	}	
}*/
