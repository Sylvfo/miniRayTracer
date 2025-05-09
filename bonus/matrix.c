/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:23:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 15:33:07 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
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
}*/

/*
//on laisse au cas où
t_coord *matrix_multiplication_44_point(float *m_, t_coord *p)
{
	t_coord *new_point = malloc(sizeof(t_coord));
//	float *m = m_ + 2; // on saute les infos taille

	if (!new_point)
		return (NULL);
	int i = 2;
	new_point->x = m_[i+0] * p->x + m_[i+1] * p->y + m_[i+2] * p->z + m_[i+3];
	new_point->y = m_[i+4] * p->x + m_[i+5] * p->y + m_[i+6] * p->z + m_[i+7];
	new_point->z = m_[i+8] * p->x + m_[i+9] * p->y + m_[i+10]* p->z + m_[i+11];
		
//	new_point->x = m_[2] * p->x + m_[6] * p->y + m_[10] * p->z + m_[14];  // Colonne 0
//	new_point->y = m_[3] * p->x + m_[7] * p->y + m_[11] * p->z + m_[15];  // Colonne 1
//	new_point->z = m_[4] * p->x + m_[8] * p->y + m_[12] * p->z + m_[16]; // Colonne 2
	new_point->t = 1.0f;
	return (new_point);
}*/

/*
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
}*/


/*
//a voir après
void	matrix_division_44(float *m_matrix, float div)
{
	int	i;

	if (!m_matrix)
	{
		printf("no matrix\n");
		return ;
	}
	if (div == 0)
	{
		printf("devide by 0 in matrix_division\n");
		return ;
	}
	i = 2;
	div = (1 / div);
	while (i < (m_matrix[0] * m_matrix[1]) + 2)
	{
		m_matrix[i] *= div;
		i++;
	}
}*/