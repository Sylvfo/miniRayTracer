/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_rotation_rodrigues.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:01:11 by syl               #+#    #+#             */
/*   Updated: 2025/05/11 17:51:02 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	rotation_from_vector(t_obj *obj)
{
	float	dot;
	float	angle;
	float	c;
	float	s;

	if (!obj || !obj->from || !obj->v_axe || !obj->v_axe_r || !obj->m_rot)
	{
		fprintf(stderr, "Error: Null pointer in rotation_from_vector\n");
		return ;
	}
	cross_product_na(obj->v_axe_r, obj->from, obj->v_axe);
	dot = dot_product(obj->from, obj->v_axe);
	dot = fmaxf(-1.0f, fminf(1.0f, dot));
	angle = acosf(dot);
	if (fabs(angle) < EPSILON)
		return ;
	normalize_vector_na(obj->v_axe_r);
	c = cos(angle);
	s = sin(angle);
	matrix_rotation_rodrigues(obj, angle, c, s);
}

void	matrix_rotation_rodrigues(t_obj *obj, float angle, float c, float s)
{
	float	t;
	float	axe_x;
	float	axe_y;
	float	axe_z;

	axe_x = obj->v_axe_r->x;
	axe_y = obj->v_axe_r->y;
	axe_z = obj->v_axe_r->z;
	t = 1 - c;
	matrix_fill(obj->m_rot, 0, 0, (c + t * axe_x * axe_x));
	matrix_fill(obj->m_rot, 0, 1, t * axe_x * axe_y - s * axe_z);
	matrix_fill(obj->m_rot, 0, 2, t * axe_x * axe_z + s * axe_y);
	matrix_fill(obj->m_rot, 0, 3, 0);
	matrix_fill(obj->m_rot, 1, 0, t * axe_x * axe_y + s * axe_z);
	matrix_fill(obj->m_rot, 1, 1, t * axe_y * axe_y + c);
	matrix_fill(obj->m_rot, 1, 2, t * axe_y * axe_z - s * axe_x);
	matrix_fill(obj->m_rot, 1, 3, 0);
	matrix_fill(obj->m_rot, 2, 0, t * axe_x * axe_z - s * axe_y);
	matrix_fill(obj->m_rot, 2, 1, t * axe_y * axe_z + s * axe_x);
	matrix_fill(obj->m_rot, 2, 2, t * axe_z * axe_z + c);
	matrix_fill(obj->m_rot, 2, 3, 0);
	matrix_fill(obj->m_rot, 3, 0, 0);
	matrix_fill(obj->m_rot, 3, 1, 0);
	matrix_fill(obj->m_rot, 3, 2, 0);
	matrix_fill(obj->m_rot, 3, 3, 1);
}
