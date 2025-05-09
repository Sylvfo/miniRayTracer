/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_m_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 17:04:22 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//effacer les mesures du temps
#include <sys/time.h>

void	matrix_transformations(t_pix ***pix)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	set_transformation(pix[0][0]->obj);
	start = time_now(start, " after set transf");
	apply_transformation(pix);
	start = time_now(start, " after apply");
}

void	set_transformation(t_obj ***obj)
{
	int	a;
	int	b;

	a = 1;
	while (obj[a] != NULL)
	{
		b = 0;
		while (obj[a][b] != NULL)
		{
			set_transformation_obj(obj[a][b]);
			b++;
		}
		a++;
	}
}

void	set_transformation_obj(t_obj *obj)
{
	translation_matrix_coord(obj);
	matrix_mult_2(obj->m_transf, obj->m_transl);
	if (obj->type == PLAN || obj->type == CYLINDER)
	{
		rotation_from_vector(obj);
		matrix_mult_2(obj->m_transf, obj->m_rot);
	}
	if (obj->type == SPHERE || obj->type == CYLINDER)
	{
		scaling_matrix_coord(obj);
		matrix_mult_2(obj->m_transf, obj->m_scale);
	}
	inverse_matrix_44(obj->m_inv, obj->m_transf);
}

void	apply_transformation(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			apply_transformation_obj(pix[x][y]);
			y++;
		}
		x++;
	}
}

void	apply_transformation_obj(t_pix *pix)
{
	int	a;
	int	b;

	a = 1;
	while (pix->obj[a] != NULL)
	{
		b = 0;
		while (pix->obj[a][b] != NULL)
		{
			matrix_point_multiplication_new(pix->hits[a][b]->r_origin,
				pix->obj[a][b]->m_inv, pix->r_origin);
			matrix_point_multiplication_new(pix->hits[a][b]->r_dir,
				pix->obj[a][b]->m_inv, pix->r_dir);
			b++;
		}
		a++;
	}
}
