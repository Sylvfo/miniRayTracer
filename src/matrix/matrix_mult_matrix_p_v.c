/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult_matrix_p_v.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:54:35 by sforster          #+#    #+#             */
/*   Updated: 2025/04/19 16:10:54 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Multiplying a matrix by a tuple produces another tuple
// On calcule seulement 4 valeurs (x,y,z,t)

t_coord	*matrix_multiplication_44_coord(float *m_a, t_coord *p_v_1)
{
	t_coord	*new_point_vector;
	float	coord[4];
	float	sum;
	int		count;

	if (check_matrix_44_coord(m_a, p_v_1) == false)
		return (NULL);
	new_point_vector = malloc(sizeof(t_coord));
	if (!new_point_vector)
		return (NULL);
	count = 0;
	matrix_from_coord(p_v_1, coord);
	while (count < 4)
	{
		sum = 0;
		sum += m_a[2 + count * 4] * coord[0];
		sum += m_a[2 + count * 4 + 1] * coord[1];
		sum += m_a[2 + count * 4 + 2] * coord[2];
		sum += m_a[2 + count * 4 + 3] * coord[3];
		fill_point_vector(new_point_vector, count, sum);
		count++;
	}
	return (new_point_vector);
}

bool	check_matrix_44_coord(float *m_a, t_coord *p_v_1)
{
	if (!m_a)
	{
		printf("Matrix is missing\n");
		return (false);
	}
	if (m_a[0] != 4 || m_a[1] != 4)
	{
		printf("Matrix not 4x4 in multiplication\n");
		return (false);
	}
	if (!p_v_1)
	{
		printf("vect or point is missing\n");
		return (false);
	}
	return (true);
}

void	matrix_from_coord(t_coord *p_v_1, float coord[4])
{
	coord[0] = p_v_1->x;
	coord[1] = p_v_1->y;
	coord[2] = p_v_1->z;
	coord[3] = p_v_1->t;
}

// new_point_vector->t = sum;  reprendre celui d avant pour avoir le meme???
void	fill_point_vector(t_coord *new_point_vector, int count, float sum)
{
	if (count == 0)
		new_point_vector->x = sum;
	else if (count == 1)
		new_point_vector->y = sum;
	else if (count == 2)
		new_point_vector->z = sum;
	else
		new_point_vector->t = sum;
}


//on laisse au cas où
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
	return (new_point);
}

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