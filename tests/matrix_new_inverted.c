/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_new_inverted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:33:03 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 16:06:49 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
/*
#define IDX(i, j) (2 + (i) * 4 + (j))

// Calcule le déterminant d'une matrice 3x3
static float determinant3x3(float *m) {
    return 
		m[0] * (m[4] * m[8] - m[5] * m[7]) -
		m[1] * (m[3] * m[8] - m[5] * m[6]) +
		m[2] * (m[3] * m[7] - m[4] * m[6]);
}

// Extrait une sous-matrice 3x3 en supprimant ligne row et colonne col
static void get_submatrix3x3(float *src, float *dest, int row, int col) {
	int di = 0;
	for (int i = 0; i < 4; ++i) {
		if (i == row) continue;
		int dj = 0;
		for (int j = 0; j < 4; ++j) {
			if (j == col) continue;
			dest[di * 3 + dj] = src[IDX(i, j)];
			dj++;
		}
		di++;
	}
}

// Calcule le déterminant d'une matrice 4x4
static float determinant4x4(float *m)
{
	float det = 0.0f;
	float subm[9];
	int sign = 1;
	for (int col = 0; col < 4; ++col) {
		get_submatrix3x3(m, subm, 0, col);
		det += sign * m[IDX(0, col)] * determinant3x3(subm);
		sign = -sign;
	}
    return det;
}


// Inverse une matrice 4x4
int inverse4x4(float *src, float *dest)
{
	float det = determinant4x4(src);
	if (det == 0.0f)
		return 0; // matrice non inversible

    // initialiser taille
	dest[0] = 4;
	dest[1] = 4;

	float subm[9];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			get_submatrix3x3(src, subm, i, j);
			float cofactor = determinant3x3(subm);
			if ((i + j) % 2)
				cofactor = -cofactor;
			dest[IDX(j, i)] = cofactor / det; // attention, on transpose (j, i)
		}
	}
	return 1; // succès
}*/
