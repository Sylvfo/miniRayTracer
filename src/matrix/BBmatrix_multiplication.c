/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BBmatrix_multiplication.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:42:19 by syl               #+#    #+#             */
/*   Updated: 2025/04/24 18:41:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Multiplying a matrix by a tuple produces another tuple
// On calcule seulement 4 valeurs (x,y,z,t)
void	matrix_multiplication_44_coord_NA(t_coord *new_point_vector, float *m_a, t_coord *p_v_1)
{
	float	coord[4];
	float	sum;
	int		count;

	if (check_matrix_44_coord(m_a, p_v_1) == false)
		return ;
	count = 0;
	matrix_from_coord(p_v_1, coord);
	while (count < 3)
	{
		sum = 0;
		sum += m_a[2 + count * 4] * coord[0];
		sum += m_a[2 + count * 4 + 1] * coord[1];
		sum += m_a[2 + count * 4 + 2] * coord[2];
		sum += m_a[2 + count * 4 + 3] * coord[3];
		fill_point_vector(new_point_vector, count, sum);
		count++;
	}
	new_point_vector->t = p_v_1->t;
}

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

// Don’t worry about 2x2 or 3x3 matrices here; your ray tracer won’t
//need to multiply those at all
//Matrix multiplication computes the dot product of every row-column
//combination in the two matrices!

/*
void matrix_multiplication_44_NA2(float *out, float *a, float *b) {
    if (!check_matrix_44(a) || !check_matrix_44(b)) return;

    // Ligne 0
    out[2]  = a[2]*b[2]  + a[6]*b[3]  + a[10]*b[4]  + a[14]*b[5];
    out[6]  = a[2]*b[6]  + a[6]*b[7]  + a[10]*b[8]  + a[14]*b[9];
    out[10] = a[2]*b[10] + a[6]*b[11] + a[10]*b[12] + a[14]*b[13];
    out[14] = a[2]*b[14] + a[6]*b[15] + a[10]*b[16] + a[14]*b[17];
    // Lignes 1 à 3 similaires...
}*/

/* gpt
void	matrix_mult_44_new_NA2(float *m_result, float *m_a, float *m_b)
{
	int		row;
	int		col;
	int		i;
	float	sum;

	// Sécurité : matrices doivent être 4x4
	if (!m_result || !m_a || !m_b
		|| m_a[0] != 4 || m_a[1] != 4
		|| m_b[0] != 4 || m_b[1] != 4)
	{
		printf("Erreur : matrices non valides\n");
		return;
	}

	// Dimensions de la matrice résultat
	m_result[0] = 4;
	m_result[1] = 4;

	// Multiplication ligne × colonne
	for (row = 0; row < 4; row++)
	{
		for (col = 0; col < 4; col++)
		{
			sum = 0;
			for (i = 0; i < 4; i++)
			{
				sum += m_a[2 + row * 4 + i] * m_b[2 + i * 4 + col];
			}
			m_result[2 + row * 4 + col] = sum;
		}
	}
}*/

/*
gpt
void	matrix_multi_44_ret_NA(float *m_a, float *m_b, float *m_tmp)
{
	int	row, col, i;
	float	sum;

	if (!m_a || !m_b || !m_tmp
		|| m_a[0] != 4 || m_a[1] != 4
		|| m_b[0] != 4 || m_b[1] != 4)
	{
		printf("Erreur : matrices non valides\n");
		return;
	}
	// Calcule le produit m_a × m_b dans m_tmp
	m_tmp[0] = 4;
	m_tmp[1] = 4;

	for (row = 0; row < 4; row++)
	{
		for (col = 0; col < 4; col++)
		{
			sum = 0;
			for (i = 0; i < 4; i++)
			{
				sum += m_a[2 + row * 4 + i] * m_b[2 + i * 4 + col];
			}
			m_tmp[2 + row * 4 + col] = sum;
		}
	}
	// Copie le résultat final dans m_a
	copy_matrix_44_stack(m_tmp, m_a);
}*/


//celui ci pour une nouvelle matrice
//void	matrix_multiplication_44_NA2(float *m_result, float *m_a, float *m_b)
void	matrix_mult_44_new_NA2(float *m_result, float *m_a, float *m_b)
{
	int		count;
	float	sum;
	int		row;
	int		col;
	

	if (check_matrix_44(m_result) == false)
	{
		printf("miss in 44 NA\n");
		return;
	}
	if (check_matrix_44_44(m_a, m_b) == false)
	{
		printf("miss in 44 NA 2\n");
		return;
	}
	count = 0;
	while (count < 16)
	{
		row = count / 4;
		col = count % 4;
		sum = 0;
		sum += m_a[2 + row * 4 + 0] * m_b[2 + 0 * 4 + col];
		sum += m_a[2 + row * 4 + 1] * m_b[2 + 1 * 4 + col];
		sum += m_a[2 + row * 4 + 2] * m_b[2 + 2 * 4 + col];
		sum += m_a[2 + row * 4 + 3] * m_b[2 + 3 * 4 + col];
		m_result[2 + count] = sum;
		count++;
	}
	m_result[0] = 4;
	m_result[1] = 4;
}

//celui ci pour une nouvelle matrice
void	matrix_multiplication_44_NA2(float *m_result, float *m_a, float *m_b)
{
	int		count;
	float	sum;
	int		row;
	int		col;
	

	if (check_matrix_44(m_result) == false)
	{
		printf("miss in 44 NA\n");
		return;
	}
	if (check_matrix_44_44(m_a, m_b) == false)
	{
		printf("miss in 44 NA 2\n");
		return;
	}
	count = 0;
	while (count < 16)
	{
		row = count / 4;
		col = count % 4;
		sum = 0;
		sum += m_a[2 + row * 4 + 0] * m_b[2 + 0 * 4 + col];
		sum += m_a[2 + row * 4 + 1] * m_b[2 + 1 * 4 + col];
		sum += m_a[2 + row * 4 + 2] * m_b[2 + 2 * 4 + col];
		sum += m_a[2 + row * 4 + 3] * m_b[2 + 3 * 4 + col];
		m_result[2 + count] = sum;
		count++;
	}
	m_result[0] = 4;
	m_result[1] = 4;
}


//celui ci pour une matric ma qui devient m result
//void	matrix_multi_44_ret_NA(float *m_a, float *m_b, float *m_tmp)
void	matrix_multiplication_44_NA(float *m_a, float *m_b, float *m_tmp)
{
	int		count;
	float	sum;
	int		row;
	int		col;
	
	if (check_matrix_44_44(m_a, m_b) == false)
	{
		printf("miss in 44 NA 2\n");
		return;
	}
	if (check_matrix_44(m_tmp) == false)
	{
		printf("miss in 44 NA 3\n");
		return;
	}
	count = 0;
	//copy_matrix_44_stack(m_a, m_tmp);
	while (count < 16)
	{
		row = count / 4;
		col = count % 4;
		sum = 0;
		sum += m_a[2 + row * 4 + 0] * m_b[2 + 0 * 4 + col];
		sum += m_a[2 + row * 4 + 1] * m_b[2 + 1 * 4 + col];
		sum += m_a[2 + row * 4 + 2] * m_b[2 + 2 * 4 + col];
		sum += m_a[2 + row * 4 + 3] * m_b[2 + 3 * 4 + col];
		m_tmp[2 + count] = sum;
		count++;
	}
	copy_matrix_44_stack(m_tmp, m_a);
	m_a[0] = 4;
	m_a[1] = 4;
}

/*
void	matrix_multiplication_44_NA(float *m_a, float *m_b, float *m_tmp)
{
	int		row, col, i;
	float	sum;

	if (!m_a || !m_b || !m_tmp || m_a[0] != 4 || m_b[0] != 4)
	{
		printf("Erreur : matrices invalides\n");
		return;
	}

	for (row = 0; row < 4; row++)
	{
		for (col = 0; col < 4; col++)
		{
			sum = 0;
			for (i = 0; i < 4; i++)
			{
				sum += m_a[2 + row * 4 + i] * m_b[2 + i * 4 + col];
			}
			m_tmp[2 + row * 4 + col] = sum;
		}
	}

	// copie le résultat final dans m_a
	copy_matrix_44_stack(m_tmp, m_a);
	m_a[0] = 4;
	m_a[1] = 4;
}*/


//celui ci pour une matric ma qui devient m result
//void	matrix_multiplication_44_NA(float *m_a, float *m_b, float *m_tmp)
void	matrix_multi_44_ret_NA(float *m_a, float *m_b, float *m_tmp)
{
	int		count;
	float	sum;
	int		row;
	int		col;
	
	if (check_matrix_44_44(m_a, m_b) == false)
	{
		printf("miss in 44 NA 2\n");
		return;
	}
	if (check_matrix_44(m_tmp) == false)
	{
		printf("miss in 44 NA 3\n");
		return;
	}
	count = 0;
	copy_matrix_44_stack(m_a, m_tmp);
	while (count < 16)
	{
		row = count / 4;
		col = count % 4;
		sum = 0;
		sum += m_a[2 + row * 4 + 0] * m_b[2 + 0 * 4 + col];
		sum += m_a[2 + row * 4 + 1] * m_b[2 + 1 * 4 + col];
		sum += m_a[2 + row * 4 + 2] * m_b[2 + 2 * 4 + col];
		sum += m_a[2 + row * 4 + 3] * m_b[2 + 3 * 4 + col];
		m_tmp[2 + count] = sum;
		count++;
	}
	copy_matrix_44_stack(m_tmp, m_a);
}
