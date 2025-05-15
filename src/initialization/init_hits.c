/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:46:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/15 15:10:52 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_hits	***init_hits(t_num_obj *num_obj)
{
	t_hits	***hits;

	hits = NULL;
	hits = malloc(5 * sizeof(t_hits **));
	if (!hits)
		return (NULL);
	if (!allocate_hits_arrays(hits, num_obj))
		return (NULL);
	initialize_hits_arrays(hits, num_obj);
	return (hits);
}

void	assign_hits_to_pix(t_pix ***pix, t_num_obj *num_obj)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_WIDTH)
	{
		j = 0;
		while (j < WND_HEIGHT)
		{
			pix[i][j]->hits = init_hits(num_obj);
			if (!pix[i][j]->hits)
				return;
            
			// Allocation de la structure comps
			pix[i][j]->comps = malloc(sizeof(t_comps));
			if (!pix[i][j]->comps)
				return;

			// Initialisation des champs de base
			pix[i][j]->comps->closestt = INT_MAX;
			pix[i][j]->comps->t_count = 0;
			pix[i][j]->comps->obj = pix[i][j]->obj[0][0];
			pix[i][j]->comps->type = NONE;

			// Allocation des vecteurs et matrices
			pix[i][j]->comps->r_dir = malloc(sizeof(t_coord));
			pix[i][j]->comps->r_origin = malloc(sizeof(t_coord));
			pix[i][j]->comps->p_touch = malloc(sizeof(t_coord));
			pix[i][j]->comps->v_eye = malloc(sizeof(t_coord));
			pix[i][j]->comps->v_norm_parral = malloc(sizeof(t_coord));
			pix[i][j]->comps->obj_color = malloc(sizeof(t_color));
			
			// Vérification des allocations de base
			if (!pix[i][j]->comps->r_dir || !pix[i][j]->comps->r_origin || 
				!pix[i][j]->comps->p_touch || !pix[i][j]->comps->v_eye || 
				!pix[i][j]->comps->v_norm_parral || !pix[i][j]->comps->obj_color)
			{
				// Nettoyage en cas d'erreur
				if (pix[i][j]->comps->r_dir)
					free(pix[i][j]->comps->r_dir);
				if (pix[i][j]->comps->r_origin)
					free(pix[i][j]->comps->r_origin);
				if (pix[i][j]->comps->p_touch)
					free(pix[i][j]->comps->p_touch);
				if (pix[i][j]->comps->v_eye)
					free(pix[i][j]->comps->v_eye);
				if (pix[i][j]->comps->v_norm_parral)
					free(pix[i][j]->comps->v_norm_parral);
				if (pix[i][j]->comps->obj_color)
					free(pix[i][j]->comps->obj_color);
				free(pix[i][j]->comps);
				return;
			}

			// Création des vecteurs et matrices supplémentaires
			pix[i][j]->comps->v_light_to_point = create_vector(0, 0, 0);
			pix[i][j]->comps->v_sphere_to_point = create_vector(0, 0, 0);
			pix[i][j]->comps->reflect_dir = create_vector(0, 0, 0);
			pix[i][j]->comps->scalar = create_vector(0, 0, 0);
			pix[i][j]->comps->view_dir = create_vector(0, 0, 0);
			pix[i][j]->comps->p_space = create_point(0, 0, 0);
			pix[i][j]->comps->origin_zero = create_point(0, 0, 0);
			pix[i][j]->comps->object_normal = create_vector(0, 0, 0);
			pix[i][j]->comps->transp_inv = create_matrix(4, 4);
			pix[i][j]->comps->obj_inv = create_matrix(4, 4);
			pix[i][j]->comps->v_point_to_light = create_point(0, 0, 0);

			// Vérification des créations
			if (!pix[i][j]->comps->v_light_to_point || !pix[i][j]->comps->v_sphere_to_point ||
				!pix[i][j]->comps->reflect_dir || !pix[i][j]->comps->scalar ||
				!pix[i][j]->comps->view_dir || !pix[i][j]->comps->p_space ||
				!pix[i][j]->comps->origin_zero || !pix[i][j]->comps->object_normal ||
				!pix[i][j]->comps->transp_inv || !pix[i][j]->comps->obj_inv ||
				!pix[i][j]->comps->v_point_to_light)
			{
				// Le nettoyage sera géré par free_comps en cas d'erreur
				free_comps(pix[i][j]->comps);
				pix[i][j]->comps = NULL;
				return;
			}
			j++;
		}
		i++;
	}
}
