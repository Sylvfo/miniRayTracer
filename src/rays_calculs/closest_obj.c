/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:48:36 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 15:26:30 by syl              ###   ########.fr       */
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
			// Copier la couleur au lieu de réassigner le pointeur :
		/*	pix[x][y]->color->r = pix[x][y]->comps->obj->color->r;
			pix[x][y]->color->g = pix[x][y]->comps->obj->color->g;
			pix[x][y]->color->b = pix[x][y]->comps->obj->color->b;
			pix[x][y]->color->rgb = pix[x][y]->comps->obj->color->rgb;*/
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

/*
void closest_obj(t_pix *pix)
{
	int	a;
	int	b;

	//a mettre dans init
	pix->comps->closestt = INT_MAX;
	pix->comps->r_dir = malloc(sizeof(t_coord));
	pix->comps->r_origin = malloc(sizeof(t_coord));
	
	a = 1;
	while (a < 4) //ICI CHANGER POUR PLUS DE FORMES!!!!
	{
		b = 0;
		while (pix->hits[a][b] != NULL)
		{
			if (pix->hits[a][b]->t1 < pix->comps->closestt && pix->hits[a][b]->t1 > 0)/// ou plus grand que zero...
			{
				pix->comps->closestt = pix->hits[a][b]->t1;
				pix->comps->obj = pix->obj[a][b];
				copy_coord(pix->comps->r_dir, pix->hits[a][b]->r_dir);
				copy_coord(pix->comps->r_origin, pix->hits[a][b]->r_origin);
				pix->comps->t_count = 1;
				pix->comps->obj_type = pix->hits[a][b]->obj_type;
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
			}
			else // si rien touche...
			{
				copy_coord(pix->comps->r_dir, pix->r_dir);
				copy_coord(pix->comps->r_origin, pix->r_origin);
				pix->comps->t_count = 0;
				pix->comps->obj = pix->obj[0][0];
				pix->comps->obj_type = NONE;
			}
			b++;
		}
		a++;
	}
}*/


void closest_obj(t_pix *pix)
{
	int	a;
	int	b;

	//a mettre dans init
	pix->comps->closestt = INT_MAX;
	pix->comps->r_dir = malloc(sizeof(t_coord));
	pix->comps->r_origin = malloc(sizeof(t_coord));
	
	copy_coord(pix->comps->r_dir, pix->r_dir);
	copy_coord(pix->comps->r_origin, pix->r_origin);
	pix->comps->t_count = 0;
	pix->comps->obj = pix->obj[0][0];
	pix->comps->obj_type = NONE;

	a = 1;
	while (a < 4) //ICI CHANGER POUR PLUS DE FORMES!!!!
	{
		b = 0;
		while (pix->hits[a][b] != NULL)
		{
			if (pix->hits[a][b]->t1 < pix->comps->closestt && pix->hits[a][b]->t1 > 0)/// ou plus grand que zero...
			{
				pix->comps->closestt = pix->hits[a][b]->t1;
				pix->comps->obj = pix->obj[a][b];
				copy_coord(pix->comps->r_dir, pix->hits[a][b]->r_dir);
				copy_coord(pix->comps->r_origin, pix->hits[a][b]->r_origin);
				pix->comps->t_count = 1;
				pix->comps->obj_type = pix->hits[a][b]->obj_type;
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
			}
/*			else // si rien touche...
			{
				copy_coord(pix->comps->r_dir, pix->r_dir);
				copy_coord(pix->comps->r_origin, pix->r_origin);
				pix->comps->t_count = 0;
				pix->comps->obj = pix->obj[0][0];
				pix->comps->obj_type = NONE;
			}*/
			b++;
		}
		a++;
	}
}
