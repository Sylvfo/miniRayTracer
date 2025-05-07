/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_m_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 11:28:21 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void matrix_transformations(t_pix ***pix)
{
	set_transformation(pix[0][0]->obj);
	apply_transformation(pix);
}

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
			fill_translation_matrix(obj[a][b]->m_transl, obj[a][b]->p_coord->x, obj[a][b]->p_coord->y, obj[a][b]->p_coord->z);
			matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_transl);
			if (obj[a][b]->obj_type == PLAN || obj[a][b]->obj_type == CYLINDER)
			{
				rotation_from_vector_NA(obj[a][b]);
				matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_rot);
			}
			if (obj[a][b]->obj_type == SPHERE || obj[a][b]->obj_type == CYLINDER)
			{
				create_scaling_matrix_NA(obj[a][b]->m_scale, obj[a][b]->diam, obj[a][b]->diam, obj[a][b]->diam);
				matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_scale);
			}
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
