/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult_matrix_p_v.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:54:35 by sforster          #+#    #+#             */
/*   Updated: 2025/02/14 15:22:37 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Multiplying a matrix by a tuple produces another tuple
t_coord *matrix_multiplication_44_coord(float *m_a, t_coord *p_v_1)
{
	t_coord	*new_point_vector;
	float coord[4];
	float sum;
	int count;

	if (check_matrix_44_coord(m_a, p_v_1) == false)
		return (NULL);
	new_point_vector = malloc(sizeof(t_coord));
	if (!new_point_vector)
		return (NULL);
	count = 0;
	matrix_from_coord(p_v_1, coord);
    while (count < 4)  // On calcule seulement 4 valeurs (x,y,z,t)
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

void fill_point_vector(t_coord *new_point_vector, int count, float sum)
{
	if (count == 0)
		new_point_vector->x = sum;
	else if (count == 1)
		new_point_vector->y = sum;
	else if (count == 2)
		new_point_vector->z = sum;
	else
		new_point_vector->t = sum;  // reprendre celui d avant pour avoir le meme???
}