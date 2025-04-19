/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult_matrix_p_v.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:54:35 by sforster          #+#    #+#             */
/*   Updated: 2025/04/19 15:57:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Multiplying a matrix by a tuple produces another tuple
// On calcule seulement 4 valeurs (x,y,z,t)



/*
typedef struct s_tuple {
    float x;
    float y;
    float z;
    float w;  // w=1 for point, w=0 for vector
} t_tuple;*/

/*
//t_coord *matrix4x4_multiply_tuple(float matrix[16], t_coord *tuple)
t_coord *matrix_multiplication_44_coord(float *matrix, t_coord *tuple) {
    t_coord *result = malloc(sizeof(t_coord));
    if (!result) return NULL;

    // Multiplication row-major (si matrix est row-major)
    result->x = matrix[0] * tuple->x + matrix[1] * tuple->y + matrix[2] * tuple->z + matrix[3] * tuple->t;
    result->y = matrix[4] * tuple->x + matrix[5] * tuple->y + matrix[6] * tuple->z + matrix[7] * tuple->t;
    result->z = matrix[8] * tuple->x + matrix[9] * tuple->y + matrix[10] * tuple->z + matrix[11] * tuple->t;
    result->t = matrix[12] * tuple->x + matrix[13] * tuple->y + matrix[14] * tuple->z + matrix[15] * tuple->t;

    // Normalisation pour les points uniquement (t != 0)
    if (result->t != 0.0f && result->t != 1.0f) {
        float inv_t = 1.0f / result->t;
        result->x *= inv_t;
        result->y *= inv_t;
        result->z *= inv_t;
        result->t = 1.0f;
    }
    return result;
}*/

/*
//version gpt 2
t_coord *matrix_multiplication_44_coord(float *m_a, t_coord *p_v_1)
{
    t_coord *res;
    float coord[4];
    float out[4];
    int row, col;

    if (!m_a || !p_v_1)
        return (NULL);

    res = malloc(sizeof(t_coord));
    if (!res)
        return (NULL);

    coord[0] = p_v_1->x;
    coord[1] = p_v_1->y;
    coord[2] = p_v_1->z;
    coord[3] = p_v_1->t;

    for (row = 0; row < 4; row++)
    {
        out[row] = 0;
        for (col = 0; col < 4; col++)
            out[row] += m_a[row * 4 + col] * coord[col];
    }

    res->x = out[0];
    res->y = out[1];
    res->z = out[2];
    res->t = out[3];

    return (res);
}*/

/*
//version gpt
t_coord	*matrix_multiplication_44_coord(float *m_a, t_coord *p_v_1)
{
	t_coord	*res;
	float	in[4];
	float	out[4];
	int		i, j;

	if (!m_a || !p_v_1)
		return (NULL);
	res = malloc(sizeof(t_coord));
	if (!res)
		return (NULL);

	// point : w = 1 / vecteur : w = 0
	in[0] = p_v_1->x;
	in[1] = p_v_1->y;
	in[2] = p_v_1->z;
	in[3] = p_v_1->t; // tu dois définir w dans ton t_coord !

	for (i = 0; i < 4; i++)
	{
		out[i] = 0;
		for (j = 0; j < 4; j++)
			out[i] += m_a[i * 4 + j] * in[j];
	}
	fill_point_vector(res, 0, out[0]);
	fill_point_vector(res, 1, out[1]);
	fill_point_vector(res, 2, out[2]);
	res->t = in[3]; // garde le w original

	return (res);
}*/

/*
t_coord	*matrix_multiplication_44_coord(float *m_a, t_coord *p_v_1)
{
	t_coord	*new_point_vector;
	float	coord[4];
	float	sum;
	int		count;

	if (check_matrix_44_coord(m_a, p_v_1) == false)
	{
		printf("mistake here \n");
		return (NULL);
	}	
	new_point_vector = malloc(sizeof(t_coord));
	if (!new_point_vector)
		return (NULL);
	count = 0;
	matrix_from_coord(p_v_1, coord);
	while (count < 4)
	{
		sum = 0;
		sum += m_a[count * 4 + 0] * coord[0];
		sum += m_a[count * 4 + 1] * coord[1];
		sum += m_a[count * 4 + 2] * coord[2];
		sum += m_a[count * 4 + 3] * coord[3];
		fill_point_vector(new_point_vector, count, sum);
		count++;
	}
//	printf("ok done \n");
	return (new_point_vector);
}*/


//ORIGINAL
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
/*
t_coord	*matrix_multiplication_44_coord(float *m_a, t_coord *p_v_1)
{
	t_coord	*new_point_vector;
	float	coord[4];
	float	sum;
	int		count;

	if (check_matrix_44_coord(m_a, p_v_1) == false)
	{
		printf("mistake here \n");
		return (NULL);
	}	
	new_point_vector = malloc(sizeof(t_coord));
	if (!new_point_vector)
		return (NULL);
	count = 0;
	matrix_from_coord(p_v_1, coord);
	while (count < 4)
	{
		sum = 0;
		sum += m_a[2 + count * 4 + 0] * coord[0];
		sum += m_a[2 + count * 4 + 1] * coord[1];
		sum += m_a[2 + count * 4 + 2] * coord[2];
		sum += m_a[2 + count * 4 + 3] * coord[3];
		fill_point_vector(new_point_vector, count, sum);
		count++;
	}
	new_point_vector->t = p_v_1->t;
//	fill_point_vector()
//	printf("ok done \n");
	return (new_point_vector);
}*/

/*
t_coord	*matrix_multiplication_44_point(float *m_a, t_coord *p_v_1)
{
	t_coord	*new_point_vector;
	float	coord[4];
	float	sum;
	int		count;

	if (check_matrix_44_coord(m_a, p_v_1) == false)
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

		sum += m_a[2 + count * 4] * coord[0];
		sum += m_a[2 + count * 4 + 1] * coord[1];
		sum += m_a[2 + count * 4 + 2] * coord[2];
		sum += m_a[2 + count * 4 + 3] * coord[3];
		fill_point_vector(new_point_vector, count, sum);
		count++;
	}
//	printf("ok done \n");
	return (new_point_vector);
}*/



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



