/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_transformations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/19 16:10:51 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void matrix_transformations(t_pix ***pix)
{
/*	float m[16] = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		5, 5, 5, 1 // translation de +5 sur x, y, z
	};*/
/*	float m[16] = {
		1, 0, 0, 5,
		0, 1, 0, 5,
		0, 0, 1, 5,
		0, 0, 0, 1
	};
	
	t_coord *p = create_point(1, 2, 3);
	t_coord *res = matrix_multiplication_44_coord(m, p);
	printf("Résultat point : %.2f %.2f %.2f (w=%i)\n", res->x, res->y, res->z, res->t);
	
	t_coord *v = create_vector(1, 2, 3);
	t_coord *res2 = matrix_multiplication_44_coord(m, v);
	printf("Résultat vecteur : %.2f %.2f %.2f (w=%i)\n", res2->x, res2->y, res2->z, res2->t);*/
	

	// calcule les matrix de transfo pour tous les objets
	set_transformation(pix[0][0]->obj);
	// applique toutes les transfo sur chaque ray de chaque pixel pour chaque object
	//ray
	apply_transformation(pix);
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
			while (pix[x][y]->obj[a] != NULL)// a changer
			{
				b = 0;
				while(pix[x][y]->obj[a][b] != NULL)// a changer
				{
					u++;
					pix[x][y]->hits[a][b]->r_origin = matrix_multiplication_44_coord(pix[x][y]->obj[a][b]->m_inv, pix[x][y]->r_origin);									
					pix[x][y]->hits[a][b]->r_dir = matrix_multiplication_44_coord(pix[x][y]->obj[a][b]->m_inv, pix[x][y]->r_dir);
	
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
}

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


