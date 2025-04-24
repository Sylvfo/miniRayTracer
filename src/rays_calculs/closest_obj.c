/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:48:36 by syl               #+#    #+#             */
/*   Updated: 2025/04/24 17:50:26 by syl              ###   ########.fr       */
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
			y++;
		}
		x++;
	}
}

void copy_hits_to_comps(t_comps *comps, t_hits *hits)
{
	comps->closestt = hits->t1;
	copy_coord(comps->r_dir, hits->r_dir);
	copy_coord(comps->r_origin, hits->r_origin);
	comps->obj_type = hits->obj_type;
}

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
			else if (pix->hits[a][b]->t2 < pix->comps->closestt &&  pix->hits[a][b]->t2 > 0)// && pix->hits[x][y]->t2 > pix->hits[x][y]->t1)/// ou plus grand que zero...
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
	pix->comps->t_count = 1;
	pix->comps->obj = pix->obj[a][b];
	copy_coord(pix->comps->r_dir, pix->hits[a][b]->r_dir);
	copy_coord(pix->comps->r_origin, pix->hits[a][b]->r_origin);
	pix->comps->obj_type = pix->hits[a][b]->obj_type;
	copy_color(pix->comps->obj_color, pix->obj[a][b]->color);
	copy_coord(pix->comps->p_world, pix->obj[a][b]->p_world);
	copy_matrix_44_stack(pix->obj[a][b]->m_inv, pix->comps->obj_inv);
}


/*
void closest_obj(t_pix *pix)
{
	int	a;
	int	b;

	a = 1;
	while (a < 4)//pix->hits[a] != NULL
	{
		b = 0;
		while (pix->hits[a][b] != NULL)
		{
			if (pix->hits[a][b]->t1 < pix->comps->closestt && pix->hits[a][b]->t1 > 0)
			{
				pix->comps->closestt = pix->hits[a][b]->t1;
				pix->comps->obj = pix->obj[a][b];
				copy_coord(pix->comps->r_dir, pix->hits[a][b]->r_dir);
				copy_coord(pix->comps->r_origin, pix->hits[a][b]->r_origin);
				pix->comps->t_count = 1;
				pix->comps->obj_type = pix->hits[a][b]->obj_type;
				copy_color(pix->comps->obj_color, pix->obj[a][b]->color);
			}
			//rajouter si t2 est plus petit que t1?
			else if (pix->hits[a][b]->t2 < pix->comps->closestt &&  pix->hits[a][b]->t2 > 0)// && pix->hits[x][y]->t2 > pix->hits[x][y]->t1)/// ou plus grand que zero...
			{
				pix->comps->closestt = pix->hits[a][b]->t2;
				pix->comps->obj = pix->obj[a][b];
				copy_coord(pix->comps->r_dir, pix->hits[a][b]->r_dir);
				copy_coord(pix->comps->r_origin, pix->hits[a][b]->r_origin);
				pix->comps->t_count = 1;
				pix->comps->obj_type = pix->hits[a][b]->obj_type;
				copy_color(pix->comps->obj_color, pix->obj[a][b]->color);
			}
			b++;
		}
		a++;
	}
}*/

