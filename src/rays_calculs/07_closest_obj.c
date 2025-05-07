/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_closest_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:48:36 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 11:11:00 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// POUR REFLEXION ET REFRACTION FAIRE DES ARRAYS....
void find_closest_obj(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			closest_obj(pix[x][y]);
		/*	if (pix[x][y]->comps->closestt < 2147483648.00)
				printf("closestt %.2f \n", pix[x][y]->comps->closestt);*/
			y++;
		}
		x++;
	}
}

/*
void copy_hits_to_comps(t_comps *comps, t_hits *hits)
{
	comps->closestt = hits->t1;
	copy_coord(comps->r_dir, hits->r_dir);
	copy_coord(comps->r_origin, hits->r_origin);
	comps->obj_type = hits->obj_type;
}*/

void closest_obj(t_pix *pix)
{
	int	a;
	int	b;

	a = 1;
	while (pix->hits[a] != NULL)
	{
		b = 0;
		while (pix->hits[a][b] != NULL)
		{
			if (pix->hits[a][b]->t1 < pix->comps->closestt && pix->hits[a][b]->t1 > 0)
			{
				pix->comps->closestt = pix->hits[a][b]->t1;
				save_in_comps(pix, a, b);
			}
			//rajouter si t2 est plus petit que t1?
			else if (pix->hits[a][b]->t2 < pix->comps->closestt && pix->hits[a][b]->t2 > 0)// && pix->hits[a][b]->t2 > pix->hits[a][b]->t1)
			{
				pix->comps->closestt = pix->hits[a][b]->t2;
				save_in_comps(pix, a, b);
			}
			b++;
		}
		a++;
	}
}

void save_in_comps(t_pix *pix, int a, int b)
{
	pix->comps->t_count = pix->hits[a][b]->t_count;
	pix->comps->obj = pix->obj[a][b];
	copy_coord(pix->comps->r_dir, pix->hits[a][b]->r_dir);
	copy_coord(pix->comps->r_origin, pix->hits[a][b]->r_origin);
	pix->comps->obj_type = pix->hits[a][b]->obj_type;
	copy_color(pix->comps->obj_color, pix->obj[a][b]->color);
	copy_matrix_44(pix->comps->obj_inv, pix->obj[a][b]->m_inv);
	if (pix->hits[a][b]->obj_type == CYLINDER)
		pix->comps->height = pix->obj[a][b]->height;
	if (pix->hits[a][b]->obj_type == PLAN)
	copy_coord(pix->comps->v_norm_parral, pix->obj[a][b]->v_axe);
//	copy_matrix_44(pix->obj[a][b]->m_inv, pix->comps->obj_inv);
//	copy_matrix_44(pix->obj[a][b]->m_transl, pix->comps->m_transl);
	//print_vector(pix->comps->r_dir);
}
