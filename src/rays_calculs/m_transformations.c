/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_transformations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/19 15:10:30 by syl              ###   ########.fr       */
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

t_coord *matrix_multiplication_44_point(float *m_, t_coord *p)
{
	t_coord *new_point = malloc(sizeof(t_coord));
//	float *m = m_ + 2; // on saute les infos taille

	if (!new_point)
		return (NULL);
	
	new_point->x = m_[2] * p->x + m_[6] * p->y + m_[10] * p->z + m_[14];  // Colonne 0
	new_point->y = m_[3] * p->x + m_[7] * p->y + m_[11] * p->z + m_[15];  // Colonne 1
	new_point->z = m_[4] * p->x + m_[8] * p->y + m_[12] * p->z + m_[16]; // Colonne 2
	new_point->t = 1.0f;
/*	new_point->x = m_[2] * p->x + m_[3] * p->y + m_[4] * p->z + m_[5] * p->t;  // Ligne 0
    new_point->y = m_[6] * p->x + m_[7] * p->y + m_[8] * p->z + m_[9] * p->t;   // Ligne 1
    new_point->z = m_[10] * p->x + m_[11] * p->y + m_[12] * p->z + m_[13] * p->t; // Ligne 2
*/
	return (new_point);
}

/*
t_coord *matrix_multiplication_44_point(float *m_transf, t_coord *p_point)
{
	t_coord	*new_point;

	new_point = malloc(sizeof(t_coord));
    // Multiplier la position locale par la matrice de transformation
    new_point->x = m_transf[2] * p_point->x + 
                    m_transf[6] * p_point->y + 
                    m_transf[10] * p_point->z + 
                    m_transf[14];
                    
	new_point->y = m_transf[3] * p_point->x + 
                    m_transf[7] * p_point->y + 
                    m_transf[11] * p_point->z + 
                    m_transf[15];
                    
	new_point->z = m_transf[4] * p_point->x + 
                    m_transf[8] * p_point->y + 
                    m_transf[12] * p_point->z + 
                    m_transf[16];
                    
	new_point->t = 1.0f; // Important pour un point
	return (new_point);
}*/

/*
t_coord *matrix_multiplication_44_point(float *m_, t_coord *p)
{
	t_coord *new_point = malloc(sizeof(t_coord));
	float *m = m_ + 2; // on saute les infos taille

	if (!new_point)
		return (NULL);

	new_point->x = m[0] * p->x + m[1] * p->y + m[2] * p->z + m[3];
	new_point->y = m[4] * p->x + m[5] * p->y + m[6] * p->z + m[7];
	new_point->z = m[8] * p->x + m[9] * p->y + m[10] * p->z + m[11];
	new_point->t = 1.0f;

	return (new_point);
}

t_coord *matrix_multiplication_44_vector(float *m_, t_coord *v)
{
	t_coord *new_vec = malloc(sizeof(t_coord));
	float *m = m_ + 2;

	if (!new_vec)
		return (NULL);

	new_vec->x = m[0] * v->x + m[1] * v->y + m[2] * v->z;
	new_vec->y = m[4] * v->x + m[5] * v->y + m[6] * v->z;
	new_vec->z = m[8] * v->x + m[9] * v->y + m[10] * v->z;
	new_vec->t = 0.0f;

	return (new_vec);
}*/
/*
t_coord *matrix_multiplication_44_point(float *m_, t_coord *p)
{
	t_coord *new_point = malloc(sizeof(t_coord));
//	float *m = m_ + 2; // on saute les infos taille

	if (!new_point)
		return (NULL);

	new_point->x = m_[0] * p->x + m_[4] * p->y + m_[8] * p->z + m_[12];  // Colonne 0
	new_point->y = m_[1] * p->x + m_[5] * p->y + m_[9] * p->z + m_[13];  // Colonne 1
	new_point->z = m_[2] * p->x + m_[6] * p->y + m_[10] * p->z + m_[14]; // Colonne 2
	new_point->t = 1.0f;

	return (new_point);
}

t_coord *matrix_multiplication_44_vector(float *m_, t_coord *v)
{
	t_coord *new_vec = malloc(sizeof(t_coord));
//	float *m = m_ + 2;

	if (!new_vec)
		return (NULL);

	new_vec->x = m_[0] * v->x + m_[4] * v->y + m_[8] * v->z;  // Colonne 0
	new_vec->y = m_[1] * v->x + m_[5] * v->y + m_[9] * v->z;  // Colonne 1
	new_vec->z = m_[2] * v->x + m_[6] * v->y + m_[10] * v->z; // Colonne 2
	new_vec->t = 0.0f;
	return (new_vec);
}*/





t_coord *matrix_multiplication_44_vector(float *m_, t_coord *v)
{
	t_coord *new_vec = malloc(sizeof(t_coord));
//	float *m = m_ + 2;

	if (!new_vec)
		return (NULL);

	new_vec->x = m_[2] * v->x + m_[6] * v->y + m_[10] * v->z;  // Colonne 0
	new_vec->y = m_[3] * v->x + m_[7] * v->y + m_[11] * v->z;  // Colonne 1
	new_vec->z = m_[5] * v->x + m_[8] * v->y + m_[12] * v->z; // Colonne 2
	new_vec->t = 0.0f;
	return (new_vec);
}


/*
t_coord	*matrix_multiplication_44_vector(float *m_, t_coord *p_v_1)
{
	t_coord	*new_point_vector;
	float	coord[4];
	float	sum;
	int		count;

	if (check_matrix_44_coord(m_, p_v_1) == false)
	{
		printf("mistake here \n");
		return (NULL);
	}	
	new_point_vector = malloc(sizeof(t_coord));
	if (!new_point_vector)
		return (NULL);
	count = 0;
	matrix_from_coord(p_v_1, coord);
	coord[3] = 0;
	
	while (count < 4)
	{
		sum = 0;
		sum += m_[2 + count * 4] * coord[0];
		sum += m_[2 + count * 4 + 1] * coord[1];
		sum += m_[2 + count * 4 + 2] * coord[2];
		sum += m_[2 + count * 4 + 3] * coord[3];
		fill_point_vector(new_point_vector, count, sum);
		count++;
	}
	new_point_vector->t = p_v_1->t;
//	printf("ok done \n");
	return (new_point_vector);
}*/


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

/*
void update_world_position(t_obj *obj)
{
    if (!obj) return;
    
    // Multiplier la position locale par la matrice de transformation
    obj->p_world->x = obj->m_transf[0] * obj->p_coord->x + 
                    obj->m_transf[4] * obj->p_coord->y + 
                    obj->m_transf[8] * obj->p_coord->z + 
                    obj->m_transf[12];
                    
    obj->p_world->y = obj->m_transf[1] * obj->p_coord->x + 
                    obj->m_transf[5] * obj->p_coord->y + 
                    obj->m_transf[9] * obj->p_coord->z + 
                    obj->m_transf[13];
                    
    obj->p_world->z = obj->m_transf[2] * obj->p_coord->x + 
                    obj->m_transf[6] * obj->p_coord->y + 
                    obj->m_transf[10] * obj->p_coord->z + 
                    obj->m_transf[14];
                    
    obj->p_world->t = 1.0f; // Important pour un point
}*/