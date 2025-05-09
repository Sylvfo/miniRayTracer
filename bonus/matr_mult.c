/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matr_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:24:16 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 16:24:29 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//AVANT NORME

void	matrix_mult_2(float *ma, float *mb)
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