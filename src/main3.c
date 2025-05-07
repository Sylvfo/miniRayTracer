/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:05:22 by syl               #+#    #+#             */
/*   Updated: 2025/04/27 15:06:24 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "./inc/minirt.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>
#include <math.h>

#define IDX(i,j) (2 + (i) * 4 + (j))

// Fonctions de test que j'ajoute (petites seulement)

void test_apply_matrix_to_point(float *m, float x, float y, float z)
{
    float res_x, res_y, res_z, res_w;

    res_x = x * m[IDX(0,0)] + y * m[IDX(1,0)] + z * m[IDX(2,0)] + 1.0f * m[IDX(3,0)];
    res_y = x * m[IDX(0,1)] + y * m[IDX(1,1)] + z * m[IDX(2,1)] + 1.0f * m[IDX(3,1)];
    res_z = x * m[IDX(0,2)] + y * m[IDX(1,2)] + z * m[IDX(2,2)] + 1.0f * m[IDX(3,2)];
    res_w = x * m[IDX(0,3)] + y * m[IDX(1,3)] + z * m[IDX(2,3)] + 1.0f * m[IDX(3,3)];

    if (res_w != 0.0f && res_w != 1.0f)
    {
        res_x /= res_w;
        res_y /= res_w;
        res_z /= res_w;
    }

    printf("Point (%f, %f, %f) devient (%f, %f, %f)\n", x, y, z, res_x, res_y, res_z);
}

void test_apply_matrix_to_vector(float *m, float x, float y, float z)
{
    float res_x, res_y, res_z;

    res_x = x * m[IDX(0,0)] + y * m[IDX(1,0)] + z * m[IDX(2,0)];
    res_y = x * m[IDX(0,1)] + y * m[IDX(1,1)] + z * m[IDX(2,1)];
    res_z = x * m[IDX(0,2)] + y * m[IDX(1,2)] + z * m[IDX(2,2)];

    printf("Vecteur (%f, %f, %f) devient (%f, %f, %f)\n", x, y, z, res_x, res_y, res_z);
}

void test_print_matrix(float *m)
{
    printf("Matrix %dx%d\n", (int)m[0], (int)m[1]);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            printf("%8.3f ", m[IDX(i,j)]);
        printf("\n");
    }
}

// ==== Ton main de test ====

int main(void)
{
    printf("==== Tests Matrices avec TES fonctions ====\n");

    float *m_transf = create_indentity_matrix_44();
    float *m_scale = create_matrix(4, 4);
    float *m_rot = create_matrix(4, 4);
    float *m_transl = create_matrix(4, 4);

    // 1. Identité
	//m_transf = create_indentity_matrix_44();
 //   init_matrix_identity(m_transf);

    // 2. Scaling
    create_scaling_matrix_NA(m_scale, 2.0f, 3.0f, 4.0f);
    matrix_mult_2(m_transf, m_scale);

    // 3. Rotation
   // create_rotation_z_matrix_NA(m_rot, M_PI / 2.0f); // Tu dois avoir une fonction rotation autour Z
   // matrix_mult_2(m_transf, m_rot);

    // 4. Translation
    fill_translation_matrix(m_transl, 10.0f, 0.0f, 5.0f);
    matrix_mult_2(m_transf, m_transl);

    // 5. Affichage
    printf("\nMatrice Finale :\n");
    test_print_matrix(m_transf);

    printf("\nTest Application Point :\n");
    test_apply_matrix_to_point(m_transf, 1.0f, 0.0f, 0.0f);

    printf("\nTest Application Vecteur :\n");
    test_apply_matrix_to_vector(m_transf, 1.0f, 0.0f, 0.0f);

    free(m_transf);
    free(m_scale);
    free(m_rot);
    free(m_transl);

    printf("\n==== Fin des tests ====\n");
    return 0;
}*/
