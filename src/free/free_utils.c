/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:34:56 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/19 16:39:52 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
** Libère une structure t_image.
*/
void	free_image(t_image *ima)
{
	if (!ima)
		return ;
	free(ima);
}

/*
** Libère une structure t_comps et tous ses champs dynamiquement alloués.
*/
void	free_comps(t_comps *comps)
{
	if (!comps)
		return ;
	free(comps->p_touch);
	free(comps->v_eye);
	free(comps->v_norm_parral);
	if (comps->r_ray)
	{
		free(comps->r_ray->p_origin);
		free(comps->r_ray->v_dir);
		free(comps->r_ray);
	}
	free(comps);
}

void	free_all(t_pix ***pix, int x, int y, t_num_obj *num_obj)
{
	free_pix(pix, x, y, num_obj);
	free(num_obj);
}
