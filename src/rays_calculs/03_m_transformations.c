/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_m_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 11:48:48 by syl              ###   ########.fr       */
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
//	struct timeval	start;

//	gettimeofday(&start, NULL);
	int	a;
	int	b;

	a = 1;
	while (obj[a] != NULL)
	{
		b = 0;
		while (obj[a][b] != NULL)
		{
		//	if (a == 3 && b == 2)
		//		start = time_now(start, " in set");
			translation_matrix_coord(obj[a][b]);
			matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_transl);
			//if (a == 3 && b == 2)
		//		start = time_now(start, " transl");
			if (obj[a][b]->type == PLAN || obj[a][b]->type == CYLINDER)
			{
				rotation_from_vector_NA(obj[a][b]);
				matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_rot);
			//	if (a == 2 && b == 2)
			//		start = time_now(start, " rot");
			}
			if (obj[a][b]->type == SPHERE || obj[a][b]->type == CYLINDER)
			{
				scaling_matrix_coord(obj[a][b]);
				matrix_mult_2(obj[a][b]->m_transf, obj[a][b]->m_scale);
			//	if (a == 3 && b == 2)
			//		start = time_now(start, " scal");
			}
			inverse4x4(obj[a][b]->m_transf, obj[a][b]->m_inv);
		//	if (a == 3 && b == 2)
		//			start = time_now(start, " inv");
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
