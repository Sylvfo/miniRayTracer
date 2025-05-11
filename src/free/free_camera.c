/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:34:39 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 15:27:56 by cmegret          ###   ########.fr       */
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
	free(cam->p_zero);
	free(cam->v_up);
	free(cam->v_left);
	free(cam->v_true_up);
	free(cam->m_orient);
	free(cam->m_transl);
	free(cam->m_transf);
	free(cam->m_inverse);
	free(cam);
}
