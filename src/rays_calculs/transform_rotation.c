/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:37:38 by syl               #+#    #+#             */
/*   Updated: 2025/04/30 16:51:38 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//obj[x][y]->m_rot = create_rotation_from_vector(obj[x][y]->v_axe);
/* A EFFACER
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
}*/


void rotation_from_vector_NA(t_obj *obj)
{
    // Validate input
    if (!obj || !obj->from || !obj->v_axe || !obj->v_axe_r || !obj->m_rot) {
        fprintf(stderr, "Error: Null pointer in rotation_from_vector_NA\n");
        return;
    }

    // Initialize rotation matrix to identity by default
 //   set_identity_matrix(obj->m_rot);

    // Get rotation axis via cross product
    cross_product_NA(obj->v_axe_r, obj->from, obj->v_axe);
    
    // Calculate angle between vectors
    float dot = dot_product(obj->from, obj->v_axe);
    
    // Clamp dot product to avoid numerical instability in acos()
    dot = fmaxf(-1.0f, fminf(1.0f, dot));
    float angle = acosf(dot);

    // Skip if angle is too small
    if (fabs(angle) < EPSILON) {
        return;
    }

    // Normalize rotation axis
    if (!normalize_vector(obj->v_axe_r)) {
        fprintf(stderr, "Warning: Failed to normalize rotation axis\n");
        return;
    }

    // Create rotation matrix using Rodrigues' formula
    matrix_rotation_rodrigues(obj, angle);
}

/*
//v_axe_r
//void rotation_from_vector_NA(float *m_rot, t_coord *to, t_obj *obj)
void rotation_from_vector_NA(t_obj *obj)
{
    float 	angle;
	float 	dot;

    init_matrix_zero(obj->m_rot);
    // Produit vectoriel pour obtenir l'axe de rotation
//	obj->v_axe_r = cross_product(obj->from, to);
	cross_product_NA(obj->v_axe_r, obj->from, obj->v_axe);
	dot = dot_product(obj->from, obj->v_axe);// Produit scalaire pour obtenir l'angle
    angle = acos(dot); // angle en radians
    if (fabs(angle) < EPSILON)
		return; // Pas besoin de rotation. ce sera identity matrix...
	normalize_vector(obj->v_axe_r);
	matrix_rotation_rodrigues(obj, angle);
}*/


void matrix_rotation_rodrigues(t_obj *obj, float angle)
{
	float c;
	float s;
	float t;

	c = cos(angle);
    s = sin(angle);
    t = 1 - c;

	//obj->m_rot = create_matrix(4, 4);
    // Matrice 3x3 de rotation de Rodrigues + extension en 4x4
	matrix_fill(obj->m_rot, 0, 0, (c + t*obj->v_axe_r->x*obj->v_axe_r->x));
    matrix_fill(obj->m_rot, 0, 1, t*obj->v_axe_r->x*obj->v_axe_r->y - s*obj->v_axe_r->z);
    matrix_fill(obj->m_rot, 0, 2, t*obj->v_axe_r->x*obj->v_axe_r->z + s*obj->v_axe_r->y);
    matrix_fill(obj->m_rot, 0, 3, 0);
    matrix_fill(obj->m_rot, 1, 0, t*obj->v_axe_r->x*obj->v_axe_r->y + s*obj->v_axe_r->z);
    matrix_fill(obj->m_rot, 1, 1, t*obj->v_axe_r->y*obj->v_axe_r->y + c);
    matrix_fill(obj->m_rot, 1, 2, t*obj->v_axe_r->y*obj->v_axe_r->z - s*obj->v_axe_r->x);
    matrix_fill(obj->m_rot, 1, 3, 0);
    matrix_fill(obj->m_rot, 2, 0, t*obj->v_axe_r->x*obj->v_axe_r->z - s*obj->v_axe_r->y);
    matrix_fill(obj->m_rot, 2, 1, t*obj->v_axe_r->y*obj->v_axe_r->z + s*obj->v_axe_r->x);
    matrix_fill(obj->m_rot, 2, 2, t*obj->v_axe_r->z*obj->v_axe_r->z + c);
    matrix_fill(obj->m_rot, 2, 3, 0);
    matrix_fill(obj->m_rot, 3, 0, 0);
    matrix_fill(obj->m_rot, 3, 1, 0);
    matrix_fill(obj->m_rot, 3, 2, 0);
    matrix_fill(obj->m_rot, 3, 3, 1);
}

/*
void matrix_rotation_rodrigues(t_obj *obj, float angle)
{
    // Validate input
    if (!obj || !obj->v_axe_r || !obj->m_rot) {
        fprintf(stderr, "Error: Null pointer in matrix_rotation_rodrigues\n");
        return;
    }

    float c = cosf(angle);
    float s = sinf(angle);
    float t = 1.0f - c;

    float x = obj->v_axe_r->x;
    float y = obj->v_axe_r->y;
    float z = obj->v_axe_r->z;

    // Precompute common terms
    float xx = x * x;
    float yy = y * y;
    float zz = z * z;
    float xy = x * y;
    float xz = x * z;
    float yz = y * z;
    float xs = x * s;
    float ys = y * s;
    float zs = z * s;

    // Initialize matrix to zero first
    init_matrix_zero(obj->m_rot);

    // Fill rotation matrix using matrix_fill (Row-major order)
    matrix_fill(obj->m_rot, 0, 0, t*xx + c);
    matrix_fill(obj->m_rot, 0, 1, t*xy - zs);
    matrix_fill(obj->m_rot, 0, 2, t*xz + ys);
    matrix_fill(obj->m_rot, 0, 3, 0.0f);

    matrix_fill(obj->m_rot, 1, 0, t*xy + zs);
    matrix_fill(obj->m_rot, 1, 1, t*yy + c);
    matrix_fill(obj->m_rot, 1, 2, t*yz - xs);
    matrix_fill(obj->m_rot, 1, 3, 0.0f);

    matrix_fill(obj->m_rot, 2, 0, t*xz - ys);
    matrix_fill(obj->m_rot, 2, 1, t*yz + xs);
    matrix_fill(obj->m_rot, 2, 2, t*zz + c);
    matrix_fill(obj->m_rot, 2, 3, 0.0f);

    matrix_fill(obj->m_rot, 3, 0, 0.0f);
    matrix_fill(obj->m_rot, 3, 1, 0.0f);
    matrix_fill(obj->m_rot, 3, 2, 0.0f);
    matrix_fill(obj->m_rot, 3, 3, 1.0f);
}*/

/*
void rotation_from_vector_NA(float *m_rot, t_coord *to, t_obj *obj)
{
    float 	angle;
	float 	dot;

    // Produit vectoriel pour obtenir l'axe de rotation
	obj->axis = cross_product(obj->from, to);
	dot = dot_product(obj->from, to);// Produit scalaire pour obtenir l'angle
    angle = acos(dot); // angle en radians
    if (fabs(angle) < EPSILON)
		return; // Pas besoin de rotation. ce sera identity matrix...
	obj->axis = normalize_vector(obj->axis);
//	matrix_rotation_rodrigues(obj->axis, angle, m_rot);
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
	matrix_fill(m_rot, 0, 0, (c + t*axis->x*axis->x));
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


*/