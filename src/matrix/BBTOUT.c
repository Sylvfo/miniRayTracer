/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BBTOUT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:46:07 by syl               #+#    #+#             */
/*   Updated: 2025/04/24 11:54:07 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../inc/minirt.h"

//	row = m_matrix[0];
//	col = m_matrix[1];
float	*create_matrix(unsigned int row, unsigned int col)
{
	float	*m_matrix;

	m_matrix = malloc((row * col + 2) * sizeof(float));
	if (!m_matrix)
	{
		printf("problem allocation memory matrix\n");
		return (NULL);
	}
	m_matrix[0] = (float)row;
	m_matrix[1] = (float)col;
	init_matrix_zero(m_matrix);
	return (m_matrix);
}

void	init_matrix_zero(float *m_matrix)
{
	int	i;

	i = ((int)(m_matrix[0] * m_matrix[1]) + 1);
	while (i > 1)
	{
		m_matrix[i] = 0.0;
		i--;
	}
}

void	matrix_fill(float *m_matrix, int row, int col, float number)
{
	int	i;

	if (!m_matrix)
	{
		printf("No matrix in fill");
		return ;
	}
	if (row < 0 || row > ((int)m_matrix[0] -1))
	{
		printf("Wrong number of row. \n");
		return ;
	}
	if (col < 0 || col > ((int)m_matrix[1] - 1))
	{
		printf("Wrong number of column\n");
		return ;
	}
	i = row * (int)m_matrix[1] + col + 2;
	m_matrix[i] = number;
}

float	*create_indentity_matrix_44(void)
{
	float	*m_identity;

	m_identity = create_matrix(4, 4);
	matrix_fill(m_identity, 0, 0, 1);
	matrix_fill(m_identity, 1, 1, 1);
	matrix_fill(m_identity, 2, 2, 1);
	matrix_fill(m_identity, 3, 3, 1);
	return (m_identity);
}


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

bool	check_matrix_44_coord(float *m_a, t_coord *p_v_1)
{
	if (!m_a)
	{
		printf("Matrix is missing S\n");
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
	int i = 2;
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

void	matrix_division(float *m_matrix, float div)
{
	int	i;

	if (!m_matrix)
	{
		printf("no matrix\n");
		return ;
	}
	i = 2;
	div = (1 / div);
	while (i < (m_matrix[0] * m_matrix[1]) + 2)
	{
		m_matrix[i] *= div;
		i++;
	}
}


// celle de corentin
// À ajouter dans votre bibliothèque de matrices
float *transpose_matrix(float *m)
{
	float *result;
	int i;
	int j;
	
	if (!m || m[0] != 4 || m[1] != 4)
		return (NULL);
	
	result = create_matrix(4, 4);
	if (!result)
		return (NULL);
	
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix_fill(result, i, j, m[2 + j * 4 + i]);
			j++;
		}
		i++;
	}
	return (result);
}

//celle de syl
void	transposing_matrix_44(float *m_matrix)
{
	float	m_tmp[18];
	int		i;
	int		j;

	check_matrix_44(m_matrix);
	copy_matrix_44_stack(m_matrix, m_tmp);
	i = 2;
	j = 2;
	while (i < 18)
	{
		m_matrix[i] = m_tmp[j];
		if (j > 13)
			j -= 11;
		else
			j += 4;
		i++;
	}
}
//heap
void	copy_matrix_44_stack(float *m_matrix, float *m_tmp)
{
	int	i;

	i = 0;
	while (i < 18)
	{
		m_tmp[i] = m_matrix[i];
		i++;
	}
}*/
