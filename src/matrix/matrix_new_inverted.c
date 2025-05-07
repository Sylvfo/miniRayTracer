/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_new_inverted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:33:03 by syl               #+#    #+#             */
/*   Updated: 2025/04/28 13:50:41 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


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
static float determinant4x4(float *m) {
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
}


/*
#include <stdio.h>

//DEEPSEEK
// Function to calculate the determinant of a 4x4 matrix
float determinant4x4(float mat[4][4]) {
    float det = 0;
    float submat[3][3];
    int n = 4;
    
    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        
        // Calculate determinant of 3x3 submatrix
        float subdet = submat[0][0] * (submat[1][1] * submat[2][2] - submat[2][1] * submat[1][2])
                     - submat[0][1] * (submat[1][0] * submat[2][2] - submat[2][0] * submat[1][2])
                     + submat[0][2] * (submat[1][0] * submat[2][1] - submat[2][0] * submat[1][1]);
        
        det += (x % 2 == 0 ? 1 : -1) * mat[0][x] * subdet;
    }
    
    return det;
}

// Function to calculate the inverse of a 4x4 matrix
int inverse4x4(float mat[4][4], float inv[4][4]) {
    float det = determinant4x4(mat);
    
    if (det == 0) {
        printf("Matrix is singular, cannot find inverse.\n");
        return 0;
    }
    
    float inv_det = 1.0f / det;
    float temp[4][4];
    
    // Calculate adjugate matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // Create 3x3 submatrix by removing row i and column j
            float submat[3][3];
            int subi = 0;
            for (int k = 0; k < 4; k++) {
                if (k == i) continue;
                int subj = 0;
                for (int l = 0; l < 4; l++) {
                    if (l == j) continue;
                    submat[subi][subj] = mat[k][l];
                    subj++;
                }
                subi++;
            }
            
            // Calculate determinant of 3x3 submatrix
            float subdet = submat[0][0] * (submat[1][1] * submat[2][2] - submat[2][1] * submat[1][2])
                         - submat[0][1] * (submat[1][0] * submat[2][2] - submat[2][0] * submat[1][2])
                         + submat[0][2] * (submat[1][0] * submat[2][1] - submat[2][0] * submat[1][1]);
            
            // Apply cofactor sign and transpose (adjugate)
            temp[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * subdet * inv_det;
        }
    }
    
    // Copy temp to inv
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            inv[i][j] = temp[i][j];
        }
    }
    
    return 1;
}
*/