/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:34:39 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/19 16:34:46 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
** Libère une structure t_camera et tous ses champs dynamiquement alloués.
*/
void	free_camera(t_camera *cam)
{
	if (!cam)
		return ;
	free(cam->p_coord);
	free(cam->v_axe);
	free(cam->m_transf);
	free(cam->m_inverse);
	free(cam->p_origin_zero);
	if (cam->saved_camera)
		free_camera(cam->saved_camera);
	free(cam);
}
