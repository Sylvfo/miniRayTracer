/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:37:38 by syl               #+#    #+#             */
/*   Updated: 2025/05/06 10:58:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void rotation_from_vector_NA(t_obj *obj)
{
    float dot;

    // Validate input
    if (!obj || !obj->from || !obj->v_axe || !obj->v_axe_r || !obj->m_rot) {
        fprintf(stderr, "Error: Null pointer in rotation_from_vector_NA\n");
        return;
    }
    // Produit vectoriel pour obtenir l'axe de rotation
    cross_product_NA(obj->v_axe_r, obj->from, obj->v_axe);
    // Calculate angle between vectors
    dot = dot_product(obj->from, obj->v_axe);
    
    // Clamp dot product to avoid numerical instability in acos()
    dot = fmaxf(-1.0f, fminf(1.0f, dot));
    float angle = acosf(dot);

    // Skip if angle is too small
    if (fabs(angle) < EPSILON)
        return;
    normalize_vector(obj->v_axe_r);
    // Create rotation matrix using Rodrigues' formula
    matrix_rotation_rodrigues(obj, angle);
}

void matrix_rotation_rodrigues(t_obj *obj, float angle)
{
	float c;
	float s;
	float t;

	c = cos(angle);
    s = sin(angle);
    t = 1 - c;
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
