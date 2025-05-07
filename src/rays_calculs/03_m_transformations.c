/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_m_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 10:48:14 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void matrix_transformations(t_pix ***pix)
{
	set_transformation(pix[0][0]->obj);
	apply_transformation(pix);
}

//rotation // scaling // translation
void set_transformation(t_obj ***obj)
{
    int a;
    int b;

	a = 1;
    while(obj[a] != NULL)
    {
        b = 0;
        while(obj[a][b] != NULL)
        {
			// Apply translation
			fill_translation_matrix(obj[a][b]->m_transl, 
									obj[a][b]->p_coord->x, 
									obj[a][b]->p_coord->y, 
									obj[a][b]->p_coord->z);
			matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_transl);
			// Rotation
			if (obj[a][b]->obj_type == PLAN || obj[a][b]->obj_type == CYLINDER)
			{
				rotation_from_vector_NA(obj[a][b]);
				matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_rot);
			}
			if (obj[a][b]->obj_type == SPHERE || obj[a][b]->obj_type == CYLINDER)
			{
				create_scaling_matrix_NA(obj[a][b]->m_scale, 
										obj[a][b]->diam, 
										obj[a][b]->diam, 
										obj[a][b]->diam);
				matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_scale);
			}
			// Calculate inverse transformation
			inverse4x4(obj[a][b]->m_transf, obj[a][b]->m_inv);
            b++;
        }
        a++;
    }
}

void apply_transformation(t_pix ***pix)
{
	int	x;
	int	y;
	int a;
	int b;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			a = 1;
			while (pix[x][y]->obj[a] != NULL)
			{
				b = 0;
				while(pix[x][y]->obj[a][b] != NULL)
				{
					matrix_point_multiplication_new(pix[x][y]->hits[a][b]->r_origin, pix[x][y]->obj[a][b]->m_inv, pix[x][y]->r_origin);
					matrix_point_multiplication_new(pix[x][y]->hits[a][b]->r_dir, pix[x][y]->obj[a][b]->m_inv, pix[x][y]->r_dir);
					b++;
				}
				a++;
			}
			y++;
		}
		x++;
	}
}

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
