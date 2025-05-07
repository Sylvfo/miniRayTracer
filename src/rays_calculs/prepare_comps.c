/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_comps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:25 by syl               #+#    #+#             */
/*   Updated: 2025/05/06 15:59:14 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// prepare p_touch, normal_at and v_eye
void prepare_computation(t_pix ***pix)
{
	int x;
	int y;

	// a effacer
	struct timeval start;
	gettimeofday(&start, NULL);
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
	/*		if (x == 12 && y == 12)
				start = time_now(start, " start");*/
			if (pix[x][y]->comps->obj_type != NONE)
				position_NA(pix[x][y], pix[x][y]->comps->r_dir, pix[x][y]->comps->closestt);
			// Calculer le vecteur œil : inverse de la direction du rayon
			negat_NA(pix[x][y]->comps->v_eye, pix[x][y]->comps->r_dir);
			// Calculer la normale au point d'intersection
			if (pix[x][y]->comps->obj_type == SPHERE)
			{
				normal_at_NA(pix[x][y]->comps);
				if (dot_product(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->v_eye) < 0)
				{
					pix[x][y]->comps->inside = true;
					negat_NA(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->v_norm_parral);
				}
			}
			if (pix[x][y]->comps->obj_type == CYLINDER)
			{
			/*	if (pix[x][y]->comps->t_count == 8)
					normal_caps(pix[x][y]->comps);
				else*/
				normal_at_NA(pix[x][y]->comps);
			}
			// normal at plan c est pareil que l axe donné au début
			else if (pix[x][y]->comps->obj_type == PLAN)
				copy_coord(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->obj->v_axe);		
			y++;
		}
		x++;
	}
}
