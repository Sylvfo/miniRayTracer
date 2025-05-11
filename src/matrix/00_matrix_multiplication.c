/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:42:19 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 16:24:06 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	matrix_point_multiplication_new(t_coord *result, float *m, t_coord *p)
{
	float	x;
	float	y;
	float	z;
	float	t;

	x = p->x;
	y = p->y;
	z = p->z;
	t = p->t;
	result->x = m[2] * x + m[3] * y + m[4] * z + m[5] * t;
	result->y = m[6] * x + m[7] * y + m[8] * z + m[9] * t;
	result->z = m[10] * x + m[11] * y + m[12] * z + m[13] * t;
	result->t = t;
}

void	matrix_mult_2(float *ma, float *mb)
{
	float	tmp[18];
	int		i;

	if (!ma || !mb)
	{
		printf("problem in matrix mult 2");
		return ;
	}
	i = 2;
	copy_matrix_44(tmp, ma);
	while (i < 18)
	{
		ma[0 + i] = tmp[i] * mb[2] + tmp[i + 1] * mb[6]
			+ tmp[i + 2] * mb[10] + tmp[i + 3] * mb[14];
		ma[1 + i] = tmp[i] * mb[3] + tmp[i + 1] * mb[7]
			+ tmp[i + 2] * mb[11] + tmp[i + 3] * mb[15];
		ma[2 + i] = tmp[i] * mb[4] + tmp[i + 1] * mb[8]
			+ tmp[i + 2] * mb[12] + tmp[i + 3] * mb[16];
		ma[3 + i] = tmp[i] * mb[5] + tmp[i + 1] * mb[9]
			+ tmp[i + 2] * mb[13] + tmp[i + 3] * mb[17];
		i += 4;
	}
}

void	matrix_mult_3(float *res, float *ma, float *mb)
{
	int	i;

	i = 2;
	if (!res || !ma || !mb)
	{
		printf("problem in matrix mult 3");
		return ;
	}
	while (i < 18)
	{
		res[0 + i] = ma[i] * mb[2] + ma[i + 1] * mb[6]
			+ ma[i + 2] * mb[10] + ma[i + 3] * mb[14];
		res[1 + i] = ma[i] * mb[3] + ma[i + 1] * mb[7]
			+ ma[i + 2] * mb[11] + ma[i + 3] * mb[15];
		res[2 + i] = ma[i] * mb[4] + ma[i + 1] * mb[8]
			+ ma[i + 2] * mb[12] + ma[i + 3] * mb[16];
		res[3 + i] = ma[i] * mb[5] + ma[i + 1] * mb[9]
			+ ma[i + 2] * mb[13] + ma[i + 3] * mb[17];
		i += 4;
	}
}
