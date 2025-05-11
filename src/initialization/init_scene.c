/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:16:29 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 17:22:16 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/initialization.h"

bool	init_scene_structures(t_pix ***pix)
{
	init_pix_camera(pix);
	init_pix_viewport(pix);
	if (!init_obj_matrices(pix[0][0]->obj))
	{
		printf("probleme alloc obj \n");
		return (false);
	}
	if (!init_hits_matrices(pix[0][0]->hits))
	{
		printf("probleme alloc hits \n");
		return (false);
	}
	init_pix_comps(pix);
	return (true);
}
