/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:48:36 by syl               #+#    #+#             */
/*   Updated: 2025/03/14 14:30:08 by syl              ###   ########.fr       */
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
			pix[x][y]->color = pix[x][y]->comps->obj->color;
			y++;
		}
		x++;
	}	
}

void closest_obj(t_pix *pix)
{
	float closestt = INT_MAX;
	int	x;
	int	y;
	
	pix->comps->obj = pix->obj[0][0];
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (pix->hits[x][y] != NULL)
		{
			if (pix->hits[x][y]->t1 < closestt && pix->hits[x][y]->t1 > 0)/// ou plus grand que zero...
			{
				pix->comps->closestt = pix->hits[x][y]->t1;
				pix->comps->obj = pix->obj[x][y];
			}
			if (pix->hits[x][y]->t2 < closestt &&  pix->hits[x][y]->t2 > 0)/// ou plus grand que zero...
			{
				pix->comps->closestt = pix->hits[x][y]->t2;
				pix->comps->obj = pix->obj[x][y];
			}
			y++;
		}
		x++;
	}
}

//trier les objets dans l ordre... a la plac de find closest. 
void prepare_computation(t_pix ***pix)
{
	int	x;
	int	y;
	t_coord *v_test;
	t_coord *v_test2;

	v_test = create_vector(0,1,2);
	v_test2 = create_vector(0,1,2);

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->comps->p_point = position(pix[x][y]->r_ray, pix[x][y]->comps->closestt);
			pix[x][y]->comps->v_eye = negat(pix[x][y]->r_ray->v_dir);
/*			pix[x][y]->comps->v_norm_parral = normal_at(pix[x][y]->comps->obj, pix[x][y]->comps->p_point);
			if (dot_product(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->v_eye) < 0)
			{
				if (y < 2)
					printf("a");
				pix[x][y]->comps->inside = true;
				pix[x][y]->comps->v_norm_parral = negat(pix[x][y]->comps->v_norm_parral);
			}
			else
				pix[x][y]->comps->inside = false;*/
			y++;
		}
		x++;
	}
}
