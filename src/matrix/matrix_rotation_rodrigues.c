/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation_rodrigues.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:01:11 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 17:15:20 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void rotation_from_vector_NA(t_obj *obj)
{
	float dot;
	float angle;

	if (!obj || !obj->from || !obj->v_axe || !obj->v_axe_r || !obj->m_rot) {
		fprintf(stderr, "Error: Null pointer in rotation_from_vector_NA\n");
		return;
	}
	cross_product_NA(obj->v_axe_r, obj->from, obj->v_axe);
	dot = dot_product(obj->from, obj->v_axe);
	dot = fmaxf(-1.0f, fminf(1.0f, dot));
	angle = acosf(dot);
	if (fabs(angle) < EPSILON)
		return;
	normalize_vector_NA(obj->v_axe_r);
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