/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:37:38 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 11:37:04 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//obj[x][y]->m_rot = create_rotation_from_vector(obj[x][y]->v_axe);

void rotation_from_vector(float *m_rot, t_coord *to)
{
    t_coord *axis;
    float 	angle;
	t_coord *from;
	float 	dot;

	from = create_vector(0, 1, 0);
	axis = malloc(sizeof(t_coord));
    // Produit vectoriel pour obtenir l'axe de rotation
	axis = cross_product(from, to);
	dot = dot_product(from, to);// Produit scalaire pour obtenir l'angle
    angle = acos(dot); // angle en radians
    if (fabs(angle) < EPSILON)
		return; // Pas besoin de rotation. ce sera identity matrix...
	axis = normalize_vector(axis);
	matrix_rotation_rodrigues(axis, angle, m_rot);
	free(axis);
	free(from);
}


void matrix_rotation_rodrigues(t_coord *axis, float angle, float *m_rot)
{
	float c;
	float s;
	float t;

	c = cos(angle);
    s = sin(angle);
    t = 1 - c;
    // Matrice 3x3 de rotation de Rodrigues + extension en 4x4
	matrix_fill(m_rot, 0, 0, t*axis->x*axis->x + c);
    matrix_fill(m_rot, 0, 1, t*axis->x*axis->y - s*axis->z);
    matrix_fill(m_rot, 0, 2, t*axis->x*axis->z + s*axis->y);
    matrix_fill(m_rot, 0, 3, 0);
    matrix_fill(m_rot, 1, 0, t*axis->x*axis->y + s*axis->z);
    matrix_fill(m_rot, 1, 1, t*axis->y*axis->y + c);
    matrix_fill(m_rot, 1, 2, t*axis->y*axis->z - s*axis->x);
    matrix_fill(m_rot, 1, 3, 0);
    matrix_fill(m_rot, 2, 0, t*axis->x*axis->z - s*axis->y);
    matrix_fill(m_rot, 2, 1, t*axis->y*axis->z + s*axis->x);
    matrix_fill(m_rot, 2, 2, t*axis->z*axis->z + c);
    matrix_fill(m_rot, 2, 3, 0);
    matrix_fill(m_rot, 3, 0, 0);
    matrix_fill(m_rot, 3, 1, 0);
    matrix_fill(m_rot, 3, 2, 0);
    matrix_fill(m_rot, 3, 3, 1);
}
