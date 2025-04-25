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

//new one
/// CELLE CI POUR UNE MATRIX ET UN POINT
//void	matrix_multiplication_44_coord_NA(t_coord *new_point_vector, float *m_a, t_coord *p_v_1)
void	matrix_point_multiplication_new(t_coord *result, float *m, t_coord *p)
{
//	if (is_point(p) == false)
//		printf("laaaaalaaaaa\n");
	if (check_matrix_44(m) == false )
		printf("UUUUUUUUUUUUUUUUUU\n");
	if (check_matrix_44_coord(m, p) == false)
	{
		printf("no point or matrix in new mult\n");
		exit(0) ;
	}
	
	if (!result)
	{
		printf("no result in new mult\n");
		exit(0) ;
	}
	result->x = m[2] * p->x + m[3] * p->y + m[4] * p->z + m[5] * p->t;
	result->y = m[6] * p->x + m[7] * p->y + m[8] * p->z + m[9] * p->t;
	result->z = m[10] * p->x + m[11] * p->y + m[12] * p->z + m[13] * p->t;
	//result->t = m[14] * p->x + m[15] * p->y + m[16] * p->z + m[17] * p->t;
	result->t = p->t;
}

void matrix_mult_2(float *ma, float *mb)
{
	float tmp[18];
	int i;

	if (!ma || !mb)
	{
		printf("problem in matrix mult 2");
		return;
	}
	i = 0;
	while(i < 18)
	{
		tmp[i] = ma[i];
		i++;
	}
	ma[2] = tmp[2] * mb[2] + tmp[3] * mb[6] + tmp[4] * mb[10] + tmp[5] * mb[14];
	ma[3] = tmp[2] * mb[3] + tmp[3] * mb[7] + tmp[4] * mb[11] + tmp[5] * mb[15];
	ma[4] = tmp[2] * mb[4] + tmp[3] * mb[8] + tmp[4] * mb[12] + tmp[5] * mb[16];
	ma[5] = tmp[2] * mb[5] + tmp[3] * mb[9] + tmp[4] * mb[13] + tmp[5] * mb[17];

	ma[6] = tmp[6] * mb[2] + tmp[7] * mb[6] + tmp[8] * mb[10] + tmp[9] * mb[14];
	ma[7] = tmp[6] * mb[3] + tmp[7] * mb[7] + tmp[8] * mb[11] + tmp[9] * mb[15];
	ma[8] = tmp[6] * mb[4] + tmp[7] * mb[8] + tmp[8] * mb[12] + tmp[9] * mb[16];
	ma[9] = tmp[6] * mb[5] + tmp[7] * mb[9] + tmp[8] * mb[13] + tmp[9] * mb[17];

	ma[10] = tmp[10] * mb[2] + tmp[11] * mb[6] + tmp[12] * mb[10] + tmp[13] * mb[14];
	ma[11] = tmp[10] * mb[3] + tmp[11] * mb[7] + tmp[12] * mb[11] + tmp[13] * mb[15];
	ma[12] = tmp[10] * mb[4] + tmp[11] * mb[8] + tmp[12] * mb[12] + tmp[13] * mb[16];
	ma[13] = tmp[10] * mb[5] + tmp[11] * mb[9] + tmp[12] * mb[13] + tmp[13] * mb[17];

	ma[14] = tmp[14] * mb[2] + tmp[15] * mb[6] + tmp[16] * mb[10] + tmp[17] * mb[14];
	ma[15] = tmp[14] * mb[3] + tmp[15] * mb[7] + tmp[16] * mb[11] + tmp[17] * mb[15];
	ma[16] = tmp[14] * mb[4] + tmp[15] * mb[8] + tmp[16] * mb[12] + tmp[17] * mb[16];
	ma[17] = tmp[14] * mb[5] + tmp[15] * mb[9] + tmp[16] * mb[13] + tmp[17] * mb[17];	
}

void matrix_mult_3(float *result, float *ma, float *mb)
{
	if (!result || !ma || !mb)
	{
		printf("problem in matrix mult 3");
		return;
	}
	result[2] = ma[2] * mb[2] + ma[3] * mb[6] + ma[4] * mb[10] + ma[5] * mb[14];
	result[3] = ma[2] * mb[3] + ma[3] * mb[7] + ma[4] * mb[11] + ma[5] * mb[15];
	result[4] = ma[2] * mb[4] + ma[3] * mb[8] + ma[4] * mb[12] + ma[5] * mb[16];
	result[5] = ma[2] * mb[5] + ma[3] * mb[9] + ma[4] * mb[13] + ma[5] * mb[17];

	result[6] = ma[6] * mb[2] + ma[7] * mb[6] + ma[8] * mb[10] + ma[9] * mb[14];
	result[7] = ma[6] * mb[3] + ma[7] * mb[7] + ma[8] * mb[11] + ma[9] * mb[15];
	result[8] = ma[6] * mb[4] + ma[7] * mb[8] + ma[8] * mb[12] + ma[9] * mb[16];
	result[9] = ma[6] * mb[5] + ma[7] * mb[9] + ma[8] * mb[13] + ma[9] * mb[17];

	result[10] = ma[10] * mb[2] + ma[11] * mb[6] + ma[12] * mb[10] + ma[13] * mb[14];
	result[11] = ma[10] * mb[3] + ma[11] * mb[7] + ma[12] * mb[11] + ma[13] * mb[15];
	result[12] = ma[10] * mb[4] + ma[11] * mb[8] + ma[12] * mb[12] + ma[13] * mb[16];
	result[13] = ma[10] * mb[5] + ma[11] * mb[9] + ma[12] * mb[13] + ma[13] * mb[17];

	result[14] = ma[14] * mb[2] + ma[15] * mb[6] + ma[16] * mb[10] + ma[17] * mb[14];
	result[15] = ma[14] * mb[3] + ma[15] * mb[7] + ma[16] * mb[11] + ma[17] * mb[15];
	result[16] = ma[14] * mb[4] + ma[15] * mb[8] + ma[16] * mb[12] + ma[17] * mb[16];
	result[17] = ma[14] * mb[5] + ma[15] * mb[9] + ma[16] * mb[13] + ma[17] * mb[17];
}


/*
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
}*/

/*
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
}*/

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
