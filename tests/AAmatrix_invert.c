/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAmatrix_invert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:18:41 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 17:04:45 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//It’ll be crucial to the transforma-
//tion of shapes in your ray tracer, allowing you to move shapes around, make
//them bigger or smaller, rotate them, and more.
//not every matrix is invertible
//pas testé
bool	is_matrix_invertible(float *m_matrix)
{
	float	determinant;

	if (check_matrix_22(m_matrix) == true)
		determinant = determinant_22(m_matrix);
	else if (check_matrix_33(m_matrix) == true)
		determinant = determinant_33(m_matrix);
	else if (check_matrix_44(m_matrix) == true)
		determinant = determinant_44(m_matrix);
	else
		return (false);
	if (determinant == 0)
		return (false);
	return (true);
}



// a supprimer quand toutes matrices allouees
//float	*inverted_matrix_44(float *m_matrix)
/*
//int inverse4x4(float *m_matrix, float	*m_inverted)
void	inverse_matrix_44(float *m_inverted, float *m_matrix)
{
	float	determinant;

	printf("in inverted\n");
	if (check_matrix_44(m_matrix) == false)
	{
		printf("aa\n");
		return (0);
	}
	if (is_matrix_invertible(m_matrix) == false)
	{
		printf("bb\n");
		return (0);
	}
	
	if (!m_inverted)
	{
		printf("problem in inverted \n");
		return (0);
	}	
	m_inverted = create_matrix(4, 4);
	matrix_cofactors_44(m_matrix, m_inverted);
	transposing_matrix_44(m_inverted);
	determinant = determinant_44(m_matrix);
	printf("det %.2f \n", determinant);
	matrix_division(m_inverted, determinant);
}*/

/*
bool	is_matrix_invertible_44_NA(float *m_matrix)
{
	float	determinant;

	determinant = determinant_44(m_matrix);
	else
		return (false);
	if (determinant == 0)
		return (false);
	return (true);
}*/



//float	*submatrix_44NA(float *m_matrix, float *m_submatrix, int row_to_rm, int col_to_rm);

void	matrix_cofactors_44NA(float *m_matrix, float *m_cofactors)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 2;
	j = 0;
	k = 0;
	l = 6;
	while (i < 18)
	{
		if (i >= l)
		{
			j++;
			k = 0;
			l += 4;
		}
		m_cofactors[i] = minor_44(m_matrix, j, k);
		k++;
		i++;
	}
}

void	matrix_cofactors_44(float *m_matrix, float *m_cofactors)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 2;
	j = 0;
	k = 0;
	l = 6;
	while (i < 18)
	{
		if (i >= l)
		{
			j++;
			k = 0;
			l += 4;
		}
		m_cofactors[i] = minor_44(m_matrix, j, k);
		k++;
		i++;
	}
}


/*
float	*inverted_matrix_44(float *m_matrix)
{
	float	*m_inverted;
	float	determinant;

	printf("in inverted\n");
	if (check_matrix_44(m_matrix) == false)
	{
		printf("aa\n");
		return (NULL);
	}
	if (is_matrix_invertible(m_matrix) == false)
	{
		printf("bb\n");
		return (NULL);
	}
	
	if (!m_inverted)
	{
		printf("problem in inverted \n");
		return (NULL);
	}	
	m_inverted = create_matrix(4, 4);
	matrix_cofactors_44(m_matrix, m_inverted);
	transposing_matrix_44(m_inverted);
	determinant = determinant_44(m_matrix);
	printf("det %.2f \n", determinant);
	matrix_division(m_inverted, determinant);
	return (m_inverted);
}
*/